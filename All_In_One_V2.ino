#include "AFMotor.h"
#include <Servo.h>         
#include <NewPing.h>
#include <IRremote.h>

#define SensorLeft A1
#define IRPin A2
#define SensorRight A3

#define ECHO_PIN A4
#define TRIG_PIN A5 

#define MAX_DISTANCE 200 
#define MAX_SPEED 190 
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo1;
Servo myservo2;   

AF_DCMotor motor1(1, MOTOR34_64KHZ); 
AF_DCMotor motor2(4, MOTOR34_64KHZ);

char command;

byte LsensorU;
byte LsensorD;

boolean goesForward=false;
unsigned int distance = 0;

unsigned int Right_Value = 0;
unsigned int Left_Value = 0;  

IRrecv receiver(IRPin);
decode_results results;

int speedSet = 0;

int num_rut = 0;
int retardo = 3; 
int cont = 0;
char dato;
int ser[4] = {90,90,90,90};
int ser_rut[4][12];

String voice;

void setup() {
  pinMode (SensorLeft, INPUT);
  pinMode (SensorRight, INPUT); 

  myservo1.attach(10);  
  myservo1.write(120);

  myservo2.attach(9);
  myservo2.write(70);
  
  delay(20);
  distance = ReadPing();
  delay(10);
 
  distance = ReadPing();
  delay(10);
  
  distance = ReadPing();
  delay(10);
  
  distance = ReadPing();
  delay(10);

  receiver.enableIRIn();
  Serial.begin(9600);
}

void Read_Data(){
  if(Serial.available()>1){
    command = Serial.read();
    delay(30);
    command = Serial.read();
  }
}

int ReadPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}


void loop() {  
  Read_Data();
  
  Line_Follower();
  
  Object_Avoiding();
  
  Voice_Follower();
  
  Follow_Things();
  
  Bluetooth_Connection();

  Manual_Mode();

  Rutine_Mode();

  Infrared_Control();
}
