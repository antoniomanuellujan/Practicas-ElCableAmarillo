      
void setup()
{
  pinMode(2, INPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
}


void loop()
{

    if ((digitalRead(2) == true)) {
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      delay(1000);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      delay(3000);

    } else {
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);

    }

}
  
    
