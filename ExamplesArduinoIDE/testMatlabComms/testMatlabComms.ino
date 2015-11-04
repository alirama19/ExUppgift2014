int sensorPin = A7;
int sensorValue = 0;

int incomingByte = 0;

void setup(){
  Serial.begin(115200);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    delay(10);
}

