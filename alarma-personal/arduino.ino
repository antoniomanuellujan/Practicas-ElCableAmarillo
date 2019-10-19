void setup(){
    pinMode(7, OUTPUT);
    pinMode(3, OUTPUT);
}

void loop(){
    if(digitalRead(4)){ //si no es LOW
        if(digitalRead(8)){
            calma();
        }
        else{
            alarma();
        }
        
    }
}
void calma(){
    digitalWrite(7,HIGH);
    delay(200);
    digitalWrite(7,LOW);
    delay(1000);
    }

void alarma(){
    delay(3000);
    for (int i = 0; i < 10; i++){
    digitalWrite(7,HIGH);
    tone(3, 400);
    delay(200);
    digitalWrite(7,LOW);
    noTone(3);
    delay(200);
}
}
