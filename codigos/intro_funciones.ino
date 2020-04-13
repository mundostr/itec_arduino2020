void imprimirPorConsola(String texto01) {
	Serial.println(texto01);
	for (int i = 0; i < texto01.length(); i++) {
		Serial.print("-");
	}
	Serial.println("");
	Serial.println("");
	Serial.println("");
}

void setup() {
	Serial.begin(115200);
	Serial.println("SISTEMA INICIADO");
	Serial.println();

	imprimirPorConsola("Lectura 1");
	imprimirPorConsola("Lectura valor 2");
	imprimirPorConsola("Lectura 3");
}

void loop() {
}
