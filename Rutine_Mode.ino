void Rutine_Mode(){
 if(command == '0'){ 
 Read_Data(); 
 if(num_rut < 12 ){ 
 if(command == 'X'){ 
 ser_rut[0][num_rut] = ser[0]; 
 }
 else if(command == 'Y'){ 
 ser_rut[1][num_rut] = ser[1];
 }
 num_rut ++;
 }
 }
 else if(command == 'K') { 
 num_rut = 0;
 while(num_rut < 12 && command == 'K'){ 

 
 // movimientos almacenados para el servomotor 1
 if(ser_rut[0][num_rut] > 0) {
 if(ser[0] <= ser_rut[0][num_rut]) {
 while(ser_rut[0][num_rut] >= ser[0]) { 
 myservo1.write(ser[0]);
 ser[0]++;
 delay(retardo);
 }
 delay(500);
 }
 else {
 while(ser_rut[0][num_rut] <= ser[0]) { 
 myservo1.write(ser[0]);
 ser[0]--;
 delay(retardo);
 }
 delay(500);
 }
 }

 
 //Instrucciones para ejecutar los movimientos almacenados para el servomotor 2
 else if(ser_rut[1][num_rut] > 0) {
 if(ser[1] <= ser_rut[1][num_rut]) {
 while(ser_rut[1][num_rut] >= ser[1]) {
 myservo2.write(ser[1]);
 ser[1]++;
 delay(retardo);
 }
 delay(500);
 }
 else {
 while(ser_rut[1][num_rut] <= ser[1]) { 
 myservo2.write(ser[1]);
 ser[1] --;
 delay(retardo);
 }
 delay(500);
 }
 }
num_rut++;
 Read_Data();
 }
 }
 
 else if(command == 'S') { //Cuando el valor es 'S' significa la eliminación de la rutina
 for(int i=0;i<2;i++) { //Proceso FOR para limpiar la matriz de donde se almacenan
 //las rutinas.
 for(int j=0;j<12;j++) {
 ser_rut[i][j] = - 1;
 Serial.println(ser_rut[i][j]);
 }
 }
 num_rut = 0;
 }
}
