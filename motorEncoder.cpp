#include "motorEncoder.h"

MotorEncoder::MotorEncoder(int in1,int in2,int d0Encoder){
	this->motorControl.in1 = in1;
	this->motorControl.in2 = in1;
	this->encoder.d0 = d0Encoder;	
}

//nTicks should include poistive or negative
void MotorEncoder::rotateNticks(int nTicks){
	if(nTicks>0){
		this->isPositiveRotation = true;
	}else{
		this->isPositiveRotation = false;
	}
	this->targetTick = nTicks;
}

void MotorEncoder::Update(){
	if(this->targetTick > 0){
		//in1 output HIGH
		//in2 output LOW
		this->motorControl.in1High = true;
		this->motorControl.in2High = false;
				
	}else if(this-> targetTick < 0){
		this->motorControl.in1High = false;
		this->motorControl.in2High = true;
	}
	//TODO:can embed direction in targetTick if no extra logic
	if(this->encoder.value){
		if(this->isPositiveRotation){
			this->addTicks(1);
		}else{
			this->addTicks(-1);
		}
	}
}

void MotorEncoder::addTicks(int tick){
	this->ticks += tick;
	//ToDo:add velocity component later(with timestamp thingy)
	
}
