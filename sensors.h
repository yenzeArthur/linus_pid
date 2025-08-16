
#ifndef SENSORS_H
    #define SENSORS_H

    void ir_sensors_setup(float (*read_sensor_values_handler)(uint8_t sensor));
    void fill_sensor_value_array(void);
    float get_weighted_avg();

#endif