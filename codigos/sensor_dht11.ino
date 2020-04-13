#include <SimpleDHT.h>

#define PIN_SENSOR 2

byte temperatura, humedad;

SimpleDHT11 dht11(PIN_SENSOR);

void setup() {
  Serial.begin(115200);
  Serial.println("SISTEMA INICIADO");
}

void loop() {
  dht11.read(&temperatura, &humedad, NULL);
  Serial.println("Temperatura: " + String(temperatura) + "C, humedad: " + String(humedad) + "%");
  delay(2000);
}
