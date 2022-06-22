/*
*  Input Digital
*   Ahora vamos a ver cómo tomar mediciones digitales.
*   La electricidad tiene varios componentes que la
*   caracterizan (voltaje y corriente) pero lo que es
*   más sencillo de medir es el voltaje. Casi siempre,
*   cuando hablamos de medir algo eléctrico, hablamos
*   de medir su voltaje.
*
*   Los circuitos electrónicos tienen 2 grandes ramas.
*   La analógica, donde los voltajes pueden variar libremente.
*   Como arduino puede generar voltajes entre 0 y +5 voltios,
*   un circuito analógico de Arduino tendría voltajes entre 0 y 5.
*   Puede ser 0, 5, 3.3, 4.8, 1.25 o cualquier valor en el medio.
*   Ya veremos cómo tratar con estas situaciones más adelante, pero
*   para darles una idea de la problemática que puede tener trabajar
*   con circuitos analógicos con microcontroladores es que estos son
*   inherentemente digitales.
*
*   Un circuito digital tiene solo dos
*   voltajes posibles: + y -, positivo y negativo, si y no. Como
*   Arduino trabaja entre 0V y +5V, una señal de sí, positiva, prendiada,
*   etc. es da cuando el voltaje es 5V. Por el contrario, una señal negativa,
*   apagada, de no se da cuando el voltaje es 0 (o está a tierra)
*   Ya lo vimos con el LED, que era una situación digital. Sólo
*   había 2 valores, si y no, apagado y prendido. Si prestaron atención
*   recordarán que la función para prender y apagar el LED se llamaba
*   digitalWrite (escritura digital), que es un nombre muy apropiado,
*   dado que es un paradigma digital!
*
*   Ahora veremos cómo medir una señal digital, que como vimos
*   puede ser si o no. O sea que lo que vamos a recibir es un valor
*   verdadero/falso (un bool) ya que sólo hay dos posibles estados.
*   La señal la haremos llegar a un pin que configuraremos cono entrada
*   (INPUT). Lógicamente, si recive +5V, será verdadera y si recibe 0V
*   (está conectada a tierra) será negativa. Luego pueden probar de
*   conectar directamente el pin a positivo y negativo (5V y GND) del
*   Arduino (quê pasa si lo conetcamos a 3.3V?)
*
*   El circuito que armamos es, básicamente, un interruptor. Cuando
*   está hacia la izquierda, el positivo está desconectado de todo, por
*   lo que el cable verde para a través de la resistencia hasta el negativo.
*   Ignorando por un segundo la resistencia (que podemos ahora considerarla
*   un cable normal), lo que estamos haaciendo es conectar el pin a la tierra.
*   Lo que pasará entonces cuando el interruptor esté a la izquierda y desconecte
*   el positivo, es que llegará señal negativa y leeremos una señal digital de falso.
*   Por otro lado, si cambiamos el interruptor hacia la derecha, conectando
*   el positivo al cable verde (como la tierra está conectada a través de una
*   resistencia grande y por lo tanto pasará poca corriente), la señal positiva
*   predomirará por sobre la negativa y finalmente leeremos en el pin una señal
*   digital verdadera. La lectura se ve en el monitor serie
*
*   Si no entendieron por qué la seńal positiva predomina por sobre la negativa,
*   no se preocupen. En la práctica es como si conectáramos el pin al positivo
*   directamente, o el pin al negativo directamente. Si conectamos a postivo
*   leeremos veraddero y si conectamos a negativo leeremos falso. Si quieren saber
*   exactamente por qué el circuito funciona de esta manera pregúntenme en clase :)
*/

const byte readPin = 2; // declaramos una variable global para el pin de lectura

void setup()
{
  Serial.begin(9600); // iniciamos el monitor serie
  pinMode(readPin, INPUT); // indicamos que readPin es de entrada
  pinMode(LED_BUILTIN, OUTPUT); // iniciamos el led interno del Arduino como salida (muchos Arduinos tienen un led interno conectado como el circuito que ya vieron para el LED y está conectado a un pin que se llama LED_BUILTIN, que es el 13. Podemos usarlo como cualquier LED, pero es más sencillo porque ya está conectado)
}

void loop()
{
  bool read = digitalRead(readPin); // con la función digitalRead podemos leer una señal digital en el pin especificado. Guardamos el resultado en una variable bool (verdadero/falso)
  digitalWrite(LED_BUILTIN, read); // copiamos el estado de la señal en el led interno del Arduino
  Serial.print("Senal digital: ");
  Serial.println(read); // escribimos la señal en el monitor serie. Aparecerá como 1 para verdadero y 0 para falso (esto tiene que ver con cómo se representan los valores bool en la memoria)
}
