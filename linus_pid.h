
#ifndef LINUS_PID_H
    #define LINUS_PID_H

    typedef enum LINUS_ROBOT_STATES{
      INIT,
      MOVE,
      STOP,
      ERROR
    }LINUS_ROBOT_STATES;

    const int threshold = 200; // to be determined and changed

    int ir_sensor[] = {A0,A1,A2,A3,A4};
    int sensor_position[] = {-2,-1,0,1,2};

    int rmf = 9;
    int rmb = 6;
    int lmf = 10; 
    int lmb = 11;

    int rspeed;
    int lspeed;
    const int base_speed = 255;

    int current_position;
    int set_point_position;

    int p;
    int i;
    int d;

    int lp;
    int error;
    int correction_value;

    int Kp = 5; 
    int Kd = 40;
    int Ki = 0; 

    int button = 3;

    int cal_avg();
    void robot_stop(void);
    void motor_setup(void);
    void find_set_point(void);
    void robot_turn_left(void);
    void robot_turn_right(void);
    int calc_correction_value();
    void robot_move_forward(void);

#endif 