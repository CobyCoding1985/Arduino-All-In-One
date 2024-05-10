void Voice_Follower(){
  if(command == 'R'){
  while (Serial.available()){ 
     delay(10); 
    char c = Serial.read(); 
    if (c == '#') {break;} 
    voice += c; 
  }
  if (voice.length() > 0){
    if(voice == "*forward"){
      forward_car();
      }
    else if(voice == "*backward"){
      back_car();
      }
    else if(voice == "*turn right") {
      right_car();
    }
    else if(voice == "*turn left") {
      left_car();
    }
    else if(voice == "*stop car") {
      stop_car();
    }
    
  voice=""; 
  }
}
Read_Data();
}


void forward_car(){
  motor1.run(FORWARD);
  motor1.setSpeed(255);
  motor2.run(FORWARD);
  motor2.setSpeed(255);
  delay(2000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
  
void back_car(){
  motor1.run(BACKWARD);
  motor1.setSpeed(255);
  motor2.run(BACKWARD);
  motor2.setSpeed(255);
  delay(2000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
  
void right_car(){
  myservo1.write(0);
  delay(1000);
  myservo1.write(120);
  delay(1000);
  motor1.run(FORWARD);
  motor1.setSpeed(255);
  motor2.run(BACKWARD);
  motor2.setSpeed(255);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
  
void left_car(){
  myservo1.write(180);
  delay(1000);
  myservo1.write(120);
  delay(1000);
  motor1.run(BACKWARD);
  motor1.setSpeed(255);
  motor2.run(FORWARD);
  motor2.setSpeed(255);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void stop_car(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
