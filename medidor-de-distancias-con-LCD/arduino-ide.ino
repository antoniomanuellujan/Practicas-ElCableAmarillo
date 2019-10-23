#include 'LiquidCrystal.h' //Please replace the single quote characters ('') with the parenthesis character (<>)

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Crea un LCD con parámetros (rs, enable, d4, d5, d6, d7)

const int trig = 9; //Conectamos pin 9 del arduino al trig del HC-SR04
const int echo = 10; //Conectamos pin 10 del arduino al echo del HC-SR04
long tiempo; // Creamos variable tiempo 
int distancia; // Creamos variable distancia

void setup() {
  
lcd.begin(16,2); //Iniciamos conexión con LCD de 16 columnas por 2 filas
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

}

void loop() {
  
digitalWrite(trig, LOW); //Emitimos pulsos desde trig
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

duracion = pulseIn(echo, HIGH); //tiempo que echo que tarda en recibir pulso
distancia= duracion*0.034/2; //calculamos distancia en cm con tiempo y velocidad del sonido

lcd.setCursor(0,0); // Configura la posición donde se empezará a escribir
lcd.print("El objeto está a: "); // Imprimimos la cadena que queramos en la primera fila
delay(10);
lcd.setCursor(0,1); //Empezamos a imprimir en segunda fila
lcd.print(distancia); // Imprimimos valor variable distancia
lcd.print("  cm"); //Imprimimos cm
delay(10);

}
