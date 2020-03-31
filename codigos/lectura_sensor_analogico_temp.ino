/*
  Lectura de sensor analógico de temperatura TM36
  Conexiones:
  - pin VCC sensor a VCC Arduino (+5V)
  - pin GND sensor a GND Arduino
  - pin central sensor a pin analógico Arduino (A0)
*/

const int LED = 13;
const int PULSADOR = 8;
const int SENSOR = A0; // 14

void setup() {
  Serial.begin(38400);
  pinMode(LED, OUTPUT);
  pinMode(PULSADOR, INPUT);
  pinMode(SENSOR, INPUT);
  Serial.println("SISTEMA LISTO");
  
  // Utilizamos el while para una espera indefinida a que se presione el botón y comience.
  while(digitalRead(PULSADOR) == LOW) {
    Serial.println("aguardando pulsador");
    delay(500);
	// Mientras esperamos, imprimimos un mensaje cada 500 milisegundos en consola
  }
  // Ni bien se presional el pulsador y se "rompe" el ciclo while(), continuamos.
  Serial.println();
  Serial.println("loop iniciado");
}

void loop() {
  int lectura;
  // declaramos la variable como float, para poder trabajar con decimales
  float lecturaReal;
  
  lectura = analogRead(POTE); // devuelve 0 a 1023
  // Para el cálculo real en grados, el fabricante indica que a la lectura recibida
  // del pin (en milivolts), debemos multiplicarla por la resolución, al resultado restarle 0.5
  // y finalmente multiplicar por 100.
  // La resolución es la cantidad mínima de variación de voltaje que podemos detectar en el pin,
  // esto dependerá de cada placa, su voltaje de operación y su ADC (conversor analógico digital)
  // En este caso, como los pines digitales del Arduino UNO operan a 5V, y su ADC es de 10 bits
  // (permitiendo por lo tanto 1024 valores diferentes en la conversión (0 a 1023)), la resolución
  // será aprox de 0.0048 (5 / 1024), de allí la siguiente fórmula:
  lecturaReal = ((analogRead(POTE) * (5.0 / 1024.0)) - 0.5) * 100;
  
  Serial.print("Temperatura actual: ");
  Serial.println(lecturaReal, 1);
  Serial.println();
  
  delay(250);
}