
#include "sensors.h"
#include "motors.h"
#include "driver_config.h"

static bool is_sensors_setup = false;
static bool is_motors_setup  = false;

void setup()
{
    if(!is_motors_setup)
    {
        motor_setup();
        is_motors_setup = true;
    }
    
    if(!is_sensors_setup)
    {
        ir_sensors_setup();
        is_sensors_setup = true;
    }

    if(is_motors_setup && is_ir_sensors_setup)
    {
        drivers_init();
    }
}

void loop()
{
  
}
