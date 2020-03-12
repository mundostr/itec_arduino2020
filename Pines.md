<h1><b>FUNDACION INSTITUTO TECNOLOGICO RAFAELA</b></h1>
<h2><b>Taller Arduino Adultos 2020</b></h2>

<h3>Pines digitales y analógicos</h3>

<img src="https://openwebinars.net/media/django-summernote/2015-01-31/12bddab0-3d93-4510-98ca-ef8a7410ed11.jpg" width="400">

Hasta el momento nos hemos manejado con pines digitales, es decir, controlando solo dos estados (encendido o apagado, on u off, high o low, 0 o 1, tiene o no tiene corriente), utilizando las bahías superiores de nuestra placa Arduino.

<b>De hecho un microcontrolador opera en la totalidad de sus pines de manera digital</b>, sin embargo <b>en oportunidades tendremos necesidad de medir magnitudes físicas que pueden asumir cualquier valor dentro de un rango</b>, aquí nos serán de utilidad los pines analógicos, que en el caso del Arduino UNO se ubican en una bahía en la parte inferior derecha.

<img src="https://openwebinars.net/media/django-summernote/2015-01-31/dea32eaf-5a37-4f8d-aeaf-4db538d71020.jpg" width="400">

Como mencionamos, internamente el microcontrolador opera de manera digital, entonces qué diferencia a estos pines de los ubicados en la parte superior?. Bien, los pines analógicos A0 a A5 del Arduino UNO, están conectados a lo que se denomina un <a href="https://aprendiendoarduino.wordpress.com/tag/adc/"><b>ADC (Analog Digital Converter) o Conversor Analógico Digital</b></a>, el cual se encarga de realizar una cuantificación para convertir el valor analógico en una codificación digital (ingresar al enlace del nombre para tener información más detallada de este proceso), y nos devuelve un número en el rango 0 a 1023, proporcional a la lectura analógica que está recibiendo.

<i>Este rango depende de la resolución del conversor, en el caso del Arduino UNO la resolución es de 10 bits (2 elevado a la 10 = 1024), de allí los valores entre 0 y 1023</i>. Como veremos más adelante, esta resolución se puede ver afectada también por el rango de voltaje recibido en las entradas analógicas, que en el UNO operan de 0 a 5V. Si trabajamos en esas entradas con un nivel menor (0 a 3.3V por ejemplo), deberemos ajustar el voltaje de referencia (ARef) para aprovechar al 100% el rango del conversor.

<p>&nbsp;</p>

<b>Realizando una lectura analógica</b>

Conectaremos el siguiente circuito, empleando el potenciómetro de 10k incluído en el kit, para intentar tener una lectura progresiva del valor del mismo.

<img src="http://www.mundostreaming.tv/itec/arduino/imgs/arduino_pot.png?rnd=2" width="400">

La conexión del pot es muy sencilla, los extremos van a 5V y GND (indistintamente), y el punto central al pin A0. Intercambiando los extremos lograremos que el pot incremente su resistencia de forma horaria o antihoraria, es decir, solo invertiremos la lectura.

```
const byte PIN_POT = 14; // Utilizamos el analógico A0
int lectura;

void setup() {
  Serial.begin(38400);
  pinMode(PIN_POT, INPUT);
}

void loop() {
  lectura = analogRead(PIN_POT);
  Serial.println(lectura);
  delay(5);
}
```

> En el Arduino Uno, podemos indistintamente hacer referencia a los pines analógicos como A0 a A5, o 14 a 19

<b>Como vemos, solo declaramos una constante para hacer referencia al pin donde tenemos conectado el potenciómetro (en este caso el A0 o 14), lo configuramos como entrada y lo leemos cíclicamente en el <i>loop()</i>, pero utilizando ahora la función <i>analogRead()</i> en lugar de <i>digitalRead()</i></b>.

Tras subir el código a la placa y abrir la consola serial, comenzaremos a ver una secuencia de las lecturas recibidas del pin A0, y al mover el potenciómetro, esta lectura cambiará entre 0 y 1023 (recordar que si deseamos cambiar el sentido de incremento del potenciómetro, solo invertimos 5V y GND en sus extremos).

<p>&nbsp;</p>

<b>Reorganizando los datos de lectura con <i>map()</i></b>

Sabemos que la lectura tomada del pin analógico, será proporcional al voltaje recibido, el que a su vez responderá por ejemplo en el caso de un sensor, al nivel de la magnitud que esté controlando (temperatura, presión, humedad, luminosidad, etc), pero a efectos de darle mayor utilidad en nuestro código, necesitaremos reconvertir esa lectura a un valor que resulte más cómodo para nosotros. Podremos hacerlo a través de la función <i>map()</i>, modificando el código anterior a lo siguiente:

```
const byte PIN_POT = 14; // Utilizamos el analógico A0
int lectura;
int lecturaConvertida;

void setup() {
  Serial.begin(38400);
  pinMode(PIN_POT, INPUT);
}

void loop() {
  lectura = analogRead(PIN_POT);
  lecturaConvertida = map(lectura, 0, 1023, 0, 6);
  Serial.println(lecturaConvertida);
  delay(5);
}
```

<b>Los valores que veremos ahora en la consola serial, se encontrarán entre 0 y 6, "mapeados" en ese rango de acuerdo a la lectura original entre 0 y 1023. Si por ejemplo colocamos al pot en su posición media (estando entonces la lectura analógica alrededor de 512), en la consola tendremos el valor 3</b>. <i>Atención!, ésto se verificará si estamos empleando un pot lineal, no así con uno de tipo logarítmico en el que la variación no es progresiva</i>.

> <i>Si bien la función map() de Arduino es muy cómoda, tiene la limitación de operar solamente con valores enteros</i>, con lo cual si queremos mapear el valor del pin a un rango de 3.2 a 4.2V para controlar por ejemplo el estado de carga de una batería lipo de 1 celda, no tendríamos una buena resolución para trabajar. <i>En ese caso deberemos escribir una función de mapeo personalizada que opere con float, o bien realizar el cálculo directamente de manera manual</i>.

Podremos agregar a nuestro código una función personalizada para emplear en lugar de la <i>map()</i> standard:

```
// Función alternativa al map() standard con decimales
float mapFloat(float x, float min_orig, float max_orig, float min_salida, float max_salida) {
  return (x - min_orig) * (max_salida - min_salida) / (max_orig - min_orig) + min_salida;
}
```
