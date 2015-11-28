int sensorpin = A8;                 // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)

void setup()
{
  Serial.begin(115200);               // starts the serial monitor
}
 
void loop()
{
  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  Serial.println(val);            // prints the value of the sensor to the serial monitor
  delay(10);                    // wait for this much time before printing next value
}
