int testByte;
int incomingByte;
int i;

void setup() {
  Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps

  pinMode(13, OUTPUT);

  digitalWrite(13, LOW);
}

void loop() {

  testByte = receiveByte();

  if (testByte > 0) {
    for (i = 0; i < 10000000; i++) {
      digitalWrite(13, HIGH);
    }

  }

}

int receiveByte() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    return incomingByte;
  }
  else {
    return 0;
  }
}

int testPrintByte() {
}

