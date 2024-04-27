void setup() {
 Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A1);
  sensorValue = map(sensorValue, 1023, 0, 0, 100);
  Serial.println(sensorValue);
  delay(100);       
}
