#include "MotorController.h"
#include "MotorTaskScheduler.h"

MotorController m1 = new MotorController(0);
MotorController m2 = new MotorController(1);

MotorTaskScheduler motor_handler(2);

void setup() {
  //&m1.set(1);
  motor_handler.addMotor(&m1);
  motor_handler.addMotor(&m2);
}

void loop() {
  // your serial stuff here ;)

  motor_handler.handle();
  
}
