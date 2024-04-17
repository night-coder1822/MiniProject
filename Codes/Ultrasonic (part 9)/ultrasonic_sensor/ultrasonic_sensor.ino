#include <Servo.h>

// Define the pins for ultrasonic sensor
int trig = A1;
int echo = A2;

// Define the servo motor
Servo servo;

// Variables to store time and distance
long timeInMicro;
long distanceInCm;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes for ultrasonic sensor
  pinMode(trig, OUTPUT); // Trigger pin as output
  pinMode(echo, INPUT);  // Echo pin as input

  // Attach servo to pin 10
  servo.attach(10);
}

void loop() {
  // Send trigger signal to the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure the pulse duration from echo pin
  timeInMicro = pulseIn(echo, HIGH);

  // Calculate distance in centimeters
  distanceInCm = ((timeInMicro / 29) / 2);

  // Print distance to serial monitor
  Serial.println(distanceInCm);

  // Rotate servo based on distance
  if (distanceInCm <= 30) { 
    // If distance is within 30cm, rotate the servo motor to -90 degrees
    servo.write(-90);
  } else {
    // Otherwise, keep the servo motor at 90 degrees
    servo.write(90);
  }

  // Delay for stability
  delay(100);
}
