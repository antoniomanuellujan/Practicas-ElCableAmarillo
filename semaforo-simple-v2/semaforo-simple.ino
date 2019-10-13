void setup () {
pinMode(9,OUTPUT);// LED Rojo
pinMode(5,OUTPUT);// LED Amarillo
pinMode(0,OUTPUT);// LED Verde
}

void loop () {
  digitalWrite(9,HIGH);//Enciendo Rojo
  delay(5000);//Queda encendido 2 segundos
  digitalWrite(9,LOW);//Apago Rojo
  
  digitalWrite(0,HIGH);//Enciendo Verde
  delay(5000);//Queda encendido 2 segundos
  digitalWrite(0,LOW);//Apago Verde
  
  digitalWrite(5,HIGH);//Enciendo Ámbar
  delay(1000);//Queda encendido 1 segundo
  digitalWrite(5,LOW);//Apago Rojo
}
