#include <elapsedMillis.h>

const byte LED1 = 12;
const byte LED0 = 13;
const byte BTN1 = 10;
const int FREC_PARPADEO = 1500;
const int FREC_BTN = 100;

boolean estadoLed1 = false;
boolean estadoBtn1 = false;

elapsedMillis parpadeo;
elapsedMillis btn;

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BTN1, INPUT);
}

void loop() {
  if (parpadeo >= FREC_PARPADEO) {
    estadoLed1 = !estadoLed1;
    digitalWrite(LED1, estadoLed1);
    parpadeo = 0;
  }

  if (btn >= FREC_BTN) {
    if (digitalRead(BTN1) == HIGH) {
      digitalWrite(LED0, HIGH);
    } else {
      digitalWrite(LED0, LOW);
    }
    btn = 0;
  }
}
