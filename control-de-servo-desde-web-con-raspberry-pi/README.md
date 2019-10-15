# Control remoto desde web de un servo con raspberry pi.

El objetivo de esta práctica es diseñar un control de un servo vía web, a través de internet por medio de una raspberry pi (en nuestro caso versión 3+). Se trata de un concepto similar al que ser realiza en domótica o IoT. 

## Materiales
..* Raspberry pi.
..* Servo SG90.
..* Protoboard.
..* Cables de conexionado.

Para el diseño se ha ralizado un entorno web sencillo, marcado por 11 botones que van desde el 0% al 100% de las posibilidades del servo. 
Al tratarse del modelo de servo SG90 [(Ficha Técnica)](../control-de-servo-desde-web-con-raspberry-pi/sg90_datasheet.pdf). El rango de giro va desde -90º hasta +90º (Un rango total de 180º). Por lo que cada escalón viene a correlacionarse con 18º.


![PRÁCTICA DE CONTROL DE SERVO DESDE WEB CON RASPBERRY PI](../control-de-servo-desde-web-con-raspberry-pi/servoweb.jpg "PRÁCTICA DE CONTROL DE SERVO DESDE WEB CON RASPBERRY PI")



