/*
  Conexión pulsador:
  - 1 extremo a VCC (5V)
  - otro extremo a D2
  - D2 a GND con resistencia de 1K (MUY IMPORTANTE!, utilizar la resistencia)

  Utilizamos ahora una función while() para activar una espera indefinida, solo
  cuando se presiona el pulsador, comienza la secuencia de parpadeo
*/

const int LED = 13;
const int PULSADOR = 2;
const int FREC_PARPADEO = 250;

void setup() {
  // Inicializamos la consola serial
  Serial.begin(38400);
  // Definimos ahora al pin como ENTRADA, para poder LEER su estado
  pinMode(PULSADOR, INPUT);
  pinMode(LED, OUTPUT);

  // Mientras la lectura del pulsador sea 0 (pulsador libre), solo esperamos haciendo nada
  while(digitalRead(PULSADOR) == LOW) {
  }
  // Solo cuando lectura sea 1 (pulsador presionado), se "romperá" el ciclo while()
  // y el sistema continuará hacia el loop(), iniciando el parpadeo.
  // Qué sucede si quitamos la resistencia entre D2 y GND?.
}

void loop() {
	// Solo parpadeamos constantemente el led
	digitalWrite(LED, HIGH);
	delay(FREC_PARPADEO);
	digitalWrite(LED, LOW);
	delay(FREC_PARPADEO);
}