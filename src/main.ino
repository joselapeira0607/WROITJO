#include <Servo.h> // Includes the Servo library for servo motor control
#define motorPin1 3 // MOTOR
#define motorPin2 6
#define dMin 45 // MINIMUM DISTANCE
#define dFMax 40 // MAXIMUM DISTANCE
#define threshold 25

// --- SERVO CONFIGURATION ---
Servo myServo; // Create a servo object
const int servoPin = 9; // Digital pin where the servo signal wire is connected (e.g., Pin 9 on the Arduino)

// --- SERIAL COMMUNICATION VARIABLES ---
String receivedData = ""; // Buffer to store incoming serial data from the ESP32
bool newData = false; // Flag to indicate when a complete message has arrived (terminated by '\n')

// --- VARIABLES FOR SENSOR VALUES ---
int sensorValue1 = 0; // Variable to store the value of Sensor 1
int sensorValue2 = 0; // Variable to store the value of Sensor 2

bool loopactivo = true;

void setup() {
    Serial.begin(9600);
    Serial.println("Arduino: Ready to receive servo commands from ESP32.");
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    
    // --- Servo Configuration ---
    myServo.attach(servoPin); // Associate the servo object with the configured pin
    myServo.write(90); // Moves the servo to the center position (90 degrees) at the start
}

// --- FUNCTIONS FOR HANDLING SERIAL COMMUNICATION ---
void recvSerialData() {
    while (Serial.available() > 0) { // While there are bytes available to read
        char receivedChar = Serial.read(); // Reads a character
        receivedData += receivedChar; // Adds it to the string buffer
        if (receivedChar == '\n') { // Checks if it's the newline terminator
            newData = true; // A complete message has arrived
        }
    }
}

void advance() {
    digitalWrite(motorPin1, HIGH); // Activates motorPin1 to move forward
    digitalWrite(motorPin2, LOW);  // Ensures motorPin2 remains off
}

void stop() {
    digitalWrite(motorPin1, LOW); // Stops the motor
    digitalWrite(motorPin2, LOW); // Ensures both pins are LOW to prevent movement
}

void processSerialCommand() {
    // --- Process message from Sensor 1 ---
    if (receivedData.startsWith("S1:")) {
        int mmIndex = receivedData.indexOf(" mm");
        if (mmIndex != -1) { // Ensure that " mm" was found
            int startIndex = receivedData.indexOf(":") + 2; // +2 to skip ": "
            String valueString = receivedData.substring(startIndex, mmIndex);
            sensorValue1 = valueString.toInt(); // Convert to integer and store
            Serial.print("Arduino: Sensor 1 stored: ");
            Serial.println(sensorValue1);
        }
    }
    // --- Process message from Sensor 2 ---
    else if (receivedData.startsWith("S2:")) {
        int mmIndex = receivedData.indexOf(" mm");
        if (mmIndex != -1) { // Ensure that " mm" was found
            int startIndex = receivedData.indexOf(":") + 2; // +2 to skip ": "
            String valueString = receivedData.substring(startIndex, mmIndex);
            sensorValue2 = valueString.toInt(); // Convert to integer and store
            Serial.print("Arduino: Sensor 2 stored: ");
            Serial.println(sensorValue2);
        }
    }
}

void loop() {
    int i = 0;
    int state = 0;
    advance(); // Start by moving forward

    do {
        recvSerialData(); // Receive serial data
        if (newData == true) { // If new data has been received
            processSerialCommand(); // Process the command
            receivedData = ""; // Clear the buffer for the next message
            newData = false; // Reset the flag
        }

        // --- Servo movement logic based on sensor values ---
        if (sensorValue2 < sensorValue1 - threshold) {
            if (state != 1) { // If the current state is NOT 1
                myServo.write(10); // Move the servo to 10 degrees
                state = 1; // Update the state
                delay(1000); // Pause for stability
            }
        } else if (sensorValue1 < sensorValue2 - threshold) {
            if (state != 2) { // If the current state is NOT 2
                myServo.write(170); // Move the servo to 170 degrees
                state = 2; // Update the state
                delay(1000);
            }
        } else {
            if (state != 0) { // If the current state is NOT 0
                myServo.write(90); // Move the servo to the neutral position (90 degrees)
                state = 0; // Update the state
                delay(1000);
            }
        }
    } while (i < 12); // Repeat the loop a fixed number of times
}
