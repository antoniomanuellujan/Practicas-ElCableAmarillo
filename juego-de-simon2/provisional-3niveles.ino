      
double i;

void fnc_dynamic_digitalWrite(int _pin, int _e){
  pinMode(_pin,OUTPUT);
  digitalWrite(_pin,_e);
}

void gan_C3_A9() {
  for (int count = 0; count < 10; count++) {
    for (i = 13; i >= 11; i=i-1) {
      fnc_dynamic_digitalWrite(i, HIGH);
      delay(200);
      fnc_dynamic_digitalWrite(i, LOW);
    }
    for (i = 11; i <= 13; i=i+1) {
      fnc_dynamic_digitalWrite(i, HIGH);
      delay(200);
      fnc_dynamic_digitalWrite(i, LOW);
    }
  }
}

void hola() {
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(3000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(2000);
  nivel1();
}

void nivel1() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  while(!(((((digitalRead(2) || ((digitalRead(3) || digitalRead(4))))) == true))));
  if ((digitalRead(2) == true)) {
    digitalWrite(7, HIGH);
    delay(2000);
    digitalWrite(7, LOW);
    nivel2();

  } else {
    fin();

  }
}

void fin() {
  digitalWrite(6, HIGH);
  delay(2000);
  digitalWrite(6, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  while(true);
}

void nivel3() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  while(!(((((digitalRead(2) || ((digitalRead(3) || digitalRead(4))))) == true))));
  if ((digitalRead(2) == true)) {
    while(!(((digitalRead(2) == false))));
    while(!(((((digitalRead(2) || ((digitalRead(3) || digitalRead(4))))) == true))));
    if ((digitalRead(2) == true)) {
      while(!(((digitalRead(2) == false))));
      while(!(((((digitalRead(2) || ((digitalRead(3) || digitalRead(4))))) == true))));
      if ((digitalRead(3) == true)) {
        while(!(((digitalRead(3) == false))));
        digitalWrite(7, HIGH);
        delay(2000);
        digitalWrite(7, LOW);
        gan_C3_A9();

      } else {
        fin();

      }

    } else {
      fin();

    }

  } else {
    fin();

  }
}

void nivel2() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  while(!(((((digitalRead(2) || ((digitalRead(3) || digitalRead(4))))) == true))));
  if ((digitalRead(2) == true)) {
    while(!(((digitalRead(2) == false))));
    while(!(((((digitalRead(2) || ((digitalRead(3) || digitalRead(4))))) == true))));
    if ((digitalRead(3) == true)) {
      digitalWrite(7, HIGH);
      delay(2000);
      digitalWrite(7, LOW);
      nivel3();

    } else {
      fin();

    }

  } else {
    fin();

  }
}

void setup()
{
  pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
  hola();

}


void loop()
{


}
  
