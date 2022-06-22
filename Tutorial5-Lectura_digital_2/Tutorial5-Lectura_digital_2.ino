const byte buttonPin = 2;
const byte ledPin = 4;

bool lastButtonState = false; // declaramos variable global que represente el último estado del botón
bool ledState = false; // declaramos variable global que represente el estado del LED (prendido/apagado)

void setup() {
  pinMode(buttonPin, INPUT); // buttonPin es una entrada. queremos leer de ella
  pinMode(ledPin, OUTPUT);   // ledPin es una salida. queremos prender y apagar el LED con ella

  digitalWrite(ledPin, ledState); // ponemos al led en el mismo estado que la variable ledState (false = apagado)
}

void loop() {
  // leemos si en el pin 2 hay señal positiva (5V) o negativa (0V, tierra)
  int reading = digitalRead(buttonPin);

  // si cambió el estado del botón
  if (reading != lastButtonState) {
    lastButtonState = reading; // guardamos este estado como el último
    if (reading) { // si el estado al que se cambió es el presionado (positivo)
      ledState = !ledState; // cambiar el estado del led
      digitalWrite(ledPin, ledState); // y escribimos este estado en el pin del led
    }
  }
}
