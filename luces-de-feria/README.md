# Descripción



## Materiales



## Esquema eléctrico



## Programación en Arduino

void setup(){
    pinMode(A0, INPUT);
    Serial.begin(9600);
  }
 void loop(){
 //Se hace la lectura analoga del pin A0 (sensor) y se pasa por la funcion map() para ajustar los valores leidos a los porcentajes que queremos utilizar   
int valorHumedad = map(analogRead(A0), 0, 1023, 100, 0);
Serial.print("Humedad: ");
Serial.print(valorHumedad);
Serial.println("%"); 
delay(100);
  }

## Ayuda
https://irisfernandez.com.ar/betaweblog/index.php/2019/11/03/sensor-de-humedad-para-tierra-hw-080/