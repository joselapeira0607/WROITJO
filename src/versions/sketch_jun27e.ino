#include <Pixy2.h>
#include <Servo.h>
#include <SPI.h>

// --- Configuración de pines ---
const int motorPin1 = 3;       // Control motor
const int motorPin2 = 6;       // Control motor
const int servoPin = 9;        // Servo dirección
const int trigPin = 4;         // Ultrasónico Trigger
const int echoPin = 5;         // Ultrasónico Echo

// --- Sensores de color (Pixy2) ---
Pixy2 pixy;

// --- Parámetros del servo ---
const int ANGULO_CENTRO = 90;
const int ANGULO_MAX_DERECHA = 120;
const int ANGULO_MAX_IZQUIERDA = 60;

// --- Umbrales y constantes ---
const int UMBRAL_DIFERENCIA = 30;     // mm para considerar recto
const int MAX_DIFERENCIA = 160;       // mm diferencia máxima
const int DISTANCIA_OBSTACULO = 20;   // cm para activar giro
const int TIMEOUT_SENSORES = 1000;    // ms sin datos antes de detenerse

// --- Control de vueltas ---
const int GIROS_POR_VUELTA = 4;
const int MAX_VUELTAS = 3;

// --- Firmas de color Pixy2 ---
#define SIG_VERDE 1
#define SIG_ROJO 2
const int UMBRAL_AREA = 3000;         // Tamaño mínimo para considerar objeto

// --- Variables del sistema ---
Servo myServo;
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

// --- Estados de navegación ---
enum ModoNavegacion {MODO_VUELTAS, MODO_ESQUIVA};
ModoNavegacion modoActual = MODO_VUELTAS;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando sistema combinado...");

  // Inicializar Pixy2
  pixy.init();
  Serial.println("Pixy2 inicializado");

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
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duracion = pulseIn(echoPin, HIGH);
  return duracion * 0.034 / 2;
}

void procesarColor() {
  pixy.ccc.getBlocks();
  
  if (pixy.ccc.numBlocks) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      int signature = pixy.ccc.blocks[i].m_signature;
      int area = pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height;
      
      if (area > UMBRAL_AREA) {
        Serial.print("Objeto detectado: ");
        Serial.print(signature == SIG_VERDE ? "VERDE" : "ROJO");
        Serial.print(" Area: ");
        Serial.println(area);

        // Cambiar a modo esquiva si detecta objeto importante
        if (signature == SIG_VERDE || signature == SIG_ROJO) {
          modoActual = MODO_ESQUIVA;
          if (signature == SIG_VERDE) {
            girarIzquierda(ANGULO_MAX_IZQUIERDA);
          } else {
            girarDerecha(ANGULO_MAX_DERECHA);
          }
          delay(800); // Tiempo de giro
          centrarServo();
          modoActual = MODO_VUELTAS; // Volver al modo normal
          return;
        }
      }
    }
  }
}

void actualizarDireccion() {
  distanciaFrontal = medirDistancia();
  procesarColor(); // Verificar objetos de color primero

  if (modoActual == MODO_ESQUIVA) return;

  paredCercana = (distanciaFrontal <= DISTANCIA_OBSTACULO);

  if (!paredCercana) {
    centrarServo();
    manejarGiroCompletado();
    return;
  }

  // Lógica de giro basada en sensores laterales
  int diferencia = valorSensor1 - valorSensor2;

  if (abs(diferencia) > UMBRAL_DIFERENCIA) {
    int anguloServo = map(diferencia, -MAX_DIFERENCIA, MAX_DIFERENCIA, 
                         ANGULO_MAX_IZQUIERDA, ANGULO_MAX_DERECHA);
    anguloServo = constrain(anguloServo, ANGULO_MAX_IZQUIERDA, ANGULO_MAX_DERECHA);
    
    myServo.write(anguloServo);
    estaGirando = true;
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

// ================= FUNCIONES AUXILIARES =================

void girarDerecha(int angulo) {
  angulo = constrain(angulo, ANGULO_CENTRO, ANGULO_MAX_DERECHA);
  myServo.write(angulo);
  Serial.print("Girando derecha: ");
  Serial.println(angulo);
}

void girarIzquierda(int angulo) {
  angulo = constrain(angulo, ANGULO_MAX_IZQUIERDA, ANGULO_CENTRO);
  myServo.write(angulo);
  Serial.print("Girando izquierda: ");
  Serial.println(angulo);
}

void centrarServo() {
  myServo.write(ANGULO_CENTRO);
}

void loop() {
  if (vehiculoDetenido) return;

  // Simular lectura de sensores laterales (reemplazar con tu código real)
  valorSensor1 = random(100, 200);
  valorSensor2 = random(100, 200);
  lastSensorUpdate = millis();

  if (!vehiculoDetenido) {
    avanzar();
    actualizarDireccion();
  }

  delay(50);
}