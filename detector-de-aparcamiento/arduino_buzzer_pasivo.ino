/**
 * Detector de aparcamiento
 * 
 * @author Miguel Ángel Abellán
 * @modificado por Antonio Luján
 * @company Programo Ergo Sum
 * @license Creative Commons. Reconocimiento CompartirIgual 4.0
 */

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);

  //Inicialización  de los pines
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
}

//Este código se ejecuta en bucle repetidamente
void loop() {
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  long tiempo;
  tiempo = pulseIn(11, HIGH);

  // Velocidad Sonido = 343 m/s
  float distancia = 34300*tiempo*0.000001;
  distancia = distancia / 2;
  
  if(int(distancia)<30){ //avisa a menos de 30 cm
    if(int(distancia)<10){ //de continuo a menos de 10 cm
      tone(13, 400);
    }else{
      tone(13, 400);
      delay(50);
      noTone(13);
      delay(distancia*5);
    }
  }else{
    noTone(13);
  }
}