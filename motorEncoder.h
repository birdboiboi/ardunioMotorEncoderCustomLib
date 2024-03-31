#pragma once

struct MotorController{
	int in1;
	int in2;
	bool in1High;
	bool in2High;
};

struct Encoder{
	int d0;
	bool value;
};

class MotorEncoder{

	public:
		MotorEncoder(int in1,int in2,int d0Encoder);
		void rotateNticks(int nTicks);
		void Update();	
		bool isPositiveRotation;
		void addTicks(int tick);
    Encoder encoder;

	private:
		int targetTick;
		int ticks;
		MotorController motorControl;
};
