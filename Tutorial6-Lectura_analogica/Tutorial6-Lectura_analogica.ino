/*
*  Lectura Analógica
*   Como habíamos hablado, los circuitos pueden
*   ser digitales o analógicos. También dijimos
*   que lo analógico traīa sus complicaciones. Es
*   hora de ver esas complicaciones! Los microcontroladores,
*   como el Arduino, o una omputadora de escritorio,
*   son artefactos digitales. Todas las señales que
*   envían y reciben son de sí o de no. Esto tiene un montón
*   de ventajas para la informática, pero hacce que no se
*   lleven bien con señales analógicas. Voy a ponerme un
*   poco técnico para le que quiera ver un poco más en detalle
*   como se juntan los mundos analógico y digital, pero no
*   hace falta que comprendan todo, es sólo para que no hayan
*   dudas y porque me parece sumamente interesante :) (el comentario
*   lo dejo al final del código).
*
*   Para realizar una lectura analógica utilizamos ADC (analog-digital converter)
*   que convierten la señal analógica en digital para que el micropro-
*   cesador pueda leer. El Arduino tiene ADC en los pines A0 hasta A5.
*
*   El circuito consta únicamente de un potenciómetro. En rigor es
*   una resistenia variable pero piénsenlo como un grifo. Si está abierto
*   deja pasar toda el agua (voltaje), si está cerrado no deja pasar nada
*   Cuando esté 100% abierto, leeremos +5V, o sea un sí digital. Cuando
*   esté cerrado completamente leeremos un no digital. Pero cuando esté
*   en el medio, leeremos un valor intermedio, que no es digital
*
*   Voy a hacer una aclacarción sobre los ADC. Estos tienen una cierta defincición
*   que se mide en bits. Esta definicion se debe a que tienen que convertir una señal
*   analógica en digital. la función analogRead(pin) devuelve un valor entero que
*   es como máximo, el valor máximo que se puede escribir con esa cantidad de bits
*   (la cantidad de bits de la resolución del ADC) y como mínimo será 0. Por ejemplo,
*   si la resolución del ADC es de 10 bits, con 10 bits yo puedo máximo escribir el número
*   1023 (1111111111). Por lo que cuando el ADC esté midiendo lo máximo que puede, la función
*   analogRead(pin) devolverá 1023. Si dividimos el valor por 1023,
*   obtenemos un valor en porcentaje!
*/

const byte adcPin = A0;
const int maxADC = 1023;
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(adcPin, INPUT);
}

void loop()
{
  int value = analogRead(adcPin); // realizamos la lectura analógica del pin, que devuelve un número en vez de un bool
  Serial.print("Valor analogico: ");
  Serial.print(value);
  Serial.print(" - Valor porcentaje: ");
  Serial.println((float)value / (float)maxADC); // cuando uno escribe (tipo)variable, lo que hace uno es hacer un casting. estar transformando un tipo de variable en otro. Debemos hacer esto porque hasta ahora teníamos todos los datos guardados como números enteros int, pero queremos un número con coma float
  delay(10);
}

/*

Nota sobre analógico-digital, representación en bits y ADCs

El problema aparece en la representación de valores numéricos. Las computadoras representan los 
números en bits (unos y ceros, bien digital). Si quiero escribir el número 4 en binario puedo decir 100, si 
quiero decir 7 puedo escribir en binario 111. Ahora, si quiero escribir 8, necesito un bit más y 8 en binario se 
escribe 1000. Quiero remarcar que para escribir 7 sólo se necesitaron 3 bits (111) y para escribir 8 se 
necesitaron 4 (1000). Qué pasa si quiero representar 145? Necesito 10 bits (10010001). Lo que quiero decir 
es que no se puede representar cualquier número. Cuanto más grande sea el número, más bits voy a 
necesitar. Algo muy similar ocurre con los números con coma y es que si tengo un número con muchos 
dígitos después de la coma, voy a necesitar más bits (digo parecido, porque no es igual. Si les interesa 
pregúntenme en clase por aritmética de punto flotante). Entonces tengo un problema. Lo digital parecía muy 
bueno, pero tiene el enorme inconveniente de que no puedo tener infinita definición, esto es tantos números 
después de la coma como quiera, sino que tengo que definir cuántos números (cuántos bits) son 
suficientes. Claramente tienen que ser suficientes para tener una resolución razonable, pero no tantos 
como para que me quede sin memoria. 

Volviendo al problema de lo analógico. Los valores analógicos tienen coma! Nunca voy a poder conocer 
exactamente el valor analógico, sólo hasta una cierta resolución. Para hacer la conversión de analógico a 
digital se utilizan unos dispositivos que se llaman ADC (analog-digital converter) que tienen una resolución. 
Esta resolución está dada en bits y puede ser, por ejemplo, de 8, 10 o 12 bits (los hay de más y de menos). 
Esto quiere decir que el número que mida, va a ser de 8, 10, 12 bits y no más, la 
medición no es perfecta. Pero es algo con lo que tendremos que aprender a vivir y, con suerte, 
aprenderemos cómo armar circuitos que funcionen bien para los niveles de resolución que tengan nuestros 
ADC

Un último detalle que voy a aclarar es un detalle muy sutil, pero que es importante. Los ADC, al tener 
resolución, tendrán un valor máximo. Si sopapa ADC tiene resolución de 10 bits, yo con 10 bits no puedo 
escribir un número mayor a 1023 (1111111111), por lo que este es el máximo. Ahora, que voltaje es el 
máximo? Recordemos que medir una señal eléctrica significa (casi) siempre medir voltaje. Qué voltaje tiene 
que medir sopapa ADC para que me devuelva 1023? La respuesta a esta pregunta es: depende. Lo que 
pasa es que (y esto vale para Soy una bella mariposa electricidad en general), los voltajes sólo tienen 
sentido si se los compara contra otro voltaje (si quieren profundizar en esto pregúntenme en clase). 
Entonces, lo que hace el Arduino, es comparar siempre contra un voltaje conocido. Normalmente es el 
máximo, +5V (se puede elegir valores más bajos para ganar resolución, como 1V), por lo que si el ADC está 
midiendo +5V, devuelve 1023, si mide 0V, devuelve 0 y si mide +2.5V, devuelve 511 o 512 (acá se ve la 
pérdida de resolución).

*/
