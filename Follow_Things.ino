void Follow_Things(){
    if(command == 'Q'){
    distance = sonar.ping_cm();

    Right_Value = digitalRead(SensorRight);
    Left_Value = digitalRead(SensorLeft);
    
    Serial.print("SensorRight");
    Serial.print("SensorLeft");

if((distance>=1) && (distance<= 15)){
  //Move Forward
  motor1.setSpeed(130);
  motor1.run(FORWARD);
  motor2.setSpeed(130);
  motor2.run(FORWARD);
  
  }
  else if((Right_Value==0) && (Left_Value==1)) {
  //Turn Left
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
  delay(150);
  
  }
  else if((Right_Value==1)&&(Left_Value==0)) {
  //Turn Right
  motor1.setSpeed(100);
  motor1.run(BACKWARD);
  motor2.setSpeed(100);
  motor2.run(FORWARD);
  delay(150);
  
  
  }else if(distance > 15) {
  //Stop
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  }
  
}
Read_Data();
}
