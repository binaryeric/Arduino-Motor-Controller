#include "Arduino.h"
#include "MotorController.h"


/*
 * SPARK MOTOR CONTROLLERS: 
 *A delay of 1000 Microseconds is Full Reverse
 *A delay of 1000 to 1460 Microseconds is Proportional Reverse
 *A delay of 1460 to 1540 Microseconds is neutral
 *A delay of 1540 to 2000 Microseconds is Proportional Forward
 *A delay of 2000 Microseconds is Full Forward
 */

// constructor
MotorController::MotorController(int pin) {
  this -> signal_pin = pin;
  this -> set_point = 0;
  this -> pulse_elapsed_time = 0;
  this -> on = false;
  //
  pinMode(pin, OUTPUT);
}

void MotorController::set(double value) {
  if(value == 0 || abs(value) > 1) {
    this -> set_point = 0; // Stop
  } else if(value > 0) {
    // between 1000 and 1460
    this -> set_point = map(value,0,1,1540,2000);
  } else if(value < 0) {
    this -> set_point = map(value,-1,0,1000,1460);
  }
}

void MotorController::start_pulse() {
  if(this -> set_point != 0) {
    this -> pulse_elapsed_time = 0;
    this -> on = true;
    digitalWrite(this->signal_pin, HIGH);
  }
}

void MotorController::end_pulse() {
  this -> pulse_elapsed_time = 0;
  this -> on = false;
  digitalWrite(this->signal_pin, LOW);
}

int MotorController::get_elapsed_time() {
  this -> pulse_elapsed_time++;
  return this -> pulse_elapsed_time;
}

int MotorController::get_pulse_time() {
  return this -> set_point;
}

bool MotorController::is_on() {
  return this -> on;
}

