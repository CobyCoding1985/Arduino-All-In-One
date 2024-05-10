void Manual_Mode(){
 ////////ServoMotor 1////////////
 if (command == 'A') {
 if(ser[0] <= 175 ) {
 myservo1.write(ser[0]);
 ser[0]++;
 delay(retardo);
 }
 Read_Data();
 }
 else if(command == 'a') { 
 if(ser[0] >= 3 ) {
 myservo1.write(ser[0]);
 ser[0] --;
 delay(retardo);
 }
 Read_Data();
 }

 
 ////////ServoMotor 2////////////
 if(command == 'B') {
 if(ser[1] <= 150 ) {
 myservo2.write(ser[1]);
 ser[1]++;
 delay(retardo);
 }
 Read_Data();
 }
 else if(command == 'b') {
 if(ser[1] >= 70 ) {
 myservo2.write(ser[1]);
 ser[1] --;
 delay(retardo);
 }
 Read_Data();
 }
}
