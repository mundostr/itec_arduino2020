<h1><b>FUNDACION INSTITUTO TECNOLOGICO RAFAELA</b></h1>
<h2><b>Taller Arduino Adultos 2020</b></h2>

<h3>Temporizadores (timers e interrupciones)</h3>

Hasta el momento, <b>solo hemos efectuado un control de tiempo básico mediante llamadas a la función <i>delay()</i></b> en milisegundos. Si bien es válido, <b>esta solución implica que durante los momentos en los cuales se ejecute la espera, el microcontrolador no podrá atender nada más</b>, solo quedará al aguardo de cumplirse ese plazo para continuar:

```
void loop() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
```

Con este simple código podemos parpadear infinitamente al led incorporado en el pin 13 del Arduino Uno (identificado también con la constante LED_BUILTIN), y si es solo esa tarea la que realizaremos, no existe problema, pero si necesitamos por ejemplo atender el parpadeo y simultáneamente quedar atentos a la pulsación de un botón, no será posible, el sistema simplemente hará caso omiso de cualquier pulsación que realicemos durante los períodos de delay(500).

<p>&nbsp;</p>

<b>La opción millis()</b>

<b>Una de las formas de solucionar ésto, es utilizar la función <i>millis()</i>, la cual devuelve el número de milisegundos transcurridos desde que se comenzó a ejecutar el programa actual</b>. Esta función obtiene la información de un timer interno que se incrementa constantemente, hasta llegar a un <i>overflow</i> en aprox. 49 días, comenzando nuevamente desde 0, por ende si en nuestra aplicación necesitamos dejar operando desatendido el micro por más de 49 días, tendremos que contemplar en el código este retorno a 0; para la gran mayoría de los casos ese límite será mucho más que suficiente.

Si chequeamos constantemente el retorno de <i>millis()</i> y lo evaluamos dentro de una condición, podremos llevar un control de tiempo preciso para ejecutar procesos a intervalos definidos:

```
const long INTERVALO = 60000;

unsigned long tiempoAnterior;

void setup() {
	tiempoAnterior = millis();
}

void loop() {
  if (millis() - tiempoAnterior >= INTERVALO) {
    // Ejecutamos el código que deseemos y por último actualizamos tiempoAnterior
    tiempoAnterior = millis();
  }
}
```

Podemos ver que hemos definido una variable de tipo <i>unsigned long</i> para guardar el valor de <i>millis()</i>, utilizamos long ya que el número crecerá rápidamente, por ende necesitamos un tipo de dato que nos permita manejar valores grandes, y el modificador unsigned ya que solo trabajaremos positivos (al tratarse de tiempo). En cada ciclo.

En el condicional, realizamos la resta del valor de millis() en ese momento menos tiempoAnterior, y lo comparamos con nuestro INTERVALO, cuando esa resta iguala o supera a INTERVALO, significa que ese período de tiempo ha transcurrido, la condición se vuelve <i>verdadera</i> y por lo tanto se ejecuta lo que esté dentro del <i>if()</i>. Allí hacemos lo que necesitamos, y por último actualizamos <i>tiempoAnterior</i> al valor actual de <i>millis</i>, para que la condición vuelva a caer en <i>falso</i> hasta que transcurra un nuevo período INTERVALO.

En el ejemplo, INTERVALO está fijado en 60000 (milisegundos = 60 segs = 1 min), es decir, queremos ejecutar un determinado código, una vez por minuto.

**Además de <i>millis()</i>, el entorno de Arduino nos brinda otra función de alto nivel, <i>micros()</i>, la cual opera bajo los mismos conceptos pero devuelve la cantidad de <i>microsegundos</i> transcurridos desde el inicio de ejecución del código. Para operaciones que requieren mayor resolución, podemos optar por esta variante, si bien para controles de tareas y tiempos normales, <i>millis()</i> es más que suficiente.**

Si no queremos plantear las condiciones de <i>millis()</i> manualmente, podemos aprovechar alguna librería escrita a tal efecto, como elapsedMillis:

```
#include <elapsedMillis.h>

bool estadoLed = LOW;
const byte PIN_LED = 13;
const byte INTERVALO_LED = 100;

elapsedMillis timer01;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (timer01 >= INTERVALO_LED) {
    estadoLed = !estadoLed;
    digitalWrite(PIN_LED, estadoLed);
    timer01 = 0;
  }
}
```

Al incluir la librería <i>elapsedMillis</i>, se vuelve disponible en nuestro código una clase del mismo nombre, con la cual podemos definir un objeto (línea <i>elapsedMillis timer01;</i>) para controlar los intervalos de tiempo. Una vez disponible el objeto, simplemente lo comparamos con la constante de intervalo que hayamos definido (<i>INTERVALO_LED</i>) para saber cuánto tiempo ha transcurrido, y ejecutamos dentro de la condición el código que necesitemos, sin olvidar resetear a 0 (<i>timer01 = 0;</i>) para comenzar a controlar el próximo intervalo.

<b>Interrupciones externas</b>

Lo visto previamente funciona bien con tareas periódicas, es decir, ejecutadas a intervalos regulares de tiempo, controlados mediante <i>millis()</i> o <i>micros()</i>. El método es funcional, no tiene nada de malo, sin embargo no se ajusta a <i>eventos</i> que no sabemos en qué momento exacto se producirán (un botón de inicio / parada por ej, se puede pulsar de inmediato o no, de cualquier manera con millis() por ejemplo podremos chequear repetidamente cada 50 ms digamos - este mecanismo de consulta repetida de entradas se suele llamar "poll" en inglés- con la desventaja principal de mayor consumo de procesamiento y energía).

<p>&nbsp;</p>

> Aquí surge la opción de <b>interrupciones externas</b>, otra variante en microcontroladores para atender justamente a <i>eventos</i> no programados. Las interrupciones externas por hardware asocian una función definida por el usuario (ISR = Interrupt Service Routine) a un <i>evento</i> de cambio de estado en un pin físico, con prioridad total, es decir, ni bien se sucede el evento, el micro deriva la ejecución al contenido de la función ISR relacionada, y tan pronto ésta termina, retorna al flujo principal, en el lugar exacto donde lo había interrumpido, y continúa desde allí (lógicamente todo esto se sucede en microsegundos).

<img src="https://cdn-learn.adafruit.com/assets/assets/000/021/334/medium640/components_interrupt.png?1416523011" width="400">

En realidad, internamente el micro de Arduino utiliza de forma constante interrupciones (por ej para la transmisión serie, la comunicación I2C, el manejo de las propias funciones delay() y millis(), o el reseteo de la placa luego de grabar un nuevo código). El uso de ellas en nuestro código no es obligatorio, en especial con programas sencillos, pero se vuelve muy efectivo en programas más avanzados.

Como mencionamos, una <i>interrupción</i> está ligada a un evento de cambio de estado en un pin determinado. <b>Primero debemos conocer, que no todos los pines son utilizables con este método, en el caso del Arduino UNO como el que disponen en el kit, solo los pines digitales 2 y 3 aceptan interrupciones HW</b>; otras placas de desarrollo cuentan con mayor cantidad de pines gestionables con interrupciones.

Por otro lado, una vez que definimos el pin a utilizar, debemos indicar el evento por el cual se "disparará" la interrupción, y la función a ejecutar, veamos entonces cómo escribimos ese código:

```
const byte PULSADOR = 3; // GND a una pata del pulsador, y de la otra a PIN 3
int contador;

void setup() {
  pinMode(PULSADOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), notificar, FALLING);
}

void loop() {
}

void notificar() {
  contador++;
}
```

Vemos varios puntos interesantes:

* la llamada a <i>attachInterrupt</i> para definir la interrupción.
* el uso de <i>digitalPinToInterrupt</i> para indicar cuál es el pin digital que deseamos utilizar (recordar que no todos los pines manejan interrupciones por HW, se debe verificar con la documentación de la placa específica, cuáles son los disponibles).
* la indicación de la función personalizada a la que se derivará la ejecución de código, en este caso <i>notificar()</i>.
* la indicación del evento que nos interesa monitorear sobre ese pin, en el ejemplo, FALLING.

Vamos a explicar un poco más los eventos disponibles para ser capturados en interrupciones:

* <b>LOW</b>: se disparará tan pronto como el pin entre en un estado bajo (0).
* <b>CHANGE</b>: se disparará cada vez que el pin cambie de estado (sea de 0 a 1 o de 1 a 0).
* <b>RISING</b>: se disparará tan pronto como el pin comience a cambiar de 0 a 1.
* <b>FALLING</b>: se disparará tan pronto como el pin comience a cambiar de 1 a 0.

* <b>HIGH</b>: se disparará tan pronto como el pin entre en un estado alto (1).
(atención!, el evento HIGH NO puede utilizarse en muchos Arduinos o placas programables bajo el entorno, excepsiones son el Due, el Zero, placas MKR1000, los ESP8266 o los ESP32 por ej).

<p>&nbsp;</p>

> De esta manera, la línea:
>
> attachInterrupt(digitalPinToInterrupt(3), notificar, FALLING);
>
> se traduce como "habilitar interrupción en el pin digital 3, para ejecutar la función <i>notificar()</i> tan pronto como el estado del pin comience a caer de 1 a 0" (lo que en este caso significa que acabamos de iniciar presión sobre el pulsador, recordar que se utiliza negado por el INPUT_PULLUP).

> <b>Importante!: al diseñar una función ISR, tengamos en mente que la misma debe consumir el menor tiempo de ejecución posible, por lo general lo vamos a utilizar para cambiar de estado a variables booleanas, incrementar contadores y demás, luego en el flujo principal realizaremos otras tareas debido a esos cambios. NO es aconsejable colocar dentro, operaciones que consuman tiempo alto como comunicación serial o I2C por ejemplo, mientras más concisa, mejor. 

<p>&nbsp;</p>

Un detalle muy completo y explicativo de interrupciones, puede encontrarse en este apartado de la web <a href="https://aprendiendoarduino.wordpress.com/2016/11/13/interrupciones/">Aprendiendo Arduino</a>, y también en el <a href="https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/">Arduino CC oficial</a>.