
#include "linus_pid.h"

LINUS_ROBOT_STATES running_linus_robot_state;

void setup(){

  Serial.begin(9600);

  for(int i=0; i<5; i++){
    pinMode(ir_sensor[i], INPUT);
  }

  motor_setup();
  pinMode(button, INPUT);
  find_set_point();
  delay(200);

}

void loop(){
  i = 0;
  current_position = 0;
  running_linus_robot_state = INIT;
  robot_move_forward();

  switch(running_linus_robot_state){
    case INIT:
      current_position = cal_avg();
      correction_value = calc_correction_value();
      running_linus_robot_state = MOVE; 
    break;

    case MOVE:
      if(current_position == set_point_position){
        robot_move_forward();
      }
      else if(correction_value < 0){
        get_turning_speeds();
        robot_turn_left();
      }
      else if(correction_value > 0){
        get_turning_speeds();
        robot_turn_right();
      }
      else if(!no_line()){
        Serial.println("Robot is in a stop position");
        running_linus_robot_state = STOP;
      }
      else if(no_line()){
        Serial.println("robot is in a white area, no where to go!");
        running_linus_robot_state = STOP;
      }
    break;

    case STOP:
      robot_stop();
      running_linus_robot_state = INIT;
    break;

    case ERROR:
      Serial.println("Check the set point value");
    break;

    default:
      Serial.println("You have unlocked a new unknown state! Phenomenal!");
    break;
  }
}

bool no_line(){
  for(int i=0; i<5; i++){
    if(analogRead(ir_sensor[i]) > threshold){
      return false;
    }
  }
  return true;
}