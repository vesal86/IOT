int photocellPin = A0;     
int photocellReading;

int sensorMin = 0;        
int sensorMax = 1023; 

int SensorLdr=0; 

void setup() {
  Serial.begin(9600);
  pinMode(photocellPin,INPUT);
}

void loop() {
  photocellReading = analogRead(photocellPin);
  //SensorLdr=map(photocellReading,sensorMin, sensorMax, 0, 100);  
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);
  delay(1000);
}
