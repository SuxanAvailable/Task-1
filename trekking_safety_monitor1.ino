// Pin Definitions
const int tempPin = A0;
const int gasPin = A1;
const int soilPin = A2;

const int redLED = 3;
const int yellowLED = 4;
const int blueLED = 5;
const int buzzer = 6;

void setup() {
  Serial.begin(9600);

  // Set outputs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Read TMP36 temperature sensor
  int tempRaw = analogRead(tempPin);
  float voltage = tempRaw * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100.0;

  // Read gas and soil sensors
  int gasValue = analogRead(gasPin);     // from raw MQ-2 with voltage divider
  int soilValue = analogRead(soilPin);   // soil moisture

  // Debug output
  Serial.print("Temp: "); Serial.print(tempC); Serial.print("°C | ");
  Serial.print("Gas: "); Serial.print(gasValue); Serial.print(" | ");
  Serial.print("Soil: "); Serial.println(soilValue);

  // FIRE ALERT: High temp + high gas
  if (tempC > 40 && gasValue > 400) {
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  }

  // GAS ALERT
  if (gasValue > 700) {
    digitalWrite(yellowLED, HIGH);
  } else {
    digitalWrite(yellowLED, LOW);
  }

  // DRY SOIL ALERT
  if (soilValue < 300) {
    digitalWrite(blueLED, HIGH);
  } else {
    digitalWrite(blueLED, LOW);
  }

  delay(1000);  // Delay for readability
}
