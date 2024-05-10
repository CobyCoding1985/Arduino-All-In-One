void Bluetooth_Connection(){
  if(command == 'F'){
    Forward();
    Read_Data();
  }
  if(command == 'G'){
    Backward();
    Read_Data();
  }
  if(command == 'H'){
    Left();
    Read_Data();
  }
  if(command == 'I'){
    Right();
    Read_Data();
  }
  if(command == 'E'){
    ForwardLeft();
    Read_Data();
  }
  if(command = 'O'){
    ForwardRight();
    Read_Data();
  }
  if(command == 'M'){
    BackLeft();
    Read_Data();
  }
  if(command == 'N'){
    BackRight();
    Read_Data();
  }
  if(command == 'P'){
    Stop();
    Read_Data();
  }
} 


void Forward(){
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD); 
}

void Backward(){
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
}

void Left(){
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD); 
}


void Right(){
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
}

void Stop(){
  motor1.setSpeed(0); 
  motor1.run(RELEASE);
  motor2.setSpeed(0); 
  motor2.run(RELEASE);
}

void ForwardLeft(){
  motor1.setSpeed(0); 
  motor1.run(RELEASE);
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
}

void ForwardRight(){
  motor1.setSpeed(255); 
  motor1.run(FORWARD);
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
}

void BackLeft(){
  motor1.setSpeed(0); 
  motor1.run(RELEASE);
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
}

void BackRight(){
  motor1.setSpeed(255); 
  motor1.run(BACKWARD);
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
}
