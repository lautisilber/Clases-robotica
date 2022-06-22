/*
* Introducción a electrónica
*   Saber de elecrtónica es tan importante como saber programar
* si se quiere hacer robótica. El mundo de la electrónica es
* infinito y súper interesante, pero vamos a empezar por el
* principio: prender y apagar un led. Para eso intriducimos la
* protoboard o breadboard. Es un elemento que nos permite crear
* circuitos rápida y fácilmente (imeagínense que antes de que
* existiera esto, para conectar dos componentes la única opción
* era soldar!). Cada columna (numerada con números del 1 al 30)
* está conectada entre sí y separada en el medio. Las filas de
* arriba y abajo (con - y +) están conectadas a lo largo. No se
* preocupen, es fácil entender esto una vez que empiezen a usarlas
*
* Ahora vamos a crear un circuito con un LED. Tal vez sepan que
* la electricidad (a corriente constante, que usamos en el Arduino)
* tiene un lado extremo positivo, que para el Arduino está a 5
* voltios y uno negativo que está a 0 voltios y se llama tierra.
* Para que un circuito esté conectado eléctricamente debbe tener un
* lado conectado a positivo y otro a negativo o tierra. Si uno de
* estos dos falta, no está bien conectado. 
*
* Para el LED usaremos uno de los pines (2) del Arduino como positivo
* y la tierra del mismo (GND). Conectaremos un LED que tiene una pata
* más larga que la otra. Esta va del lado positivo. Además conectaremos
* una resistencia (de 220 Ohm) para que no reviente todo. Por ahora no
* se preocupen por la resistencia. Estas son componentes súper utilizados
* en todo tipo de circuitos. En este caso la estamos usando para no crear
* un cortocircuito y que se prenda fuego todo (en una simulación no pasa
* nada, creo...), pero sepan que no pueden conectar un LED directamente o
* se va a quemar él o el Arduino. Además, se puede conocer cuan grande o
* chica es la resistencia con el código de color que en lo personal me
* parece muy divertido. Si quieren saber por qué exactamente necesitamos una
* resistencia pregúntenme en clase.
*/

// creamos una variable constante de tipo byte, que es como un int pero solo positivo y menor a 255, que represente el número de pin al que conectaremos el LED
const byte ledPin = 2;

void setup()
{
  // en setup llamamos a la función que provee Arduino llamada pinMode. Nos permite decirle a Arduino que vamos a utilizar el pin 2 como una salida (no como una entrada)
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // con la función de Arduino digitalWrite podemos decirle al Arduino que el el pin del LED, haya un voltaje positivo (5V) o voltaje 0 (tierra). Así podemos prender o apagar el LED. En vez de escribir HIGH podríamos haber escrito true o 1
  digitalWrite(ledPin, HIGH);
  
  // usamos otra función interna de Arduino que se llama delay que espera la cantidad de milisegundos que le pasemos: delay(1000); espera 1000 milisegundos que es igual a un segundo
  delay(1000);
  
  // apagamos el ping (lo igualamos a tierra)
  digitalWrite(ledPin, LOW);
  
  //esperamos nuevamente
  delay(1000);
}
