# Medidor de ruido con Arduino y Raspberry 

Utilizaremos una tarjeta de Arduino para leer la señal analógica del micrófono y con un programa en Arduino activaremos un RGB que mostrará diferentes colores en función del ruido.
La función de la Raspberry Pi es comunicarse con la tarjeta arduino y generar un archivo en una hoja de cálculo para registrar la información.
Se podrá acceder a la información remotamente utilizando el escritorio virtual del al Raspberry Py.
La mayor dificultad ha sido poder hacer una lectura correcta de la entrada analógica. El micrófono utilizado KY-037 ofrece una señal analógica que no se corresponde con las variaciones del volumen del ruido. En la siguiente dirección web se indica como se soluciona este problema:
https://www.luisllamas.es/medir-sonido-con-arduino-y-microfono-amplificado-max9812/

## Materiales

- 1 Placa de Arduino
- 1 Placa Raspberry Pi
- Micrófono KY-037
- 1 Placa con RGB



![](Arduino_Raspberry.jpg)
![](Arduino_RGB_KY037.jpg)

En el siguiente GIF se puede visualizar el funcionamiento pero a no tener audio no se puede apreciar los cambios de color del RGB con en nivel sonoro. En el siguiente enlace pueden ver el video con audio.

[VER VIDEO](full-URL-of-wiki-page)
![](Medidor_sonido.gif)

En la siguiente imagen tenemos un captura de la tabla de datos obtenida con el programa en Python en la Raspberry Pi y con la ayuda de la hoja de cálculo se ha creado una gráfica.
![](Datos_Gráfica.png)


```arduino
// Código Arduino
const int sensorPIN = A0;
const int sampleWindow = 50; // Ancho ventana en mS (50 mS = 20Hz)
 
void setup() 
{
   Serial.begin(9600);
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);

}
 
void loop() 
{
   unsigned long startMillis= millis();
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // Recopilar durante la ventana
   unsigned int sample;
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(sensorPIN);
      if (sample < 1024)
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // Actualizar máximo
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // Actualizar mínimo
         }
      }
   }
   unsigned int peakToPeak = signalMax - signalMin;  // Amplitud del sonido
   int volts = peakToPeak;  // Convertir a tensión
   Serial.println(volts);

         if((volts) < (20)){
        digitalWrite(13,1);
        digitalWrite(12,0);
        digitalWrite(11,0);
    }
    
    if((volts) > (20)){
        if((volts) < (51)){
            digitalWrite(13,0);
            digitalWrite(12,1);
            digitalWrite(11,0);
        }
    }


    
    if((volts) > (51)){
        digitalWrite(13,0);
        digitalWrite(12,0);
        digitalWrite(11,1);
    }
    delay(1000);

}
```


```python
#Código Python
import serial, time
from time import strftime
 
arduino = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    cadena = arduino.readline()

    if(cadena.decode() != ''):
        cadena = str(cadena.decode())
       
        with open("/home/pi/Desktop/volumen.csv", "a") as log:
            log.write("{0},{1}".format(strftime("%Y-%m-%d %H:%M:%S"), cadena))

    time.sleep(1)

arduino.close()

```
