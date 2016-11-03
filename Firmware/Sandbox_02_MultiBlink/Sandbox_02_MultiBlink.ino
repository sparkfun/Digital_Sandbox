// Sandbox 02: Multi-Blink

/* Large arrays of LEDs are often used to create massive outdoor signs and 
   animations because they're both bright and efficient. While we don't have the 
   millions of LED pixels that a display in Times Square might have, we can 
   still create some fun patterns with the Digital Sandbox.
   
   This experiment introduces the pinMode([pin], [INPUT/OUTPUT]) function. 
   
   It also explores the subject of PINs. Pins are all uniquely numbered, and 
   each input or output component on the Sandbox is labeled with the pin number 
   it's connected to -- that's the D2, D4, D11, A1, etc. lettering next to each 
   LED, switch and sensor.
   
   When we call a pinMode or digitalWrite function, we always have to declare
   which pin we want to control. That's usually done with the literal value
   (e.g. 4, 13, 8, etc) of the pin
*/

// The setup function will allow us to set the mode of each pin to OUTPUT.
void setup()
{
	pinMode(4, OUTPUT);	// Set pin D4 as an OUTPUT
	pinMode(5, OUTPUT);	// Set pin D5 as an OUTPUT
	pinMode(6, OUTPUT);	// Set pin D6 as an OUTPUT
	pinMode(7, OUTPUT);	// Set pin D7 as an OUTPUT
	pinMode(8, OUTPUT);	// Set pin D8 as an OUTPUT
}

// The loop function will be used to blink each of our LEDs in succession.
void loop()
{
	digitalWrite(4, HIGH);	// Turn the D4 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(4, LOW);	// Turn the D4 LED off (LOW)
	
	digitalWrite(5, HIGH);	// Turn the D5 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(5, LOW);	// Turn the D5 LED off (LOW)
	
	digitalWrite(6, HIGH);	// Turn the D6 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(6, LOW);	// Turn the D6 LED off (LOW)
	
	digitalWrite(7, HIGH);	// Turn the D7 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(7, LOW);	// Turn the D7 LED off (LOW)
	
	digitalWrite(8, HIGH);	// Turn the D8 LED on (HIGH)
	delay(500);				// Wait half a second (500 ms)
	digitalWrite(8, LOW);	// Turn the D8 LED off (LOW)
}
