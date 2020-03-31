/*
  Utilizamos el led incorporado en la placa
  Configuramos el pin (13) como salida
  y luego utilizamos un ciclo permamente para activarlo y desactivarlo a intervalos regulares
*/

// Declaramos las constantes LED y FREC_PARPADEO como tipo entero (int)
const int LED = 13;
const int FREC_PARPADEO = 500; // en milisegundos

void setup() {
  // Configuramos el pin del led como salida, aprovechando la constante OUTPUT
  // ya definida en el sistema
  pinMode(LED, OUTPUT);
}

void loop() {
	// Ponemos en "alto" el pin, aprovechando la constante HIGH
	// También podríamos utilizar 1 sin problemas
  digitalWrite(LED, HIGH);
  // Aguardamos aplicando la función delay()
  // Durante ese período el led permanecerá encendido, ya que el último
  // digitalWrite se hizo con HIGH
  // Como veremos más adelante, esta forma no permite trabajar en tareas múltiples,
  // pero por el momento no nos afecta.
  delay(FREC_PARPADEO);

  // Ejecutamos lo mismo pero ahora con un LOW, para mantener durante ese tiempo
  // en "bajo" el pin, y por ende apagado el led.
  // Como nos encontramos dentro del loop(), esta secuencia se repetirá constantemente
  // mientras la placa se mantenga energizada.
  digitalWrite(,LED, LOW);
  delay(FREC_PARPADEO);
}
