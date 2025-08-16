
#include "sensors.h"

int16_t values_sum;
static const uint8_t sensor_no = 5;
static int8_t const weights[sensor_no] = {-2,-1,0,1,2};
uint16_t sensor_values[sensor_no] = {0};
int16_t weighted_sum; 
static uint16_t thresholds[sensor_no] = {100, 100, 100, 100, 100}; // for an example.

static uint16_t (*get_sensor_values)(uint8_t sensor)   = NULL;

void ir_sensors_setup(uint16_t (*read_sensor_values_handler)(uint8_t sensor))
{
    get_sensor_values = read_sensor_values_handler;
}

//this is the order of sensors from left to right; one to five
void fill_sensor_value_array(void)
{
    for(uint8_t i=0; i<sensor_no; i++)
    {
        sensor_values[i] = get_sensor_values(i);
    }
}

float get_weighted_avg()
{
    values_sum = 0;
    weighted_sum = 0;

    fill_sensor_value_array();

    for(uint8_t i=0; i<sensor_no; i++)
    {
        if(sensor_values[i] > thresholds[i])
        {
            weighted_sum += weights[i] * sensor_values[i];  
            values_sum += sensor_values[i];
        }
    }

    if(values_sum == 0)
    {
        return 0.0; // Avoid division by zero
    }

    return (float)weighted_sum/values_sum;
}
