#include <Servo.h>

Servo myservo;

//  Define relay connection:

int led=33;
int water_pump=35;
int cold_steam=37;
int fan=31;

// Define Servo pin 
int servopin=7;

int pos=0;

void setup() {

 myservo.attach(servopin);
  
 pinMode(fan,OUTPUT);
 pinMode(water_pump,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(cold_steam,OUTPUT);

 digitalWrite(fan,1);
 digitalWrite(water_pump,1);
 digitalWrite(led,1);
 digitalWrite(cold_steam,1);
 delay(2000);
ServoUp();
delay(5000);
ServoDown();
}

void loop() {

digitalWrite(led,0);
delay(500);
digitalWrite(led,1);

}

void ServoUp(){
    myservo.attach(servopin);
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
    }
    myservo.detach(); 
}

void ServoDown(){
    myservo.attach(servopin);
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
    }
    myservo.detach(); 
}
