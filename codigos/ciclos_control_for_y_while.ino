/*
  Ejemplo ciclos de control
  Utilización de for() y while() para ciclos FINITOS que realizan una sumatoria
*/

int sumatoria = 0;

void setup() {
  Serial.begin(38400);
  // Definimos el ciclo for inicializando una variable arbitraria "c"
  // a 0; luego la condición límite (c < 10) y por último el paso de incremento (c++)
  // Por ende en este caso el ciclo se repetirá para 0, 1, 2, 3, 4, 5, 6, 7, 8 y 9
  // y la variable "sumatoria" acumulará dicha suma (45).
  for (int c = 0; c < 10; c++) {
    sumatoria = sumatoria + c; // a la variable sumatoria se la suele denominar "acumulador"
	// sumatoria += c; // otra forma de escribirlo
  }
  Serial.println(sumatoria);

  // Retornamos sumatoria a 0 para usarla nuevamente en el while()
  sumatoria = 0;
  // Dado que el while() solo opera on una condición, definimos una variable para el ciclo por fuera
  int ciclo = 0;
  // Activamos el while, el cual continuará repitiendo su contenido hasta que se valide la condición
  // (ciclo < 10 en este caso), allí el while se interrumpirá y el código seguirá con el flujo
  // normal, imprimiendo sumatoria por consola.
  while (ciclo < 10) {
    sumatoria = sumatoria + ciclo; // o bien sumatoria += ciclo, es lo mismo
    ciclo = ciclo + 1; // o bien ciclo++;
  }
  Serial.println(sumatoria);
}

void loop() {
  // En este caso el loop() queda vacío, solo nos interesa ejecutar una vez los ciclos
  // en el setup para entender su funcionamiento, pero recordar que aún estando vacío,
  // debemos incluir el loop() o el compilador se quejará.
}
