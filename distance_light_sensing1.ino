// Pins
const int ultrasonicPin = 7;     // 3-pin Ultrasonic SIG
const int buttonPin = 2;         // Push button
const int lightSensorPin = A0;   // LDR analog input

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // --- Ultrasonic distance measurement ---
    long duration, distance;

    pinMode(ultrasonicPin, OUTPUT);
    digitalWrite(ultrasonicPin, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasonicPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonicPin, LOW);

    pinMode(ultrasonicPin, INPUT);
    duration = pulseIn(ultrasonicPin, HIGH);
    distance = duration * 0.01723;

    // --- Ambient light reading ---
    int lightLevel = analogRead(lightSensorPin);

    // --- Output ---
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Light Level: ");
    Serial.println(lightLevel);
  }

  delay(300);  // Slight delay for stability
}
