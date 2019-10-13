/**
 * Semáforo de peatones
 *
 * @author Miguel Ángel Abellán
 * @modificado por Antonio Luján
 * @company Programo Ergo Sum
 * @license Creative Commons. Reconocimiento CompartirIgual 4.0
 */

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13, LOW);
  
  digitalWrite(12, HIGH);
  for(int i=0; i<10; i++){
    tone(11, 440);
    delay(500);
    noTone(11);
    delay(500);
  }
  digitalWrite(12, LOW);
}