
#include "driver_config.h"
#include "motors.h"
#include "drivers.h"
#include "sensors.h"

void drivers_init(void)
{
    init_motors(&write_lside_motor_front, &write_lside_motor_back, &write_rside_motor_front, &write_rside_motor_back);
    ir_sensors_setup(&read_sensor_value);
}

void write_rside_motor_front(uint8_t value)
{
    analogWrite(rside_motor_front, value);
}

void write_lside_motor_front(uint8_t value)
{
    analogWrite(lside_motor_front, value);
}

void write_rside_motor_back(uint8_t value)
{
    analogWrite(rside_motor_back, value);
}

void write_lside_motor_back(uint8_t value)
{
    analogWrite(lside_motor_back, value);
}

uint16_t read_sensor_value(uint8_t index)
{
    return analogRead(ir_sensors[index]);
}

