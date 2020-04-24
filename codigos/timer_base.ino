const byte LED1 = 12;
const byte LED0 = 13;
const byte BTN1 = 10;

boolean estadoLed1 = false;
boolean estadoBtn1 = false;
unsigned long timer1;
unsigned long timer2;

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BTN1, INPUT);
  timer1 = millis();
  timer2 = millis();
}

void loop() {
  if (millis() - timer1 >= 500) {
    estadoLed1 = !estadoLed1;
    digitalWrite(LED1, estadoLed1);
    timer1 = millis();
  }

  if (millis() - timer2 >= 100) {
    if (digitalRead(BTN1) == HIGH) {
      digitalWrite(LED0, HIGH);
    } else {
      digitalWrite(LED0, LOW);
    }
    timer2 = millis();
  }
}
