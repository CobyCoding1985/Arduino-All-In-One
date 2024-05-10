void Line_Follower(){
  if(command == 'L'){
  LsensorU = digitalRead(SensorLeft);
  LsensorD = digitalRead(SensorRight);

  if (LsensorU == 0 && LsensorD == 0) {
    Avanza();
  }
  if (LsensorU == 1 && LsensorD == 0) {
    Derecha();
  }
  if (LsensorU == 0 && LsensorD == 1) {
    Izquierda();
  }
}
Read_Data();
}

void Avanza() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
 }

void Izquierda() {
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void Derecha(){
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
