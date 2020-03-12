<h1><b>FUNDACION INSTITUTO TECNOLOGICO RAFAELA</b></h1>
<h2><b>Taller Arduino Adultos 2020</b></h2>

<h3>Bienvenida</h3>

### **El INSTITUTO TECNOLOGICO RAFAELA les da la bienvenida a su ciclo de talleres de prototipado en Arduino, agradeciendo su confianza y esperando que los mismos les resulten de utilidad en futuros proyectos.**

### El mundo Arduino

![Arduino Uno](https://store-cdn.arduino.cc/usa/catalog/product/cache/1/image/520x330/604a3538c15e081937dbfbd20aa60aad/a/0/a000066_featured_4.jpg)

Comenzando desde cero -y como no podía ser de otra manera- utilizando como primer imagen al hiper conocido Arduino Uno, vamos a introducirnos en este fantástico mundo.

**Arduino es una plataforma de código abierto (open-source) orientada al desarrollo de proyectos con microcontroladores**. Por qué es tan popular?, bien, por un lado indudablemente, el hecho de ser open-source es fundamental; por otro, tanto en lo referente al hardware como al software asociado, ha simplificado considerablemente el proceso de programación y carga de código, expandiendo el horizonte de uso de microcontroladores a una enorme cantidad de entusiastas y profesionales sin una formación netamente electrónica.

Si a lo mencionado le agregamos otros elementos como un costo sumamente accesible, la posibilidad de utilización en cualquiera de las plataformas populares (Linux, Windows, Mac, Android), y una enorme comunidad detrás, desarrollando de manera constante librerías y soluciones, obtenemos una combinación muy práctica y versátil para gran cantidad de aplicaciones.

**<a href="https://arduinohistory.github.io/">En arduinohistory.github.io puede leerse información interesante sobre la historia de Arduino</a>**

Hablamos de Arduino y hablamos de microcontroladores, qué es un microcontrolador?. Esencialmente es un circuito integrado programable, que incluye en su interior las 3 unidades funcionales primarias que estamos acostumbrados a observar en una computadora: [CPU (Unidad Central de Procesamiento)](https://es.wikipedia.org/wiki/Unidad_central_de_procesamiento), [memoria](<https://es.wikipedia.org/wiki/Memoria_(inform%C3%A1tica)>) y [periféricos de entrada y salida](<https://es.wikipedia.org/wiki/Perif%C3%A9rico_(inform%C3%A1tica)>).

Los [microcontroladores](https://es.wikipedia.org/wiki/Microcontrolador) (MCUs) han estado en la escena desde hace muchos años, sin embargo, su programación y uso eran bastante incómodos para el usuario general, aquel sin una formación específica electrónica. Con la llegada y la difusión de Arduino, esta situación cambió radicalmente, volviendo accesible la utilización de MCUs a todo el mundo.

### Entendiendo la estructura de funcionamiento

![Imagen original de aprendiendoarduino.files.wordpress.com](https://aprendiendoarduino.files.wordpress.com/2017/08/componetes-uno.jpg)

La gran comodidad de uso de modelos como el clásico Arduino Uno, se basa en la posibilidad de disponer en una única placa, de los distintos elementos necesarios tanto para programar como para probar diferentes códigos en un microcontrolador (más específicamente el [Atmega328P](https://es.wikipedia.org/wiki/Atmega328) en el caso del Uno), teniendo además una conectividad directa vía USB, y la opción de escribir código de manera práctica a través de un IDE gratuito y sencillo, tal cual el caso del [Arduino IDE oficial](https://www.arduino.cc/en/Main/Software).

Una placa de desarrollo Arduino, integra el microcontrolador con elementos como controlador USB, cristal externo de oscilación, regulador de voltaje, entrada para alimentación externa, botón de reset, capacitores, resistencias, diodos, leds y bahías de extensión para los pines del MCU, todo lo cual nos brinda mucha practicidad al momento de probar desarrollos.

Información detallada sobre este tema puede encontrarse en la página de Aprendiendo Arduino: [https://aprendiendoarduino.wordpress.com/2017/08/11/hw-arduino-a-fondo-2/](https://aprendiendoarduino.wordpress.com/2017/08/11/hw-arduino-a-fondo-2/).

Los primeros elementos a los que haremos mención, son las bahías de conectores que pueden observarse en el perímetro de la placa, las cuales no son más que extensiones cómodas de los distintos pines del microcontrolador, más varios pines de tierra (GND) alimentación 3.3 y 5V (para utilizar en sensores por ejemplo), reset y referencia de voltaje externa.

Lógicamente al momento de prototipar, será mucho más cómodo conectar y desconectar elementos en estas bahías, que hacerlo directamente a las salidas del propio micro.

<b>Tipos de pines en microcontroladores</b>

Dependiendo de la familia y modelo de microcontrolador que utilicemos, dispondremos de mayor o menor cantidad de pines para interactuar con elementos externos, pudiendo configurarlos como entradas o como salidas, bajo 2 tipos:

<b>Digitales</b>:

<img src="https://openwebinars.net/media/django-summernote/2015-01-31/12bddab0-3d93-4510-98ca-ef8a7410ed11.jpg" width="400">

Los pines digitales (ubicados en la zona superior) operan de forma booleana, "entendiendo" solo 2 niveles de señal, alto (HIGH, presencia de voltaje) o bajo (LOW, ausencia de voltaje). Puede parecer muy básico, pero en muchos casos es exactamente ésto lo que necesitamos, por ejemplo al momento de detectar un cambio en un pulsador, interruptor, final de carrera, sensor de presencia, etc.

Además, varios de estos pines llevan junto a ellos un tilde (~), el cual nos indica que ese pin es capaz de operar con señales PWM (Pulse Width Modulation, Modulación de Ancho de Pulso). Este tipo de señales, como veremos al avanzar con el curso, serán muy útiles y precisas para operar con diferentes sensores y elementos de control.

<b>Analógicos</b>:

<img src="https://openwebinars.net/media/django-summernote/2015-01-31/dea32eaf-5a37-4f8d-aeaf-4db538d71020.jpg" width="400">

Los pines analógicos por su parte (A0 a A5), son capaces de operar con valores de tensión dentro de un rango. En el caso del Arduino UNO, este rango es de 0 a 5V, con una resolución de 10 bits, es decir 1024 valores (0 a 1023) o lo que es lo mismo, 5mV.

Esto nos resulta de mucha utilidad para la lectura de diferentes tipos de sensores, los cuales retornan un valor de voltaje proporcional a la magnitud que están sensando, el pin nos devolverá el valor de 0 a 1023 correspondiente al voltaje recibido.

En el caso del Atmega328P que equipa a nuestro Arduino Uno, disponemos de 14 pines digitales (de los cuales 6 son compatibles con PWM) y 6 analógicos.

> <b>Muy importante!: verificar siempre con la hoja de datos de la placa que estemos utilizando, cuál es el límite de voltaje tolerable por pin, como así también el de consumo en miliamperes (mAh), esto es fundamental para un funcionamiento apropiado y seguro del micro, sin riesgos de quemar e inutilizar pines</b>.
