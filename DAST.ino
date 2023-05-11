const int LDR1_PIN = A0;
const int LDR2_PIN = A1;
const int LDR3_PIN = A2;
const int LDR4_PIN = A3;
const int ENABLE_PIN = 3;
const int MOTOR_PIN1 = 7;
const int MOTOR_PIN2 = 9;

void setup() {
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  digitalWrite(ENABLE_PIN, HIGH); // enable the motor driver
  Serial.begin(9600);  // initialize serial communication
}

void loop() {
  int ldr1_value = analogRead(LDR1_PIN);
  int ldr2_value = analogRead(LDR2_PIN);
  int ldr3_value = analogRead(LDR3_PIN);
  int ldr4_value = analogRead(LDR4_PIN);

  // convert analog values to voltage values
  float ldr1_voltage = ldr1_value * (5.0 / 1023.0);
  float ldr2_voltage = ldr2_value * (5.0 / 1023.0);
  float ldr3_voltage = ldr3_value * (5.0 / 1023.0);
  float ldr4_voltage = ldr4_value * (5.0 / 1023.0);

  // print voltage values to serial monitor
  Serial.print("LDR 1 Voltage: ");
  Serial.print(ldr1_voltage);
  Serial.print("V | Resistance: ");
  Serial.print((5.0-ldr1_voltage)/ldr1_voltage * 10e3);
  Serial.print("kOhm\n");

  Serial.print("LDR 2 Voltage: ");
  Serial.print(ldr2_voltage);
  Serial.print("V | Resistance: ");
  Serial.print((5.0-ldr2_voltage)/ldr2_voltage * 10e3);
  Serial.print("kOhm\n");

  Serial.print("LDR 3 Voltage: ");
  Serial.print(ldr3_voltage);
  Serial.print("V | Resistance: ");
  Serial.print((5.0-ldr3_voltage)/ldr3_voltage * 10e3);
  Serial.print("kOhm\n");

  Serial.print("LDR 4 Voltage: ");
  Serial.print(ldr4_voltage);
  Serial.print("V | Resistance: ");
  Serial.print((5.0-ldr4_voltage)/ldr4_voltage * 10e3);
  Serial.print("kOhm\n");

  // adjust motor direction based on LDR values
  if (ldr1_value < ldr4_value && ldr2_value < ldr4_value && ldr3_value < ldr4_value) {
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
  } else if (ldr1_value > ldr4_value && ldr2_value < ldr4_value && ldr3_value < ldr4_value) {
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, HIGH);
  } else if (ldr1_value < ldr4_value && ldr2_value > ldr4_value && ldr3_value < ldr4_value) {
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
  } else if (ldr1_value < ldr4_value && ldr2_value < ldr4_value && ldr3_value > ldr4_value) {
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, HIGH);
  }
}