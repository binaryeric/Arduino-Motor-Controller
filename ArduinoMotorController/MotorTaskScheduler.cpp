#include "Arduino.h"
#include "MotorTaskScheduler.h"


MotorTaskScheduler::MotorTaskScheduler(int arr_size) {
	this -> motors = new MotorController[arr_size];
	this -> arr_idx = 0;
}

void MotorTaskScheduler::addMotor(MotorController *motor) {
	this -> motors[this -> arr_idx] = &motor;
	this -> arr_idx++; //= this -> arr_idx + 1;
}

void MotorTaskScheduler::handle() {
	for(int i=0; i< this->array_size; i++) {
		MotorController mtr = this->motors[i];
		if(mtr.get_elapsed_time() >= mtr.get_pulse_time()) {
			if(mtr.is_on()) {
				mtr.end_pulse();
			} else {
				mtr.start_pulse();
			}
		}
	}
	delayMicroseconds(1);
}
