
#ifndef DRIVER_CONFIG_H
    #define DRIVER_CONFIG_H

    void drivers_init(void);
    void write_rside_motor_front(uint8_t state);
    void write_lside_motor_front(uint8_t state);
    void write_rside_motor_back(uint8_t state);
    void write_lside_motor_back(uint8_t state);
    float read_sensor_value(void);

#endif 