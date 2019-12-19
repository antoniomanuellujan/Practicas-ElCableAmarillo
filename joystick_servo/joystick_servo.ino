
#include <Servo.h>

Servo servo1;




void setup() {
  

 
  pinMode(A0,INPUT);
  servo1.attach(10);
  servo1.write(20); 
 
 
}

void loop() {

 if(analogRead(A0) <= 300) {
     servo1.write(150); 
 }


  else{
   servo1.write(20);
  }
  

delay(100);

}
