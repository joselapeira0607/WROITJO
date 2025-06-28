# Autonomous Vehicle Control System

An Arduino-based control system for autonomous navigation using distance sensors and servo steering.

### Parameters
```cpp
#include <Servo.h>  // Include the Servo library to control the steering mechanism

// === PIN CONFIGURATION ===
const int motorPin1 = 3;  // Pin to control motor direction (forward)
const int motorPin2 = 6;  // Pin to control motor direction (reverse or stop)
const int servoPin   = 9; // PWM pin connected to the servo motor for steering

// === SERVO STEERING LIMITS ===
const int ANGLE_CENTER       = 90;  // Neutral angle: wheels aligned straight
const int ANGLE_MAX_RIGHT    = 120; // Max turn right angle
const int ANGLE_MAX_LEFT     = 60;  // Max turn left angle

// === SENSOR LOGIC AND SAFETY LIMITS ===
const int DIFFERENCE_THRESHOLD = 30;    // Acceptable difference (in mm) between sensors to consider straight
const int MAX_DIFFERENCE       = 160;   // Max expected measurable difference to scale the steering
const int SENSOR_TIMEOUT       = 1000;  // Stop the vehicle if no sensor data is received within this time (in ms)

// === LAPS AND TURNS CONTROL ===
const int TURNS_PER_LAP = 4;  // Number of turns that count as one lap
const int MAX_LAPS      = 3;  // Stop the vehicle after completing this many laps

// === GLOBAL VARIABLES ===
Servo myServo;                   // Servo object to control steering
String receivedData = "";        // Buffer to collect incoming serial data
bool newData         = false;    // Flag indicating whether a complete command was received
int sensorValue1     = 0;        // Latest reading from sensor 1
int sensorValue2     = 0;        // Latest reading from sensor 2
unsigned long lastSensorUpdate = 0; // Timestamp of last sensor input

// === STATE OF THE VEHICLE ===
int turnsDetected     = 0;       // Counts how many turns have been completed in the current lap
int lapsCompleted     = 0;       // Total laps completed
bool isTurning        = false;   // Tracks if the robot was turning in the last cycle
bool vehicleStopped   = false;   // True when the robot finishes its mission or hits a timeout

void setup() {
  Serial.begin(9600);  // Start serial communication to receive sensor data
  Serial.println("Arduino: System started. Waiting for sensor data...");

  pinMode(motorPin1, OUTPUT); // Motor direction pin 1
  pinMode(motorPin2, OUTPUT); // Motor direction pin 2

  myServo.attach(servoPin);   // Attach servo control to the designated pin
  centerServo();              // Initialize with centered steering
}

// === MOVEMENT CONTROL FUNCTIONS ===
void moveForward() {
  // Set motor to move forward
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void stopVehicle() {
  // Stop the motor and straighten steering
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  centerServo();
  Serial.println("Movement: Stopped");
}

// === SERVO CONTROL ===
void centerServo() {
  // Set servo to center position
  myServo.write(ANGLE_CENTER);
}

void turnRight(int angle) {
  // Clamp angle to max range and turn servo right
  angle = constrain(angle, ANGLE_CENTER, ANGLE_MAX_RIGHT);
  myServo.write(angle);
  Serial.print("Direction: Turning right to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

void turnLeft(int angle) {
  // Clamp angle to max range and turn servo left
  angle = constrain(angle, ANGLE_MAX_LEFT, ANGLE_CENTER);
  myServo.write(angle);
  Serial.print("Direction: Turning left to ");
  Serial.print(angle);
  Serial.println(" degrees");
}

// === SERIAL COMMUNICATION HANDLING ===
void recvSerialData() {
  // Reads incoming characters until newline '\n' is detected
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar == '\n') {
      newData = true; // Full command received
      break;
    }
    receivedData += receivedChar;
  }
}

void processSerialCommand() {
  // Distinguish between Sensor 1 and Sensor 2 data
  if (receivedData.startsWith("S1:")) {
    processSensorData(receivedData, sensorValue1, 1);
  } 
  else if (receivedData.startsWith("S2:")) {
    processSensorData(receivedData, sensorValue2, 2);
  }

  // Reset input buffer after processing
  receivedData = "";
  newData = false;
  lastSensorUpdate = millis();  // Update the timestamp
}

void processSensorData(String &data, int &sensorValue, int sensorNum) {
  // Extract the number from format like "S1: 123 mm"
  int mmIndex = data.indexOf(" mm");
  if (mmIndex != -1) {
    int startIndex = data.indexOf(":") + 2;
    String valueString = data.substring(startIndex, mmIndex);
    sensorValue = valueString.toInt();

    Serial.print("Sensor ");
    Serial.print(sensorNum);
    Serial.print(" updated: ");
    Serial.print(sensorValue);
    Serial.println(" mm");
  }
}

// === NAVIGATION DECISION MAKING ===
void updateSteering() {
  if (vehicleStopped) return; // If vehicle is halted, skip

  int difference = sensorValue1 - sensorValue2;

  if (abs(difference) <= DIFFERENCE_THRESHOLD) {
    // Continue straight if difference is within tolerance
    centerServo();
    handleTurnCompleted();
  } 
  else {
    // Map the difference linearly into an appropriate steering angle
    int servoAngle = map(difference, -MAX_DIFFERENCE, MAX_DIFFERENCE, 
                         ANGLE_MAX_LEFT, ANGLE_MAX_RIGHT);
    servoAngle = constrain(servoAngle, ANGLE_MAX_LEFT, ANGLE_MAX_RIGHT);

    // Turn left or right accordingly
    if (difference > 0) {
      turnRight(servoAngle);
    } else {
      turnLeft(servoAngle);
    }

    isTurning = true; // Flag that we're mid-turn
  }
}

void handleTurnCompleted() {
  // Detect change from turning to straight
  if (isTurning) {
    turnsDetected++;
    Serial.print("Turn completed. Total: ");
    Serial.println(turnsDetected);

    // If number of turns equals one full lap
    if (turnsDetected >= TURNS_PER_LAP) {
      lapsCompleted++;
      Serial.print("Lap completed: ");
      Serial.println(lapsCompleted);

      turnsDetected = 0; // Reset counter for the next lap

      if (lapsCompleted >= MAX_LAPS) {
        // Mission success! Stop everything
        vehicleStopped = true;
        stopVehicle();
        Serial.println("Mission complete: 3 laps finished");
      }
    }

    isTurning = false; // Reset turn state
  }
}

void checkSensorTimeout() {
  // If too much time passed without sensor input, stop for safety
  if (millis() - lastSensorUpdate > SENSOR_TIMEOUT) {
    Serial.println("WARNING: Sensor timeout. Stopping vehicle...");
    stopVehicle();
    vehicleStopped = true;
  }
}

// === MAIN LOOP ===
void loop() {
  if (vehicleStopped) return; // Skip logic if mission is already done

  recvSerialData();       // Check for new sensor data
  if (newData) {
    processSerialCommand();
  }

  // Run only if vehicle is allowed to move
  if (!vehicleStopped) {
    moveForward();        // Activate motors
    updateSteering();     // Adjust direction based on sensors
    checkSensorTimeout(); // Safety mechanism
  }
}

