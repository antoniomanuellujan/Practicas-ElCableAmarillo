
//pines-casa1---servo(servo1)=3, luz(luz1)=2, joystick(vrx)=A1, DavidyJoséRamón
//pines-casa2---servo(servo2)=5, luz(luz2)=4, joystick(vrx)=A1, JuanAntonioyRaul
//pines-casa3---servo(servo3)=6, luz(luz3)=7, trig(sr04)=9, echo(sr04)=8, AntonioNabil
//pines-casa4---servo(servo4)=10, luz(luz4)=12, trig(sr04)=9, echo(sr04)=8,

#include <Servo.h>

/*Variables de las casas controladas por joystick*/
int joystick;
Servo servo1;
int luz1=2;
Servo servo2;
int luz2=4;

/*Variables de la casa controlada por sr04*/
int echo=8;
int trig=9;
long distance;
long duration;
Servo servo3;
int luz3=7;
Servo servo4;
int luz4=12;



void setup() {
  
  Serial.begin(9600);
  /*COnfiguración de la casas controladas por joystick*/
  pinMode(A1,INPUT);
  servo1.attach(3);
  servo1.write(10); 
  pinMode(luz1,OUTPUT);
  digitalWrite(luz1,LOW);
  servo2.attach(5);
  servo2.write(10);
  pinMode(luz2,OUTPUT);
  digitalWrite(luz2,LOW);

  /*COnfiguración de la casas controladas por sr04*/
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo3.attach(6);
  servo3.write(10); 
  pinMode(luz3,OUTPUT);
  digitalWrite(luz3,LOW);
  servo4.attach(10);
  servo4.write(10); 
  pinMode(luz4,OUTPUT);
  digitalWrite(luz4,LOW);
  
 
}

void loop() {
 joystick=analogRead(A1);
 ultra();
 if(joystick <= 300) {
    casa1();
 }
  else if(joystick > 1000) {
    casa2();
  }
  else if(distance<=5){
   casa3();
  }
  else if(distance>5&&distance<=20){
    casa4();
  }
  else{
    nada();
  }
  

Serial.println(joystick);
//Serial.println(distance);

delay(100);

}

void ultra(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  }

void casa1(){
  servo1.write(280); 
  digitalWrite(luz1,HIGH);
  delay(5000); 
  servo1.write(100);
  digitalWrite(luz1,LOW);
  
  
}

void casa2(){
  servo2.write(10); 
  digitalWrite(luz2,HIGH);
  delay(5000); 
  servo2.write(100);
  digitalWrite(luz2,LOW);
  
}

void casa3(){
  servo3.write(10); 
  digitalWrite(luz3,HIGH);
  delay(5000); 
  servo3.write(100);
  digitalWrite(luz3,LOW);
}

void casa4(){
  servo4.write(10); 
  digitalWrite(luz4,HIGH);
  delay(5000); 
  servo4.write(100);
  digitalWrite(luz4,LOW);
  
}

void nada(){
  servo1.write(130); 
  digitalWrite(luz1,LOW);
  servo2.write(130);
  digitalWrite(luz2,LOW);
}
