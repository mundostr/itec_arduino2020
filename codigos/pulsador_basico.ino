/*
  Conexión pulsador:
  - 1 extremo a VCC (5V)
  - otro extremo a D2
  - D2 a GND con resistencia de 1K (MUY IMPORTANTE!, utilizar la resistencia)
*/

const int PULSADOR = 2;

void setup() {
  // Inicializamos la consola serial
  Serial.begin(38400);
  // Definimos ahora al pin como ENTRADA, para poder LEER su estado
  pinMode(PULSADOR, INPUT);
}

void loop() {
  // Leemos el estado del pin cada 100 ms empleando la función digitalRead()
  // y lo mostramos por consola para poder observarlo en tiempo real
  // Se debe ver el cambio entre pulsado y libre sin problemas
  // Qué sucede con las lecturas si se quita la resistencia?
  Serial.println(digitalRead(PULSADOR));
  delay(100);
}
