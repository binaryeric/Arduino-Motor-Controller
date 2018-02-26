
#ifndef MotorController_h
#define MotorController_h

#include "Arduino.h"

// Class definition
class MotorController {
  private:
    int signal_pin;
    double set_point; // aka pulse time
    int pulse_elapsed_time;
    bool on;

  public:
    MotorController(int pin);
    void set(double value);
    void start_pulse();
    void end_pulse();
    int get_pulse_time();
    int get_elapsed_time();
    bool is_on();
};

#endif

