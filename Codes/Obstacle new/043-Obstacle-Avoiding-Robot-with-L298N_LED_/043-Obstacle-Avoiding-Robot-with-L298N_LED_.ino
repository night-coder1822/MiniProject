#include <Servo.h> // Include the Servo library

#define BUZZER_PIN 8 // Define the buzzer pin
#define SERVO_PIN 9 // Define the servo pin

Servo myservo; // Create a servo object

int trig = 7;
int echo = 6;
long timeInMicro;
long distanceInCm;
bool obstacleDetected = false;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Attach servo to pin 9
  myservo.attach(SERVO_PIN);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  timeInMicro = pulseIn(echo, HIGH);

  distanceInCm = ((timeInMicro / 29) / 2);

  Serial.println(distanceInCm);

  if (distanceInCm <= 20) {
    digitalWrite(BUZZER_PIN, HIGH);
    obstacleDetected = true;
    
    // Rotate servo from 90 to -90 degrees
    for (int pos = 90; pos >= -90; pos -= 1) {
      myservo.write(pos); // Set servo position
      delay(15); // Wait for servo to move
    }
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    obstacleDetected = false;
  }

  // If no obstacle detected, start the motor
  if (!obstacleDetected) {
    // Your code to control the motor driver to start the motor in the appropriate direction
    // For example, if motor should rotate clockwise, you might do something like:
    // digitalWrite(MOTOR_DIRECTION_PIN, HIGH); // Set motor direction
    // analogWrite(MOTOR_SPEED_PIN, 255); // Start the motor at full speed
  }

  delay(100); // Wait for 1 second before re-evaluating
}
