void Object_Avoiding(){
  if (command == 'T') {
  myservo1.attach(10);  
  myservo1.write(115);

  myservo2.attach(9);
  myservo2.write(120);
  
  int distanceR = 0;
  int distanceL = 0;
  delay(40);

 if(distance<=15){
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL){
    turnRight();
    moveStop();
  }else {
    turnLeft();
    moveStop();
  }
 } else {
  moveForward();
 }
 distance = ReadPing();
}
Read_Data();
}


int lookRight(){
    myservo1.write(50); 
    delay(500);
    int distance = ReadPing();
    delay(100);
    myservo1.write(120); 
    return distance;
}

int lookLeft(){
    myservo1.write(200); 
    delay(500);
    int distance = ReadPing();
    delay(100);
    myservo1.write(120); 
    return distance;
    delay(100);
}


void moveStop(){
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
} 

  
void moveForward(){
 if(!goesForward){
    goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2){
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    delay(5);
   }
  }
}

void moveBackward(){
    goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
 
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2){
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    delay(5);
  }
}  


void turnRight(){
  motor1.run(FORWARD);
  motor2.run(BACKWARD); 
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);    
} 
 
void turnLeft(){
  motor1.run(BACKWARD);     
  motor2.run(FORWARD);  
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
}  
