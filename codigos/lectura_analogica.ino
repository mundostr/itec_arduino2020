/*
  Uso de potenciómetro para repaso de lectura analógica
  Agregado de función map() para extrapolación de valores entre rango ADC y rango analogWrite
 */

const int PIN_LED = 13;
const int PIN_POT = 14; // A0
const int FREC_POT = 100;

int lectura, lecturaMap;

void setup() {
  Serial.begin(38400);
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
    lectura = analogRead(PIN_POT);
    // map() nos permite extrapolar un valor de un rango a otro, en este caso el de la variable
    // "lectura", siendo el rango original 0 a 1023, y el destino 0 a 255.
    // por ende lectura = 0 => lecturaMap = 0, lectura = 1023 => lecturaMap = 255,
    // lectura = 512 => lecturaMap = 128, etc.
    lecturaMap = map(lectura, 0, 1023, 0, 255);
    Serial.println(lectura);
	Serial.println(lecturaMap);
	// La extrapolación que hicimos con map() es necesaria, ya que analogWrite en el caso de
    // Arduino UNO, solo opera en un rango de 0 a 255.
    analogWrite(PIN_LED, lecturaMap);

	// Aguardamos 100 milisegundos antes de repetir
	delay(100);
}
