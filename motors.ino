
#include "motors.h"

static void (*l_motor_front_write)(void)  = NULL;
static void (*l_motor_back_write)(void)   = NULL;
static void (*r_motor_front_write)(void)  = NULL;
static void (*r_motor_back_write)(void)   = NULL;

void init_motors(void (*l_motor_front_write_handler)(void), (void)(*l_motor_back_write_handler)(void), (void)(*r_motor_front_write_handler)(void), (void)(*r_motor_back_write_handler)(void))
{ 
    l_motor_front_write = l_motor_front_write_handler;
    l_motor_back_write  = l_motor_back_write_handler;
    r_motor_front_write = r_motor_front_write_handler;
    r_motor_back_write  = r_motor_back_write_handler;
}

