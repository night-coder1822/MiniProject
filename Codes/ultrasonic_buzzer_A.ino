// Define the buzzer pin
#define BUZZER_PIN 8

// Define the pins for ultrasonic sensor
int trig = 7;
int echo = 6;

// Variables to store time and distance
long timeInMicro;
long distanceInCm;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes for ultrasonic sensor and buzzer
  pinMode(trig, OUTPUT); // Trigger pin as output
  pinMode(echo, INPUT);  // Echo pin as input
  pinMode(BUZZER_PIN, OUTPUT); // Buzzer pin as output
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

  // Check if distance is less than or equal to 20cm
  if (distanceInCm <= 20) { 
    // If distance is within 20cm, turn on the buzzer
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    // Otherwise, turn off the buzzer
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Delay for stability
  delay(50);
}