/*
* Funciones
*  Otra cosa que podemos hacer en C++ que es de suma importancia
* es utilizar funciones. Una funcion nos permite agrupar una serie
* comandos bajo un único nombre. Una funcion tiene algunas similitudes
* con las variables (y hay casos donde se la trata como una)
* pero se usa diferente.
*
* Una función funciona como una caja negra. Se le da un input,
*   o entrada y esta devuelve un valor
* INPUT -> FUNCION -> VALOR
* Por ejemplo, la suma es una función
* 1, 2 -> SUMA -> 3
*
* Primero hay que declarar la función. Para ello se debe saber
* cuáles son los parámetros (entrada o input) y cuál es la salida.
* Es mejor si lo vemos con un ejemplo
*/

// declaramos la función SumaDeEnteros

// int es el tipo de valor que devolverá la función. Como es una suma de enteros, devolveremos un entero (int)
// Luego se escribe el nombre de la funión que puede ser el que querramos
// Después, entre paréntesis y separados por coma se esccrciben los parámetros con sus tipos que son las entradas o inputs de la función
// Toda la funcionalidad se escribe entre corchetes
int SumaDeEnteros(int a, int b) {
  int s = a + b; // declaramos una variable int llamada s que es igual a 'a' más 'b'
  return s; // devolvemos el valor s con la palabra clave 'return'
}

/*
* Es importante ver que las variables que declaramos dentro de una funcion
* son 'locales'. Es decir que existen sólo dentro de la función y una vez
* que termina la función estas variables se borran para siempre
*/

// Dejo algunas funciones de ejemplo más

float MultiplicacionConComa(float a, float b) {
  float m = a * b;
  return m;
}

String AgregarTexto(String texto) {
  const String extra = "paparulo";
  String todo = texto + extra;
  return todo;
}

int CuarentaYDos() {
  return 42;
}

void EscribirHola() {
  // Esta función devuelve tipo 'void' (vacío en inglés). Las funciones
  // que devuelven 'void', no hace falta que tengan un return dado que
  // void está indicando que no devuelve nada.
  Serial.println("Hola, que tul?");
}

void EscribirChau() {
  // Igualmente, funciones void sí pueden tener un return que la finaliza.
  // Lo que esté después de return no se ejecutará
  Serial.println("Chauchis");
  return;
  Serial.println("Esto nunca va a ocurrir");
}

void EscribirTexto(String texto) {
  Serial.println(texto);
}

void EscribirNumero(int n=12) {
  // Si un parámetro se lo iguala a un valor, esto significa que este parámetro
  // tiene un valor por defecto. Si se pasa el parámetro n, funcionará normalmente,
  // pero si no se pasa un valor para n, n será igual a 12
  Serial.println(n);
}

/*
* Si prestaron atención se habrán dado cuenta, que 'setup' y 'loop' que están
* en todos los programas de Arduino son funciones. Estas son efectivamente son
* funciones, pero son especiales. Estas no podemos ejecutarlas nosotres, sino que
* las ejecuta Arduino. 'setup' se ejecuta al principio de cada programa y 'loop'
* se ejecuta todo el tiempo (en loop) luego de setup. Voy a ejecutar las funcionnes
* que declaramos en setup para que ocurrann sólo una vez.
*
* Para ejecutar una función (se dice llamar una función) se escribe el nombre de la
* misma seguida de paréntesis. Si tiene parámetros, los esccribimos en el paréntesis.
* La función devolverá valores del tipo que se haya declarado.
*/

void setup()
{
  Serial.begin(9600);
  
  // suma de enteros
  const int a = 1;
  const int b = 2;
  const int c = SumaDeEnteros(a, b);
  Serial.print("suma de enteros");
  Serial.println(c);
  
  const float d = 3.4;
  const float e = 5.9;
  Serial.println("multiplicacion de numeros con coma");
  Serial.println(MultiplicacionConComa(d, e)); // esto se puede hace perfectamente! Es como poner una variable
  
  // agregar texto
  String texto1 = "Holus ";
  Serial.print("agregar texto: ");
  Serial.println(AgregarTexto(texto1));
  
  // 42
  Serial.print("42: ");
  Serial.println(CuarentaYDos());
  
  // escrbir hola
  EscribirHola();
  
  // escribir chau
  EscribirChau();
  
  // escribir texto
  const String texto2 = "mike wazowski";
  const String texto3 = AgregarTexto(texto2);
  EscribirTexto(texto2);
  EscribirTexto(texto3);
  EscribirTexto("hocus pocus"); // tambien puedo agregar parámetros directamente
  
  // escribir numero
  EscribirNumero(37);
  EscribirNumero(CuarentaYDos());
  EscribirNumero();
  
}

void loop()
{
}
