# Medidor de distancia con Raspberry Pi con fichero .csv

## Descripción

Se trata de capturar los datos de la distancia a un objeto al sensor de ultrasonidos HC-SR04 registrados por una placa Arduino

![](captura.png) 
![](Montaje.jpg) 

## Materiales

- uyhndfxuhg
- fdgdfgcf

```arduino


```

```python
import serial, time
from time import strftime

arduino = serial.Serial('/dev/ttyACM0', 9600)

while True:
    cadena = arduino.readline()
  
    if(cadena.decode() != ''):
        cadena = str(cadena.decode())
                       
        with open("/home/pi/Desktop/registro_HCSR04.csv", "a") as log:
            log.write("Fecha {0}, Distancia {1}\n".format(strftime("%Y-%m-%d %H:%M:%S"), cadena))
        
        #print(cadena.decode())
  
    time.sleep(0.1)

arduino.close()
```
