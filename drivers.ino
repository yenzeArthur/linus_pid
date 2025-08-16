
#include "drivers.h"

void motor_setup(void)
{
    pinMode(rside_motor_front, OUTPUT);
    pinMode(rside_motor_back, OUTPUT);
    pinMode(lside_motor_front, OUTPUT);
    pinMode(lside_motor_back, OUTPUT);
}

void sensors_setup(void)
{
    for(uint8_t i=0; i<5; i++)
    {
      pinMode(ir_sensors[i], INPUT);
    }
}