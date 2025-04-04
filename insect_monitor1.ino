const int ldrPin = A0;
const int tempPin = A1;      // TMP36 analog pin
const int pirPin = 2;
const int outputPin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  bool motion = digitalRead(pirPin);

  // Simulate temperature (replace with actual if needed)
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  bool isDark = ldrValue < 900;
  bool isHot = temperatureC > 16;
  bool ismid = temperatureC < 40; 

  Serial.print("LDR: "); Serial.print(ldrValue);
  Serial.print(" | Motion: "); Serial.print(motion);
  Serial.print(" | Temp: "); Serial.print(temperatureC);
  Serial.println(" °C");

  if (isDark && motion && isHot && ismid) {
    digitalWrite(outputPin, HIGH);
    delay(3000);
    digitalWrite(outputPin, LOW);
  } else {
    digitalWrite(outputPin, LOW);
  }

  delay(1000);
}
