
#ifndef MOTORS_H
    #define MOTORS_H

    void init_motors(void (*l_motor_front_write_handler)(void), (void)(*l_motor_back_write_handler)(void), (void)(*r_motor_front_write_handler)(void), (void)(*r_motor_back_write_handler)(void));

#endif