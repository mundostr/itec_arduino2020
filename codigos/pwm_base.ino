// PWM Pulse Width Modulation = Modulación por Ancho de Pulso
// ADC Analog Digital Converter
// AnalogRead() 0-5V 0-1023 (ADC 10 bits)

#include <elapsedMillis.h>

const byte LED1 = 11;
const byte LED2 = 12;
bool estadoLed2 = false;
int intensidadLed1 = 0;
int salto = 5;

elapsedMillis timerLed1;
elapsedMillis timerLed2;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
	if (timerLed1 >= 30) {
		intensidadLed1 = intensidadLed1 + salto;
		analogWrite(LED1, intensidadLed1);
		if (intensidadLed1 == 0 || intensidadLed1 == 255) {
			salto = -salto;
		}
		timerLed1 = 0;
	}

	if (timerLed2 >= 500) {
		estadoLed2 = !estadoLed2;
		digitalWrite(LED2, estadoLed2);
		timerLed2 = 0;
	}
}
