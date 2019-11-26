
#include <Servo.h>

Servo myservo1;
Servo myservo2;// create servo object to control a servo
Servo myservo3;
Servo myservo4;

void setup() {
  
  myservo1.attach(10);
  myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(11);
  myservo4.attach(2);
}

void loop() {
ser1();
ser2();
ser3();
ser4();
}

void ser1(){
  myservo1.write(10);                  // sets the servo position according to the scaled value
  delay(5000); 
 
  myservo1.write(90);                  // sets the servo position according to the scaled value
  delay(5000);
}

void ser2(){
  myservo2.write(10);                  // sets the servo position according to the scaled value
  delay(5000); 
 
  myservo2.write(90);                  // sets the servo position according to the scaled value
  delay(5000);
}

void ser3(){
  myservo3.write(10);                  // sets the servo position according to the scaled value
  delay(5000); 
 
  myservo3.write(90);                  // sets the servo position according to the scaled value
  delay(5000);
}

void ser4(){
  myservo4.write(10);                  // sets the servo position according to the scaled value
  delay(5000); 
 
  myservo4.write(90);                  // sets the servo position according to the scaled value
  delay(5000);
}
