// Sandbox 01: Exploring Blink

/* When faced with a new platform, a coder’s first task is to write a “Hello, 
   world” program. Usually a “Hello, world” program actually prints those 
   comforting words on a screen. The Digital Sandbox doesn’t give us a screen to 
   print words on, but we do have LEDs! Wonderful, blinky, bright, shiny LEDs. 
   Instead of printing words, let’s blink an LED to say “Hello, world.”

   This experiment introduces some of the most basic functions in the Arduino
   language: digitalWrite([pin], [HIGH/LOW]) and delay([milliseconds]).
   Used together, these functions can be used to control an LED and time!
*/

// Nothing to do in the setup this time. But the function still has to be there!
void setup()
{
}

// Our loop function will blink the LED over-and-over-and-over.
void loop()
{
	digitalWrite(13, HIGH);	// Set pin 13 HIGH (3.3-5V)
	delay(1000);			// Wait 1000 ms (1 second)
	digitalWrite(13, LOW);	// Set pin 13 LOW (0V)
	delay(1000);			// Wait 1000 ms (1 second)
}
