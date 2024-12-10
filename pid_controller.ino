
#include "linus_pid.h"

typedef enum SET_POINT_STATES{
  D_INIT,
  FIND_SET_POINT,
  D_ERROR
}SET_POINT_STATES;

SET_POINT_STATES current_set_point_state;

int sensor_value;
int sensor_value_sum;
int standardised_value;


void find_set_point(){

  current_set_point_state = D_INIT;

  switch(current_set_point_state){
    case D_INIT:
      if((digitalRead(button))==HIGH){
        current_set_point_state = FIND_SET_POINT;
      }
      else{
        Serial.println("Something is wrong with that button, Check button!");
        current_set_point_state = D_ERROR;
      }
    break;

    case FIND_SET_POINT:
      set_point_position = cal_avg();
      if(set_point_position < 0){
        Serial.println("set point value: ");
        Serial.print(set_point_position);
        current_set_point_state = D_INIT;
      }
      else{
        Serial.println("Set point value is NULL, press button to retry! or check code!");
        current_set_point_state = D_ERROR;
      }
    break;

    case D_ERROR:
      running_linus_robot_state = ERROR;
    break;

    default:
      Serial.println("You have unlocked a new unknown state! Phenomenal!");
    break;
  }
}

int cal_avg(){
  standardised_value = 0;
  sensor_value_sum = 0;
  for(int i=0; i<5; i++){
        sensor_value = analogRead(ir_sensor[i]);
        standardised_value += sensor_value * sensor_position[i] * 1000;
        sensor_value_sum += sensor_value;
      }

      int avg = standardised_value/sensor_value_sum;
      return avg;
}

int calc_correction_value(){
  unsigned long elapsed_time, current_time = millis();
  elapsed_time = millis() - current_time; 
  error = set_point_position - current_position;

  p = error;
  i += error * elapsed_time;
  d = (p - lp) * elapsed_time;

  lp = p;
  current_time = millis();
  return((Kp*p) + (Ki*i) + (Kd*d));
}