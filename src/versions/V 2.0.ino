#include <Servo.h>

// --- Configuración de pines ---
const int motorPin1 = 3;    // Control dirección motor (HIGH/LOW)
const int motorPin2 = 6;    // Control dirección motor (HIGH/LOW)
const int servoPin = 9;     // Pin para control del servo

// --- Parámetros del servo ---
const int ANGULO_CENTRO = 90;
const int ANGULO_MAX_DERECHA = 120;
const int ANGULO_MAX_IZQUIERDA = 60;

// --- Umbrales y constantes ---
const int UMBRAL_DIFERENCIA = 300;    // mm para considerar recto
const int MAX_DIFERENCIA = 160;      // mm diferencia máxima esperada
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

// --- Estado del vehículo ---
int girosDetectados = 0;
int vueltasCompletadas = 0;
bool estaGirando = false;
bool vehiculoDetenido = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino: Sistema iniciado. Esperando datos de sensores...");

  // Configuración pines motor (solo ON/OFF)
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Configuración servo
  myServo.attach(servoPin);
  centrarServo();
}

// ================= FUNCIONES DE CONTROL =================

// --- Control de movimiento (ON/OFF) ---
void avanzar() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void detener() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  centrarServo();
  Serial.println("Movimiento: Detenido");
}

// --- Control de dirección ---
void centrarServo() {
  myServo.write(ANGULO_CENTRO);
}

void girarDerecha(int angulo) {
  angulo = constrain(angulo, ANGULO_CENTRO, ANGULO_MAX_DERECHA);
  myServo.write(angulo);
  Serial.print("Dirección: Girando derecha a ");
  Serial.print(angulo);
  Serial.println(" grados");
}

void girarIzquierda(int angulo) {
  angulo = constrain(angulo, ANGULO_MAX_IZQUIERDA, ANGULO_CENTRO);
  myServo.write(angulo);
  Serial.print("Dirección: Girando izquierda a ");
  Serial.print(angulo);
  Serial.println(" grados");
}

// --- Comunicación Serial ---
void recvSerialData() {
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();
    
    if (receivedChar == '\n') {
      newData = true;
      break;
    }
    
    receivedData += receivedChar;
  }
}

void processSerialCommand() {
  if (receivedData.startsWith("S1:")) {
    procesarDatosSensor(receivedData, valorSensor1, 1);
  } 
  else if (receivedData.startsWith("S2:")) {
    procesarDatosSensor(receivedData, valorSensor2, 2);
  }
  
  receivedData = "";
  newData = false;
  lastSensorUpdate = millis();
}

void procesarDatosSensor(String &data, int &valorSensor, int numSensor) {
  int mmIndex = data.indexOf(" mm");
  if (mmIndex != -1) {
    int startIndex = data.indexOf(":") + 2;
    String valueString = data.substring(startIndex, mmIndex);
    valorSensor = valueString.toInt();
    
    Serial.print("Sensor ");
    Serial.print(numSensor);
    Serial.print(" actualizado: ");
    Serial.print(valorSensor);
    Serial.println(" mm");
  }
}

// --- Lógica de navegación ---
void actualizarDireccion() {
  if (vehiculoDetenido) return;

  int diferencia = valorSensor1 - valorSensor2;

  if (abs(diferencia) <= UMBRAL_DIFERENCIA) {
    centrarServo();
    manejarGiroCompletado();
  } 
  else {
    int anguloServo = map(diferencia, -MAX_DIFERENCIA, MAX_DIFERENCIA, 
                         ANGULO_MAX_IZQUIERDA, ANGULO_MAX_DERECHA);
    anguloServo = constrain(anguloServo, ANGULO_MAX_IZQUIERDA, ANGULO_MAX_DERECHA);
    
    if (diferencia > 0) {
      girarDerecha(anguloServo);
    } else {
      girarIzquierda(anguloServo);
    }
    
    estaGirando = true;
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
}

void verificarTimeoutSensores() {
  if (millis() - lastSensorUpdate > TIMEOUT_SENSORES) {
    Serial.println("ALERTA: Timeout en sensores. Deteniendo...");
    detener();
    vehiculoDetenido = true;
  }
}

// --- Loop principal ---
void loop() {
  if (vehiculoDetenido) return;

  recvSerialData();
  if (newData) processSerialCommand();

  if (!vehiculoDetenido) {
    avanzar();
    actualizarDireccion();
    verificarTimeoutSensores();
  }
}
