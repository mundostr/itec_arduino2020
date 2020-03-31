/*
  La función map() nativa, tiene la limitación de no operar con decimales, lo cual puede
  resultar inconveniente en algunos casos. En ellos podemos reescribir una función map()
  personalizada, que retorne un float en lugar de un int.
*/

int lectura;
// recordemos que el tipo de datos float nos permite setear variables que trabajen con coma flotante (decimales)
float lecturaMap;

float mapFlotante(float var, float vemin, float vemax, float vsmin, float vsmax) {
  return (var - vemin) * (vsmax - vsmin) / (vemax - vemin) + vsmin;
}

void setup() {
  Serial.begin(38400);
  pinMode(A0, INPUT);
}

void loop() {
  lectura = analogRead(A0);
  lecturaMap = mapFlotante(lectura, 0, 1023, 0, 5);
  Serial.println(lectura);
  Serial.println(lecturaMap);
  delay(100);
}
