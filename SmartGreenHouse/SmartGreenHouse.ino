#include <Servo.h>
#include <dht.h>
#define dhtpin 2
dht DHT;
Servo myservo char data;
//  Define relay connection:
int led = 33;
int water_pump = 35;
int cold_steam = 37;
int fan = 31;
// Define Servo pin
int servopin = 7;
//  Define Soile sensor pin:
int soil_sensor1 = A1;
int soil_sensor2 = A2;
//  Define ldr pin
int ldr = A0;
int pos = 0;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  myservo.attach(servopin);
  pinMode(fan, OUTPUT);
  pinMode(water_pump, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(cold_steam, OUTPUT);
  pinMode(soil_sensor1, INPUT);
  pinMode(soil_sensor2, INPUT);
  digitalWrite(fan, 1);
  digitalWrite(water_pump, 1);
  digitalWrite(led, 1);
  digitalWrite(cold_steam, 1);
  ServoUp();
  delay(5000);
  ServoDown();
}
void loop() {
  int soil_sn1 = analogRead(soil_sensor1);
  int soil_sn2 = analogRead(soil_sensor2);
  soil_sn1 = map(soil_sn1, 1023, 0, 0, 100);
  soil_sn2 = map(soil_sn1, 1023, 0, 0, 100);
  Serial1.print("Soil hum 1 is : ");
  Serial1.println(soil_sn1);
  Serial1.print("Soil hum 2 is : ");
  Serial1.println(soil_sn2);
  Serial1.print("Temperatur is : ");
  Serial1.println(Dht_Temp());
  Serial1.print("Humidity is : ");
  Serial1.println(Dht_Humi());
  delay(2000);
  if (Serial1.available() > 0) {
    data = Serial1.read();
    if (data == 'l') {
      digitalWrite(led, 0);
    }
    if (data == 'f') {
      digitalWrite(fan, 0);
      Serial.println("fan is on");
    }
    if (data == 'w') {
      Serial.println("water pump is  on");
      digitalWrite(water_pump, 0);
      delay(2000);
      digitalWrite(water_pump, 1);
    }
    if (data == 'c') {
      digitalWrite(cold_steam, 0);
      Serial.println("cold steam is on");
    }
    if (data == 'a') {
      digitalWrite(led, 1);
      Serial.println("led is off");
    }
    if (data == 'g') {
      digitalWrite(fan, 1);
      Serial.println("fan is off");
    }
    if (data == 'h') {
      digitalWrite(water_pump, 1);
      Serial.println("water pump is off");
    }
    if (data == 'k') {
      digitalWrite(cold_steam, 1);
      Serial.println("cold steam is off");
    }
    if (data == 'z') {
      digitalWrite(cold_steam, 1);
      digitalWrite(water_pump, 1);
      digitalWrite(fan, 1);
      digitalWrite(led, 1);
    } else {
    }
    //      int soil_sn1=analogRead(soil_sensor1);
    //      int soil_sn2=analogRead(soil_sensor2);
    //      soil_sn1=map(soil_sn1,1023,0,0,100);
    //      soil_sn2=map(soil_sn1,1023,0,0,100);
    //      Serial1.print("Soil hum 1 is : ");
    //      Serial1.println(soil_sn1);
    //      Serial1.print("Soil hum 2 is : ");
    //      Serial1.println(soil_sn2);
    //
    //      Serial1.print("Temperatur is : ");
    //      Serial1.println(Dht_Temp());
    //      delay(1000);
    //      Serial1.print("Humidity is : ");
    //      Serial1.println(Dht_Humi());
    //      delay(1000);
  }
}

void ServoUp() {
  myservo.attach(servopin);
  for (pos = 0; pos <= 90; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);
  }
  myservo.detach();
}

void ServoDown() {
  myservo.attach(servopin);
  for (pos = 90; pos >= 0; pos -= 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);
  }
  myservo.detach();
}

int Dht_Temp() {
  int readData = DHT.read22(dhtpin);
  float t = DHT.temperature;
  int temp = int(t);
  return temp;
}

int Dht_Humi() {
  int readData = DHT.read22(dhtpin);
  float h = DHT.humidity;
  int hum = int(h);
  return hum;
}