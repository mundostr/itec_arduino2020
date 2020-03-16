<h1><b>FUNDACION INSTITUTO TECNOLOGICO RAFAELA</b></h1>
<h2><b>Taller Arduino Adultos 2020</b></h2>

<h3>Ejercicios en TinkerCAD</h3>

Para pruebas virtuales, utilizaremos el simulador online TinkerCAD de Autodesk, una herramienta completamente gratuita y muy cómoda para el aprendizaje en el aula.

### Comenzar con TinkerCAD

Para poder comenzar a trabajar con la herramienta, será necesario registrarse de forma gratuita en el sistema de Autodesk. Para ello se debe visitar la página <a href="https://tinkercad.com/join">https://tinkercad.com/join</a> y crear de forma gratuita una cuenta utilizando la opción "Create a personal account", la cual permitirá elegir entre crear una cuenta desde cero, ingresando un email de referencia, o bien hacerlo directamente con los datos de Google. Autodesk solicitará una confirmación de identidad enviando un código de verificación por SMS, por lo cual será necesario indicar un número de teléfono válido en el registro.

<p>Una vez obtenida la cuenta, se podrá ingresar al Dashboard en <a href="https://tinkercad.com/dashboard" target="_blank" rel="noopener">https://tinkercad.com/dashboard</a> y desde allí a la opción "Circuits" para crear un nuevo circuito.</p>

<p>Cada nuevo circuito creado aparecerá en el Dashboards (dentro de la opción Circuits) y se podrá editar todas las veces que se desee. A efectos de guardar copia de los diferentes ejercicios que se vayan realizando, la sugerencia es crear un nuevo circuito para cada uno de ellos, si bien, por supuesto, se puede ir actualizando también sobre el mismo.</p>

<p>El uso del editor de circuitos es sumamente simple:</p>

<ol>
	<li>En la parte superior se podrá colocar un nombre identificatorio (por defecto aparecerá uno autogenerado).</li>
	<li>Debajo se verán íconos para Rotar, Borrar, Deshacer, Rehacer, Colocar nota y Mostrar / Ocultar componentes.</li>
	<li>En la columna derecha se podrá ver una lista gráfica de todos los componentes disponibles, con la opción de filtrarlos por diferentes tipos o buscar por coincidencia de nombre.</li>
	<li>Para armar circuitos, basta con elegir componentes de la zona derecha y arrastrarlos hacia la izquierda.</li>
	<li>Los componentes podrán conectarse con otros mediante los pines disponibles, clickeando con el mouse y arrastrando el cable que se genera hacia el destino de la conexión.</li>
	<li>Cuando se desee simular el funcionamiento del circuito, se puede iniciar la secuencia con el botón "Start Simulation" de la zona superior, si bien el soporte de este simulador no es avanzado, permite realizar muchas pruebas útiles en el aprendizaje.</li>
	<li>El botón "Code" estará habilitado cuando se utilice una placa programable como el Arduino UNO, y permitirá ingresar el mismo código base C/C++ empleado en el Arduino IDE. Como alternativa, se podrá también diseñar el código mediante bloques visuales, lo cual resulta muy práctico para estudiantes en sus primeros pasos de programación, ya que permite abstraer el trabajo de la sintaxis y los detalles de texto del lenguaje, enfocándolo específicamente en la lógica del programa.</li>
</ol>

## Ejercicios

### 01- Encendido y parpadeo de led

El primer ejercicio super tradicional, y con el cual ya hemos trabajado en las primeras pruebas físicas con el Arduino UNO, es el parpadeo de un led. El UNO, como la mayoría de las placas de desarrollo actuales, incluye ya un led conectado a uno de sus pines, algo cómodo para pruebas. Precisamente es éste led el que hemos estado utilizando, unido al pin digital 13, pero obviamente podemos conectar también un led externo a ese mismo pin, o a cualquier otro de los digitales que tengamos disponible.

<ol>
	<li>
		Agregar un Arduino UNO, un led y una resistencia, conectándolos según el siguiente esquema: <img src="/ejercicios/tinkercad_ej001.png">
	</li>
	<li>
		Podemos ver que del pin 13 del Arduino, conectamos una resistencia de 220 ohms (el valor se puede modificar pulsando sobre la resistencia, como cualquier otro componente) hacia uno de los pines del led. Del otro pin conectamos un cable hacia GND (ground = tierra) en el Arduino, para cerrar el circuito.
		(Generar cables: recordar que al pulsar sobre cualquier pin de un componente, se iniciará el tirado de un cable hasta el destino que se desee, se deberá volver a pulsar en ese momento para cortarlo. Si se quiere, para mejor orden visual, se pueden cambiar los colores de los cables pulsando sobre los mismos).
	</li>
	<li>
		Una vez armado el circuito, pulsar Start Simulation para iniciar la simulación. El led debería parpadear 1 vez por segundo, al mismo tiempo que el led rectangular incorporado en la placa, ya que están conectados ambos al pin 13. Este parpadeo se da porque al arrastrar el Arduino UNO al circuito, se copia de forma predeterminada un ejemplo de parpadeo.
	</li>
	<li>
		Ingresar al botón Code, y probar diferentes cambios para familiarizarse con el circuito, tal cual se realizó en clase, por ejemplo utilizar distintos tiempos de parpadeo, ejecutar el parpadeo solo una determinada cantidad de veces, ejecutarlo después de cierto tiempo de encendida la placa, etc. Recordar que además del código de texto, se puede utilizar el editor gráfico por bloques para mayor comodidad.
	</li>
	<li>
		La resistencia de 220 ohms permite regular el valor de corriente que circula hacia el led, probar el circuito conectando el led de forma directa entre el pin 13 y GND. Qué advertencia aparece?, Por qué?, charlaremos en clase sobre el tema.
	</li>
</ol>
