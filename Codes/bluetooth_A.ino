char t;

void setup() {
  pinMode(13, OUTPUT);   // Left motors forward
  pinMode(12, OUTPUT);   // Left motors reverse
  pinMode(11, OUTPUT);   // Right motors forward
  pinMode(10, OUTPUT);   // Right motors reverse
  pinMode(9, OUTPUT);    // Led
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {            // Move forward (all motors rotate in the forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  } else if (t == 'B') {     // Move reverse (all motors rotate in the reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  } else if (t == 'L') {     // Turn right (left side motors rotate in the forward direction, right side motors don't rotate)
    digitalWrite(11, HIGH);
  } else if (t == 'R') {     // Turn left (right side motors rotate in the forward direction, left side motors don't rotate)
    digitalWrite(13, HIGH);
  } else if (t == 'k') {    // Move forward left (right side motors rotate in the forward direction, left side motors rotate in the reverse direction)
    digitalWrite(13, HIGH);
    digitalWrite(10, HIGH);
  } else if (t == 'FR') {    // Move forward right (left side motors rotate in the forward direction, right side motors rotate in the reverse direction)
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  } else if (t == 'BL') {    // Move backward left (right side motors rotate in the reverse direction, left side motors rotate in the forward direction)
    digitalWrite(13, LOW);
    digitalWrite(10, LOW);
  } else if (t == 'BR') {    // Move backward right (left side motors rotate in the reverse direction, right side motors rotate in the forward direction)
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  } else if (t == 'W') {     // Turn LED on
    digitalWrite(9, HIGH);
  } else if (t == 'N') {     // Turn LED off
    digitalWrite(9, LOW);
  } else if (t == 'S') {     // Stop (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  delay(100);
}
