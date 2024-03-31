#include "motorEncoder.h"

const int motorIn1 = 4;
const int motorIn2 = 5;
const int encoderD0 = 6;

bool dirCC = false;
int ticks = 0;
MotorEncoder MCE(motorIn1,motorIn2,encoderD0);

//ToDo: put this in motor encoder library, problem is dependancy on Ardunio ide for digital read and 
void syncEncoderState(){
  int pin = digitalRead(MCE.encoder.d0);
  Serial.println(pin);
  if(pin == HIGH){
    //encapsulation? ToDo: streamline this later
    MCE.encoder.value = true;
    Serial.println("high");
  }else{
    MCE.encoder.value=false;
  }

}

void setup(){

	pinMode(motorIn1,OUTPUT);
	pinMode(motorIn2,OUTPUT);
	pinMode(encoderD0,INPUT);

	Serial.begin(9600);

  MCE.addTicks(5);

}

void loop(){
  syncEncoderState();
  MCE.Update();
}

