int a=3;
int b=4;
int c=5;
int d=6;
int e=7;
int f=8;
int g=9;

void setup(){
//Configurar salidas de los leds
   pinMode (a, OUTPUT);
   pinMode (b, OUTPUT);
   pinMode (c, OUTPUT);
   pinMode (d, OUTPUT);
   pinMode (e, OUTPUT);
   pinMode (f, OUTPUT);
   pinMode (g, OUTPUT);    
      
   //Configurar la salida del buzzer
   pinMode (11, OUTPUT);  
  
   //Configurar el pin de entrada del pulsador
   pinMode (2, INPUT);
    
   //Inicializa el generador de números aleatorios
   randomSeed(analogRead(0));  
    
   //Apaga todos los leds
   digitalWrite (a, LOW);
   digitalWrite (b, LOW);
   digitalWrite (c, LOW);
   digitalWrite (d, LOW);
   digitalWrite (e, LOW);
   digitalWrite (f, LOW);
   digitalWrite (g, LOW);  
  
   //Buzzer a 0
   digitalWrite (11, LOW);
 
}
 
void beep () {
 
    digitalWrite (11, HIGH);
    delay (20);
    digitalWrite (11, LOW);
 
}
 
 
void escribe_dado (unsigned char num) {
  //Escribe numero en el dado
  switch (num) {
            
    case 1: //Encender el número 1
            digitalWrite (a, LOW);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, LOW);
            digitalWrite (e, LOW);
            digitalWrite (f, LOW);
            digitalWrite (g, LOW);         
            break;
            
    case 2: //Encender el número 2
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, LOW);
            digitalWrite (d, HIGH);
            digitalWrite (e, HIGH);
            digitalWrite (f, LOW);
            digitalWrite (g, HIGH);              
            break;
            
    case 3: //Encender el número 3
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, LOW);
            digitalWrite (f, LOW);
            digitalWrite (g, HIGH);  
            break;
            
    case 4: //Encender el número 4
            digitalWrite (a, LOW);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, LOW);
            digitalWrite (e, LOW);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);  
            break;
            
    case 5: //Encender el número 5
            digitalWrite (a, HIGH);
            digitalWrite (b, LOW);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, LOW);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);  
            break;
            
    case 6: //Encender el número 6
            digitalWrite (a, HIGH);
            digitalWrite (b, LOW);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, HIGH);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);
            break;
        
    default:
    case 0:  //Apagar todos los leds
            digitalWrite (a, LOW);
            digitalWrite (b, LOW);
            digitalWrite (c, LOW);
            digitalWrite (d, LOW);
            digitalWrite (e, LOW);
            digitalWrite (f, LOW);
            digitalWrite (g, LOW);
            break;
            
  }
  
 
}
 
 
void loop () {
  
  unsigned int numero;
  
  while (!digitalRead (2));   //Espera a que aprieten pulsador
 
  escribe_dado (0);              //Apaga todos los leds
  
  while (digitalRead (2));      //Espera a que suelten pulsador
  
  beep ();
  
  numero = random(1, 7);        //Genera un numero al azar entre 1 y 6
  
  escribe_dado (numero);        //Mostrar el numero en el dado
 
}
