void Infrared_Control(){
    if(command == 'U'){
    if (receiver.decode(&results)){
    Serial.println(results.value);
    delay(5);
    receiver.resume();
  }
  
  /* if the incoming data is "defined hex code" then run the motors functions */
  /* instead of zeros "0000", write the hex codes of your remote control */
  if(results.value == 0000) MotorForward();
  if(results.value == 0000) MotorBackward();
  if(results.value == 0000) TurnRight();
  if(results.value == 0000) TurnLeft();
  if(results.value == 0000) MotorStop();
    }
 }

 
void MotorForward(){
  motor1.setSpeed(130);
  motor1.run(FORWARD);
  motor2.setSpeed(130);
  motor2.run(FORWARD);
}


void MotorBackward(){
  motor1.setSpeed(130); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(130); 
  motor2.run(BACKWARD);
}

void TurnRight(){
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
  delay(150);
}

void TurnLeft(){
 motor1.setSpeed(150);
  motor1.run(BACKWARD);
  motor2.setSpeed(150);
  motor2.run(FORWARD);
  delay(150);

}

void MotorStop(){
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}
