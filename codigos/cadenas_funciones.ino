char *nombre = "Itec Rafaela";

bool contieneB(char *cadena, char caracter1, char caracter2) {
	return (strchr(cadena, caracter1) == NULL && strchr(nombre, caracter2) == NULL) ? false : true;
}

String contieneS(char *cadena, char caracter1, char caracter2) {
	return (strchr(cadena, caracter1) == NULL && strchr(nombre, caracter2) == NULL) ? "no" : "si";
}

void setup() {
	Serial.begin(115200);
	Serial.println("SISTEMA INICIADO");
	Serial.print("Cadena: ");
	Serial.println(nombre);
	Serial.print("Longitud: ");
	Serial.println(strlen(nombre));
	Serial.print("Contiene r: ");
	Serial.println(contieneS(nombre, 'r', 'R'));
}

void loop() {
}
