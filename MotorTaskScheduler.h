#ifndef MotorTaskScheduler_h
#define MotorTaskScheduler_h

#include "Arduino.h"
#include "MotorController.h"

// Class definition
class MotorTaskScheduler {
  private:
    int array_size;
    MotorController motors[];
    int arr_idx;
  public:
    MotorTaskScheduler(int arr_size);
    void addMotor(MotorController *motor);
    void handle();
    
};

#endif