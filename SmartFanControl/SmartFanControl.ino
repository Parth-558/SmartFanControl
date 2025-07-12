const int tempPin = A0;      // TMP36 sensor
const int fanPin = 5;        // PWM pin for fan (LED simulates fan)
const int btnPin = 2;        // Button to toggle mode
const int ledPin = 7;        // Optional: mode LED indicator

bool manualMode = false;
bool fanState = false;
unsigned long lastDebounceTime = 0;
int debounceDelay = 200;

void setup() {
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("Temp: ");
  Serial.println(temperatureC);

  if (!manualMode) {
    // Auto Mode: Control fan speed based on temperature
    int fanSpeed = map(temperatureC, 25, 40, 0, 255);
    fanSpeed = constrain(fanSpeed, 0, 255);
    analogWrite(fanPin, fanSpeed);

    if (fanSpeed > 0) digitalWrite(ledPin, HIGH);
    else digitalWrite(ledPin, LOW);
  }

  checkButton();
  delay(200);
}

void checkButton() {
  static bool lastButtonState = HIGH;
  bool currentButtonState = digitalRead(btnPin);

  if (lastButtonState == HIGH && currentButtonState == LOW && (millis() - lastDebounceTime > debounceDelay)) {
    manualMode = !manualMode;
    fanState = !fanState;
    lastDebounceTime = millis();
  }

  lastButtonState = currentButtonState;

  if (manualMode) {
    digitalWrite(ledPin, fanState ? HIGH : LOW);
    analogWrite(fanPin, fanState ? 200 : 0);
  }
}
