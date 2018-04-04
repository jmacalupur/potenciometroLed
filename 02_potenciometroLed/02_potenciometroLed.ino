int ledRojo = 3;
int potPin = A0;
int potValue = 0;

void setup() {
pinMode(ledRojo, OUTPUT); //indicamos que el puerto "ledRojo" es de salida
}

void loop() {
potValue = analogRead(potPin); //asignamos a la variable potValue el valor que leerá el puerto A0 (de 0 a 1023)
digitalWrite(ledRojo, HIGH); //escribimos el valor HIGH (o encendido) en el led.
delay(potValue); //damos una demora que es igual al valor de potValue (de 0 a 1023)
digitalWrite(ledRojo, LOW); //escribimos el valor LOW (o apagado) en el led.
delay(potValue); //damos una demora que es igual al valor de potValue (de 0 a 1023)
}
