/*
Author: Jordan Anderson
GitHub: https://github.com/Jordan-M-Anderson
Date: 6/13/2021
Program:
This program is for an Arduino Uno 'Useless Machine.' I modeled and printed a case for the arduino and used a 
SPDT switch and a servo motor. The program handles motor functions and gives the machine some personality. 
*/
#include <Servo.h>

Servo serv;

int servoDelay = 1000;
int smallDelay = 10;
int randStart;
int servoMax = 145;
int servoMin = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serv.attach(9);
  serv.write(servoMax);
}

void loop() {
  // put your main code here, to run repeatedly:
  int servoDelay = 1000;
  randStart = random(5000);

  //Debug for the switch
  Serial.println(digitalRead(3));
  
  if (digitalRead(3) != HIGH) {

    //modes for flipping the switch
    switch(random(3)){
      case 0:
      for(int i = servoMax; i >= servoMin; i -= 1){

        serv.write(i);
        delay(smallDelay);
      
      }
      break;
      case 1:
      for(int i = servoMax; i >= servoMin; i -= random(50, 125)){

        serv.write(i);
        delay(servoDelay);
      
      }
      break;
      case 2:
      delay(randStart);
      serv.write(servoMin);
      delay(servoDelay);
      break;
      default:
      delay(smallDelay);
      serv.write(servoMin);
      delay(servoDelay);
    }
    serv.write(servoMin);
    delay(smallDelay);

  }
  serv.write(servoMax);
  delay(servoDelay);
}
