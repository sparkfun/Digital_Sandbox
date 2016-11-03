// Sandbox 04: Dimming (the Easy Way)

/* Manual PWM is hard, and it doesn't leave room for anything else in the
   program. Why can't we offload that chore to the Digital Sandbox's 
   microcontroller? It's smart enough for that...right?
   
   This experiment introduces the analogWrite([pin], [0-255]) function.
   analogWrite is used to output an analog voltage on a pin. So not only can we
   output 0V and 5V, but we can also do 254 voltages in between. Need 2.5V 
   analogWrite to 128. Need 3.3V? Analog write 168.
   
   Unfortunately, not all pins can do analog output. Only pins 3, 5, 6, 9, 10, 
   and 11 have the special ability.
*/

// As usual, in setup we need to set our LED pin as an OUTPUT.
void setup()
{
	pinMode(5, OUTPUT);	// Set pin 5 to an output
}

// In loop we'll cycle the pin 5 LED through five different brightness levels
// from fully off, to dim, to half-on, to full-on. Then we go back to off and
// do it all over again.
void loop()
{
	analogWrite(5, 0);	// Sets voltage to 0V (0/255 * 3.3V). LED is off.
	delay(1000);		// Wait a second
	
	analogWrite(5, 64);	// Sets voltage to ~0.82V (64/255 * 3.3V). Pretty dim.
	delay(1000);		// Wait a second
	
	analogWrite(5, 128);// Set voltage to ~1.65V. Half-bright.
	delay(1000);		// Wait a second
	
	analogWrite(5, 192);// Set voltage to ~2.48V. Getting brighter!
	delay(1000);		// Wait a second
	
	analogWrite(5, 255);// Set voltage to 3.3V. Fully on (turn down for what!?).
	delay(1000);		// Wait a second
}
