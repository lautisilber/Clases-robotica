/*
*  Bienvenides a Arduino y el idioma en que se programa: C++
* Hagamos una pequeña introducción a algunos conceptos básicos
* de la programación. (Toda línea de código que empiece con
* '//', y todo código que se encuentre entre '/ *' y '* /' se
* trata como un comentario: el programa lo ignorará por completo)
*
*/

void setup()
{
  Serial.begin(9600);
  /*
  * Variables:
  *   Las variables son datosque se almacenan en la memoria
  *   Llevan un nombre que podemos elegir y se puede acceder
  *   al valor que giardan y, normalmente, se puede modificar
  *   este valor. Como estamos trabajando con el idioma C++,
  *   además, debemos indicarle a la variable cuando la creamos
  *   (se llama declarar la variable) qué tipo de datos va a
  *   guardar. Algunas opciones son números enteros (int),
  *   texto (String) o números con coma (float) (sí, números
  *   enteros y números con coma son dos tipos de variable 
  *   distintos) booleanos (verdadero/falso). También podemos
  *   escribir 'const' antes del tipo si esa variable no se va
  *   a cambiar, así dejamos que Arduino la use más eficientemente
  *   A continuación hay algunos ejemplos.
  *
  *   Para simplificar todo, introduzco la clase Serial. No importa
  *   por ahora qué es una clase o qué hace Serial (si quieren
  *   saber pregúntenme en clase o mándenme mail!). Simplemente
  *   sepamos que nos permite escribir en el monitor serie.
  *   Con 'Serial.begin(9600)' iniciamos el monitor y con
  *   'Serial.print([contenido])' y 'Serial.println([contenido])'
  *   escribimos allí. Para abrir el monitor clickeen abajo, donde
  *   dice 'Monitor en serie'
  */
  
  Serial.println("\nVariables");
  // defino variables y su valor inicial
  int entero1 = 0;
  const float conComa1 = 3.4;
  const String texto1 = "Lo esccencial es invicible a los ojos";
  
  Serial.print("entero1: ");
  Serial.println(entero1);
  
  Serial.print("conComa1: ");
  Serial.println(conComa1);
  
  Serial.print("texto1: ");
  Serial.println(texto1);
  
  // cambio el valor de una variable
  entero1 = 120;
  Serial.print("cambio el valor de 'entero1': ");
  Serial.println(entero1);
  
  /*
  *   También puedo hacer operaciones. Estas pueden ser matemáticas: +, - *, /
  *   preo también hay operaciones lógicas que son más fáciles de ver en la
  *   sección flujo: < (menor que), > (mayor que), == (igual), != (distinto)
  *   <= (menor o igual a), >= (mayor o igual a)
  */
  
  const int entero2 = 6;
  const int entero3 = -4;
  Serial.println("\nAlgunas operaciones");
  
  Serial.print("entero1 + entero2 = ");
  Serial.println(entero1 + entero2);
  Serial.print("entero1 - entero2 = ");
  Serial.println(entero1 - entero2);
  Serial.print("entero1 multiplicacdo por entero2 = ");
  Serial.println(entero1 * entero2);
  Serial.print("entero1 dividido por entero2 = ");
  Serial.println(entero1 / entero2);
  Serial.print("entero1 + entero3 = ");
  Serial.println(entero1 + entero3);
  
  /*
  *   y asignar los resultados a una variable
  */
  
  int entero4;
  entero4 = entero1 - entero3;
  Serial.print("entero4: ");
  Serial.println(entero4);
  
  /*
  * Flujo:
  *   Otra cosa que podemos hacer, y esto probablemente lo sepan de
  *   haber trabajado con sketch (los bloques ocn los que se programan
  *   los lego) es controlar el flujo del programa con ciertas palabras clave
  *   como 'if' y 'else' , 'while', 'for', y muchísimas más (cualquier cosa me preguntan)
  */
  
  // ejemplo 'if' y 'else'
  const bool variableVerdadera = true;
  const bool variableFalsa = false;
  
  Serial.println("\nFlujo");
  if (variableVerdadera) {
    Serial.println("variableVerdadera es verdadera");
  }
  
  if (variableFalsa) {
    Serial.println("variableFalsa es verdadera");
  }
  
  if (variableFalsa) {
    Serial.println("variableFalsa es verdadera");
  } else {
    Serial.println("variableFalsa es falsa");
  }
  
  const int entero5 = 2;
  
  if (entero5 == 0) {
    Serial.println("entero5 es igual a 0");
  } else if (entero5 == 1) {
    Serial.println("entero5 es igual a 1");
  } else if (entero5 == 2) {
    Serial.println("entero5 es igual a 2");
  } else if (entero5 == 3) {
    Serial.println("entero5 es igual a 3");
  } else {
    Serial.println("No se a que es igual entero5");
  }
  
  if (entero5 < 1) {
    Serial.println("entero5 es menor a 1");
  } else if (entero5 > 1) {
    Serial.println("entero5 es mayor a 1");
  }
  
  if (entero5 != 4) {
    Serial.println("entero5 es distinto a 4");
  } else {
    Serial.println("entero5 es igual a 4");
  }
  
  String texto2 = "papanata";
  if (texto2 == "papanata") {
    Serial.println("texto2 es igual a papanata");
  }
}

void loop()
{
}
