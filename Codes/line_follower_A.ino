// Define pin numbers for motor control
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;

// Define pin numbers for IR sensors
const int leftIRPin = A0;
const int rightIRPin = A1;

// Thresholds for detecting black line
const int threshold = 500; // Adjust this value according to your sensor readings

void setup() {
  // Initialize motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  int leftIRValue = analogRead(leftIRPin);
  int rightIRValue = analogRead(rightIRPin);
  
  // Print IR sensor values for debugging
  Serial.print("Left IR Sensor: ");
  Serial.print(leftIRValue);
  Serial.print(" - Right IR Sensor: ");
  Serial.println(rightIRValue);
  
  // Determine the direction based on sensor readings
  if (leftIRValue > threshold && rightIRValue > threshold) {
    // Both sensors are on the line - move forward
    moveForward();
  } else if (leftIRValue > threshold && rightIRValue < threshold) {
    // Left sensor on the line - turn right
    turnRight();
  } else if (leftIRValue < threshold && rightIRValue > threshold) {
    // Right sensor on the line - turn left
    turnLeft();
  } else {
    // Both sensors off the line - stop
    stopMoving();
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void stopMoving() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}