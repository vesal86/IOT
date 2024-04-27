#include <dht.h>
#define dhtpin 2

dht DHT;
void setup() {
 Serial.begin(9600);
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(Dht_Temp());
  Serial.println(" ");

  Serial.print("Humidity = ");
  Serial.print(Dht_Humi());
  Serial.println(" %");
  delay(2000);
}

int Dht_Temp(){
  int readData = DHT.read22(dhtpin);
  float t = DHT.temperature;
  int temp=int(t);
  return temp;
}

int Dht_Humi(){
  int readData = DHT.read22(dhtpin);
  float h = DHT.humidity;
  int hum=int(h);
  return hum;
}  
