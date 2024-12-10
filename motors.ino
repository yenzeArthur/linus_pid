
void motor_setup(){
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
}

void robot_move_forward(){
  analogWrite(rmf, base_speed);
  analogWrite(lmf, base_speed);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

void robot_turn_left(int left_speed, int right_speed){
  analogWrite(lmb, abs(left_speed));
  analogWrite(rmf, abs(right_speed));
  analogWrite(rmb, 0);
  analogWrite(lmf, 0);
}

void robot_turn_right(int left_speed, int right_speed){
  analogWrite(lmf, abs(left_speed));
  analogWrite(rmb, abs(right_speed));
  analogWrite(rmf, 0);
  analogWrite(lmb, 0);
}

void get_turning_speeds(){
  correction_value = map(correction_value, -2, 2, -255, 255);
  rspeed = base_speed + correction_value;
  lspeed = base_speed - correction_value;
}

void robot_stop(){
  analogWrite(rmf, 0);
  analogWrite(lmf, 0);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}