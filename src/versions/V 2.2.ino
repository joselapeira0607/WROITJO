#include <Servo.h>

// --- Configuración de pines ---
const int motorPin1 = 3;      // Control dirección motor (HIGH/LOW)
const int motorPin2 = 6;      // Control dirección motor (HIGH/LOW)
const int servoPin = 9;       // Pin para control del servo
const int trigPin = 4;        // Pin Trigger del sensor ultrasónico
const int echoPin = 5;        // Pin Echo del sensor ultrasónico

// --- Parámetros del servo ---
const int ANGULO_CENTRO = 90;
const int ANGULO_MAX_DERECHA = 120;
const int ANGULO_MAX_IZQUIERDA = 60;

// --- Umbrales y constantes ---
const int UMBRAL_DIFERENCIA = 30;    // mm para considerar recto
const int MAX_DIFERENCIA = 160;      // mm diferencia máxima esperada (NUEVA CONSTANTE AÑADIDA)
const int DISTANCIA_GIRO = 20;       // cm para activar giro
const int TIMEOUT_SENSORES = 1000;   // ms sin datos antes de detenerse

// --- Control de vueltas ---
const int GIROS_POR_VUELTA = 4;
const int MAX_VUELTAS = 3;

// --- Variables del sistema ---
Servo myServo;
String receivedData = "";
bool newData = false;
int valorSensor1 = 0;
int valorSensor2 = 0;
unsigned long lastSensorUpdate = 0;
float distanciaFrontal = 0;

// --- Estado del vehículo ---
int girosDetectados = 0;
int vueltasCompletadas = 0;
bool estaGirando = false;
bool vehiculoDetenido = false;
bool paredCercana = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino: Sistema iniciado. Esperando datos...");

  // Configuración pines motor
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Configuración servo
  myServo.attach(servoPin);
  centrarServo();

  // Configuración sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// ================= FUNCIONES PRINCIPALES =================

void avanzar() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void detener() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  centrarServo();
}

float medirDistancia() {
  // Limpia el trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Envía pulso de 10μs
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Mide el tiempo de respuesta
  long duracion = pulseIn(echoPin, HIGH);
  
  // Calcula distancia (cm)
  return duracion * 0.034 / 2;
}

void actualizarDireccion() {
  distanciaFrontal = medirDistancia();
  paredCercana = (distanciaFrontal <= DISTANCIA_GIRO);

  if (!paredCercana) {
    centrarServo();
    return;
  }

  // Solo gira si hay pared cercana
  int diferencia = valorSensor1 - valorSensor2;

  if (abs(diferencia) > UMBRAL_DIFERENCIA) {
    int anguloServo = map(diferencia, -MAX_DIFERENCIA, MAX_DIFERENCIA, 
                         ANGULO_MAX_IZQUIERDA, ANGULO_MAX_DERECHA);
    anguloServo = constrain(anguloServo, ANGULO_MAX_IZQUIERDA, ANGULO_MAX_DERECHA);
    
    myServo.write(anguloServo);
    estaGirando = true;
    
    Serial.print("Girando a ");
    Serial.print(anguloServo);
    Serial.print(" grados. Distancia: ");
    Serial.print(distanciaFrontal);
    Serial.println(" cm");
  } else {
    manejarGiroCompletado();
  }
}

void manejarGiroCompletado() {
  if (estaGirando) {
    girosDetectados++;
    Serial.print("Giro completado. Total: ");
    Serial.println(girosDetectados);
    
    if (girosDetectados >= GIROS_POR_VUELTA) {
      vueltasCompletadas++;
      Serial.print("Vuelta completada: ");
      Serial.println(vueltasCompletadas);
      
      girosDetectados = 0;
      if (vueltasCompletadas >= MAX_VUELTAS) {
        vehiculoDetenido = true;
        detener();
        Serial.println("Misión completada: 3 vueltas");
      }
    }
    estaGirando = false;
  }
  centrarServo();
}

void loop() {
  if (vehiculoDetenido) return;

  // Procesar datos seriales de los sensores laterales
  recvSerialData();
  if (newData) {
    processSerialCommand();
    newData = false;
    receivedData = "";
    lastSensorUpdate = millis();
  }

  // Verificar timeout
  if (millis() - lastSensorUpdate > TIMEOUT_SENSORES) {
    Serial.println("Error: Sin datos de sensores laterales");
    detener();
    vehiculoDetenido = true;
    return;
  }

  // Control principal
  avanzar();
  actualizarDireccion();
  delay(50); // Pequeña pausa para estabilidad
}

// ================= FUNCIONES AUXILIARES =================

void recvSerialData() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      newData = true;
      break;
    }
    receivedData += c;
  }
}

void processSerialCommand() {
  if (receivedData.startsWith("S1:")) {
    valorSensor1 = parseSensorValue(receivedData);
    Serial.print("Sensor1: ");
    Serial.println(valorSensor1);
  } 
  else if (receivedData.startsWith("S2:")) {
    valorSensor2 = parseSensorValue(receivedData);
    Serial.print("Sensor2: ");
    Serial.println(valorSensor2);
  }
}

int parseSensorValue(String data) {
  int mmIndex = data.indexOf(" mm");
  if (mmIndex != -1) {
    int startIndex = data.indexOf(":") + 2;
    return data.substring(startIndex, mmIndex).toInt();
  }
  return 0;
}

void centrarServo() {
  myServo.write(ANGULO_CENTRO);
}
