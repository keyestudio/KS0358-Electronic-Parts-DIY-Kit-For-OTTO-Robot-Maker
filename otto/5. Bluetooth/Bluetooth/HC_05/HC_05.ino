

void setup()
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
  Serial.begin(38400);
  Serial.println("Enter AT commands:");
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (Serial.available())
    Serial.write(Serial.read());

}
