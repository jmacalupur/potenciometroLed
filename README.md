# Entendiendo los puertos Analógicos

En este proyecto aprenderemos qué es un Puerto Analógico de un Arduino, qué es un potenciómetro y ensamblar un sistema con él.

# ¿Qué es un puerto analógico?
Es un puerto que recibe una señal directa que va a representar cómo se está comportando un sensor frente a un fenómeno. Por ejemplo: La luz, la temperatura, el movimiento, etc. 

Estos puertos se encuentran limitados por la resolución. Los puertos analógicos de Arduino UNO tienen una resolución de 10 bits, es decir, cuando mide un dato, nos puede devolver valores entre 0 y 1023. 

Existen otros modelos con mayor o menor resolución. Depende del tipo de dato y escala del proyecto que llevaremos a cabo. 

Nota: El Arduino UNO sólo cuenta con seis entradas analógicas (A0, A1, ..., A5), no con salidas. Si bien existen salidas PWM que pueden funcionar como salidas analógicas desde pines digitales, no son puras. Existe otro arduino que sí posee salidas analógicas, pero es sólo para audio. Esto nos da la idea de los límites que tiene Arduino. 

# ¿Qué es el potenciómetro?
Es un elemento que nos proporciona resistencias variables en el sistema para que obtengamos diferentes niveles de voltajes, mientras modificamos la posición del regulador.

En cristiano, nos permite variar el voltaje a medida que lo regulamos.

El potenciómetro que más nos encontraremos en los proyectos es el de 10KΩ. 

Normalmente cuenta con tres salidas:

- A: voltaje de operación. Se conecta en el polo positivo.
- B: voltaje de salida . Quiere decir que sale la señal del potenciómetro hacia la entrada del Arduino.
- C: salida a tierra. Se conecta a tiera.

![](https://github.com/jmacalupur/potenciometroLed/blob/develop/01potenciometro.JPG)

# Armando el proyecto

El proyecto que vamos a ensamblar, constará de un Led que se encenderá y apagará durante un lapso de tiempo, y que dicho tiempo variará respecto al valor obtenido al girar el potenciómetro. Recordemos que el valor variará de 0 a 1023. 

# Materiales y Equipos

- Laptop con el IDE Arduino instalado
- Protoboard
- Placa Arduino UNO
- Potenciómetro
- Cables macho
- LED
- Resistencia de 220Ω (Puedes ver el porqué en mi proyecto [helloLed](https://github.com/jmacalupur/helloLed).)
- Cable USB-B 

# Procedimiento

1. Presentamos el diseño del Arduino que realicé en Tinkercad:

![](https://github.com/jmacalupur/potenciometroLed/blob/develop/02arduinoSimulador.png)

2. Luego lo procedemos a armar:

![](https://github.com/jmacalupur/potenciometroLed/blob/develop/03arduinoFisico.JPG)

En la foto no se visualiza bien las conexiones. Pero los colores están conectados a los siguientes puertos:

- Rojo: 		conectado en puerto 5v
- Azul: 		conectado al puerto GND
- Amarillo: 	conectado al puerto A0
- Naranja: 	conectado al puerto 3


3. Ahora viene el código. Primero la configuración. Como verán a continuación podemos asignar variables para "softcodear" nuestro código. Depende de cómo te sientas cómodo, pero es una buena práctica, a fin de que si cambias, por ejemplo el puerto del led de 3 a 2, sólo tendrías que cambiar el valor de la variable.

```
int ledRojo = 3; //asignamos a la variable ledRojo el valor de 3
int potPin = A0; //asignamos a la variable potPin el valor de A0
int potValue = 0; //asignamos a la variable potValue un valor de 0

void setup() {
pinMode(ledRojo, OUTPUT); //indicamos que el puerto "ledRojo" es de salida
}
```

4. Ahora el código de ejecución. Podrás ver que he colocado una descripción en cada línea para un mayor detalle:

```
void loop() {
potValue = analogRead(potPin); //asignamos a la variable potValue el valor que leerá el puerto A0 (de 0 a 1023)
digitalWrite(ledRojo, HIGH); //escribimos el valor HIGH (o encendido) en el led.
delay(potValue); //damos una demora que es igual al valor de potValue (de 0 a 1023)
digitalWrite(ledRojo, LOW); //escribimos el valor LOW (o apagado) en el led.
delay(potValue); //damos una demora que es igual al valor de potValue (de 0 a 1023)
}
```

5. Luego subimos el código al arduino y ¡a probar!. Si no sabes cómo subir el código al Arduino, puedes ver el siguiente tutorial donde explico un poco la funcionalidad de Arduino en [helloLed](https://github.com/jmacalupur/helloLed).


6. Si giramos el potenciómetro puedes cambiar la frencuencia de encendido y apagado del led. 

![](https://github.com/jmacalupur/potenciometroLed/blob/develop/03arduinoFisico.JPG)

Eso es todo. Ahora ya sabes:

1. Puertos analógicos.
2. Definición de un potenciómetro.
3. Usar el potenciómetro en Arduino.


