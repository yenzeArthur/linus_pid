
#ifndef DRIVERS_H
    #define DRIVERS_H

    uint8_t rside_motor_front = 9;
    uint8_t rside_motor_back = 6;
    uint8_t lside_motor_front = 10; 
    uint8_t lside_motor_back = 11;

    uint8_t ir_sensors[5] = {A0, A1, A2, A3, A4};

    void motor_setup(void);
    void sensors_setup(void);
    
#endif