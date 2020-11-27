<h1><b>FUNDACION INSTITUTO TECNOLOGICO RAFAELA</b></h1>
<h2><b>Taller Arduino Adultos 2020</b></h2>

<h3>Fundamentos</h3>

<b>Corriente eléctrica</b>: movimiento de cargas eléctricas desde un generador o fuente hacia un componente destino, a través de un circuito conductor. Para originar este movimiento, es necesario que en la fuente se produzca una fuerza electromotriz que cree una diferencia de potencial entre los terminales.

<b>Voltaje</b>: es la diferencia de potencial o tensión, medida en voltios (V).

<b>Intensidad</b>: es el volumen de electricidad que circula en un conductor por unidad de tiempo, medida en amperes (A).

<b>Resistencia</b>: es la dificultad que ofrece el conductor al paso de la corriente eléctrica, medida en ohmios (R, Ω).

<h3><a href="https://tuelectronica.es/que-es-la-ley-de-ohm-y-como-se-aplica/" target="_blank">Ley de Ohm</a></h3>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/4c/Ley_de_ohm_-_Organigrama.jpg/250px-Ley_de_ohm_-_Organigrama.jpg">

Ley fundamental de los circuitos eléctricos, que postula las relaciones existentes entre la diferencia de potencial aplicada (V), la intensidad de corriente circulante (I) y la resistencia (R) de un circuito. Establece que:

<b>la intensidad de corriente (I) que atraviesa un circuito, es directamente proporcional al voltaje (V) aplicado, e inversamente proporcional a la resistencia (R) del mismo</b>

Con esta expresión, podremos fácilmente calcular cualquier magnitud a partir de las 2 restantes, manteniendo una condición de equilibrio en el circuito.

<h3><b>Microcontroladores</b></h3>

La electrónica de <b>microcontroladores</b>, opera con circuitos de <b>corriente continua</b>, siendo los <b>voltajes habituales 3.3 y 5V</b>. Es esencial tener siempre presente la polaridad para evitar conexiones inadecuadas, como así también los límites de voltaje y amperaje que tolera el micro y los distintos elementos que estaremos utilizando, para evitar sobrecargas, mal funcionamiento y voladuras de componentes.

Un <b>microcontrolador</b>, como se mencionó, trabaja con valores de <b>alimentación de 3.3 o 5V, con la posibilidad de manejar niveles reducidos de mAh por pin (normalmente de 20, 30 o 40 mAh máximo</b>), por lo cual siempre es <b>FUNDAMENTAL verificar ambas cosas antes de comenzar a trabajar</b>, tanto el voltaje de operación como el límite de amperaje que puede tolerar cada pin y el conjunto.

Mayores detalles sobre límites de corriente en Arduino:
[https://playground.arduino.cc/Main/ArduinoPinCurrentLimitations](https://playground.arduino.cc/Main/ArduinoPinCurrentLimitations)

<h3><b>Conexiones en serie y en paralelo</b></h3>

<img src="https://idux.net/itec/arduino/imgs/con_serie.gif" width="250">

<b>Conexión en serie</b>: cuando un componente es conectado a continuación de otro, el mismo valor de corriente circulará por los distintos elementos. <b>La resistencia total del circuito será igual a la suma de las resistencias parciales</b>, con lo cual en el gráfico si cada foco tiene una R de 10k (R total 20k), la I será 9 / 20 = 0,45 mAh y la pot de 4,05 mW.

<img src="http://www.mundostreaming.tv/itec/arduino/imgs/con_paralelo.gif" width="250">

<b>Conexión en paralelo</b>: en este caso todos los componentes son alimentados al mismo tiempo (terminales de entrada y de salida unidos entre sí), cada uno limita su propia corriente. <b>La resistencia total del circuito será la inversa de la suma de las resistencias parciales</b>, (1/RT = 1/R1 + 1/R2), con lo cual en el gráfico la R total será 1/RT = 1 / 10 + 1 / 10; 1/RT = 0,2; RT = 1 / 0,2 = 5, la I será 9 / 5 = 1,8 mAh y la pot de 16,2 mW.

<p>&nbsp;</p>

<h3>Componentes electrónicos tradicionales</h3>

Siempre resulta útil un repaso de los componentes analógicos de uso común, que vemos en todo circuito pero muchas veces olvidamos su comportamiento básico. En el caso de Arduino, al utilizar placas preensambladas, no tendremos necesidad de soldar desde cero este tipo de elementos, pero es bueno tener frescos los detalles de cada uno para entender su utilidad cuando deseemos ensamblar placas más personalizadas:

<b>Resistencia</b>

<b>La resistencia es un elemento pasivo que se opone al paso de corriente, permitiéndonos por lo tanto controlar voltaje y corriente en nuestros circuitos</b>. Puede conectarse indistintamente en uno u otro sentido, es decir, no tiene polaridad, y su medida se expresa en Ohms. Existen de tipo <i>fijo</i> como <i>variable</i>, también tenemos <i>especiales</i> dedicadas a distintos sensores.

<img src="https://ardronics.files.wordpress.com/2016/01/tipos-de-resistencias1.jpg?w=320&h=204" width="400">

Dentro de las <i>fijas</i>, las de carbón son las que encontraremos en cualquier casa de electrónica y podremos soldar fácilmente a nuestras placas. Estas resistencias utilizan una codificación de colores para identificar su tamaño, obtendremos las equivalencias en muchas calculadoras online, como por ejemplo:

<a href="https://es.rs-online.com/web/generalDisplay.html?id=infozone/calculators&file=4band">Calculadora online resistencias carbón</a>

También tenemos las de <i>superficie</i>, las que en lugar de codificación de colores emplean una numérica, que puede ser de varios tipos, pero como el caso anterior, es fácil recurrir a una calculadora si no se recuerda un código específico:

<a href="https://www.inventable.eu/2014/07/05/como_se_leen_las_resistencias_smd/">Lectura códigos resistencias superficie</a>

<b>Especiales</b>

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/a2/Fotocelda.jpg/200px-Fotocelda.jpg" width="200">

Diversos sensores, utilizan una resistencia para medir la variación de la magnitud, un caso típico es el de los <i>LDR o fotorresistores</i>, que varían su resistencia en función de la cantidad de luz que incide sobre ellos, modificando por ende el voltaje en su salida.

<b>Potenciómetro</b>

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Potentiometer.jpg/245px-Potentiometer.jpg" width="250">

<b>El potenciómetro es también una resistencia, pero que puede ser regulada para modificar su salida</b>. Existen diversos tipos, tanto de <i>regulación por rotación como por deslizamiento, de tipo lineal, logarítmico, antilogarítmico y otros</i>. Más info en <a href="http://ziickpaininfiniteoo.blogspot.com/2011/11/potenciometro.html">tipos de potenciómetros</a>. Es un elemento de gran utilidad para disponer de una posibilidad de regulación física dentro del esquema del circuito, a veces también cumple funciones más activas como por ejemplo en la operación de pequeños servomotores y otros.

<a href="https://es.wikipedia.org/wiki/Condensador_el%C3%A9ctrico"><b>Capacitor o condensador</b></a>

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b9/Capacitors_%287189597135%29.jpg/1200px-Capacitors_%287189597135%29.jpg" width="300">

<b>El capacitor es también un elemento pasivo, que puede almacenar energía sustentando un campo eléctrico</b>.

El tipo más común es el <i>electrólítico (diseño cilíndrico)</i>, <b>que tiene polaridad!</b>, debemos siempre prestar atención al momento de conectarlo ya que lo inutilizaremos si lo hacemos al revés (en uno de sus laterales tendrá una línea de marca que indicará el polo negativo). El otro tipo habitual, <i>cerámico</i> (formato estilo lenteja), <i>no es polarizado</i>.

Al recibir voltaje, durante un breve período, fluirá corriente que se acumulará en sus placas. Si se desconecta luego el voltaje, la carga y tensión asociada se conservarán por un período de tiempo, que dependerá del valor del capacitor. La unidad utilizada es el <i>Faradio</i> (uF = microfarados, pF = picofaradios, nF = nanofaradios). Además de su valor de capacidad, es importante considerar su límite de voltaje, con un cierto margen. Así, si tenemos por ej un circuito operando a 12V, podremos utilizar sin problemas un capacitor de 16V; en cambio si tenemos otro trabajando a 24V y aplicamos un capacitor digamos de 25V, estaremos al límite y lo más conveniente será pasar a uno de igual valor de Faradios pero mayor límite de voltaje (50V por ej).

Permite, por ende, equilibrar los consumos de nuestro circuito, ya que puede cargarse y descargarse de manera instantánea según se requiera.

<b>Switch de encendido</b>

<img src="https://www.shoptronica.com/12993-large_default/micro-interruptor-deslizante-recto-2235-2c-3-posiciones.jpg" width="200">

Otro elemento super sencillo pero que siempre debemos tener a mano, un switch deslizable. Existen de gran variedad de tamaños, todos bajo el mismo concepto de uso, lo aplicaremos en serie en una de las líneas de alimentación, utilizando el punto común central y uno de los extremos, en una posición cerrará el circuito y en la otra quedará abierto, actuando como llave de encendido.

<b>DIP switch</b>

<img src="http://www.geekbotelectronics.com/wp-content/uploads/2014/07/dip-switch-8.png" width="200">

El switch tipo DIP se emplea para dotar al circuito de opciones de configuración rápidas, podremos colocar de mayor o menor cantidad de pines, de acuerdo al número de alternativas que necesitemos. Según la posición on / off de cada pin, podremos llegar a una determinada variedad de configuraciones. Al iniciar la ejecución del código, leeremos fácilmente la configuración actual del switch y cargaremos la lógica que corresponda.

<b>Diodo semiconductor</b>

<img src="http://cdn.shopify.com/s/files/1/0409/9041/products/77db2f15edfe3a730220f5e6c104e364_grande.jpeg?v=1407378892" width="200">

El tradicional diodo semiconductor, tal cual lo indica su nombre, solo permite circulación de corriente en un sentido (hacia la marca indicada en uno de sus lados, de ánodo a cátodo). Esta condición permite aprovecharlo como dispositivo de protección para impedir que la corriente circule en sentido no deseado, o también como elemento rectificador, en el caso de los <a href="https://es.wikipedia.org/wiki/Puente_rectificador">puentes de diodos</a>.

En el caso de Arduino, si necesitamos por ejemplo conmutar un circuito que opera con voltaje superior al límite soportado por los pines del microcontrolador, y queremos evitar cualquier sorpresa desagradable con corriente de mayor valor fluyendo hacia la placa Arduino, aplicaremos un diodo de este tipo entre él y el dispositivo de mayor consumo, que nos servirá como seguro.
