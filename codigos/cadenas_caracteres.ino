// char *txt1 = "Itec";
// char *txt2 = "Rafaela";
String txt1 = "Itec";
String txt2 = "Rafaela";

float resultado = 28.54;

void setup() {
	Serial.begin(115200);
	Serial.println(txt1);
	Serial.println(txt2);
	Serial.println(txt1 + " " + txt2);
	// strcat(txt1, txt2);
	// Serial.println(txt1);
	Serial.println("El resultado es: " + String(resultado));
}

void loop() {
}
