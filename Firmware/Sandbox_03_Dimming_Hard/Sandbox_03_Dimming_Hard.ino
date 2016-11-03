// Sandbox 03: Dimming (the Hard Way)

/* Yikes! Those white LEDs are blindingly bright! Is there any way to dim them? 
   (Unless one of your hobbies is staring into the sun, we recommend putting a 
   piece of paper over the LEDs in this experiment...or wear sunglasses.)
   
   This experiment explores the concept of pulse-width modulation (PWM). PWM
   is used to dim LEDs, vary motor speeds, and control all sorts of other
   components.
   
   In this experiment, we code in PWM the hard way -- manually.
*/

// In setup() we need to set our LED pins to OUTPUTs.
void setup()
{
	pinMode(5, OUTPUT);	// Set pin 5 as an OUTPUT
	pinMode(6, OUTPUT);	// Set pin 6 as an OUTPUT
}

// We run through loop() really fast! For 10% of the time the D5 LED is on
// and D6 is off. For the other 90% of the time, D5 is off and D6 is on.
void loop()
{
	// The 10%
	digitalWrite(5, HIGH);	// Turn D5 LED on
	digitalWrite(6, LOW);	// Turn D6 LED off
	delay(1);				// Wait 1ms
	
	// The 90%
	digitalWrite(5, LOW);	// Turn D5 LED off
	digitalWrite(6, HIGH);	// Turn D6 LED on
	delay(9);				// Wait 9ms
}
