const int
PWM_A   = 3,
DIR_A   = 12,
BRAKE_A = 9;

void setup() {
  // Configure the A output
  pinMode(BRAKE_A, OUTPUT);  // Brake pin on channel A
  pinMode(DIR_A, OUTPUT);    // Direction pin on channel A

  // Open Serial communication
  Serial.begin(9600);
  Serial.println("Motor shield DC motor Test:\n");

  digitalWrite(BRAKE_A, LOW);  // setting againg the brake LOW to disable motor brake
  digitalWrite(DIR_A, LOW);    // now change the direction to backward setting LOW the DIR_A pin
  analogWrite(PWM_A, 0);     // Idle
  Serial.println("Enabled fan");
}

void loop() {

  // Set motor to full speed
  Serial.println("Full speed, PWM: 255");
  analogWrite(PWM_A, 255);     // Set the speed of the motor
  delay(2000);                 // hold the motor at full speed for some seconds

   // Set motor to full speed
  Serial.println("Half speed, PWM: 127");
  analogWrite(PWM_A, 127);     // Set the speed of the motor
  delay(2000);                 // hold the motor at full speed for some seconds

  // now stop the motor by inertia, the motor will stop slower than with the brake function
  Serial.println("Turn off, PWM: 0");
  analogWrite(PWM_A, 0);       // turn off power to the motor
  delay(2000);                 // hold the motor at full speed for some seconds
}

