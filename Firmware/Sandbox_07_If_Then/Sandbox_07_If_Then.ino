// Sandbox 07: If This Then That

/* Fading from the last experiment was working just fine until we got to the 
   maximum brightness level of 255. What happens then is a mystery known only to 
   the compiler (and you, once you learn a little something about data types). 
   What if we added “catch” to force that fade variable to reset when it hits a 
   certain value?

   This experiment introduces the if statement, one of the most fundamental 
   programming structures around. Not only are if statements important for 
   computers, they also rule most of the decisions we make in our lives: If it’s 
   cloudy outside, then pack your umbrella. If you’re hungry, then make a 
   sandwich. Like us, computers use if statements to make choices.
*/

int fade = 255;	// Create a global variable, fade, set it to 255.

// setup() set's up our LED on pin 10
void setup()
{
	pinMode(10, OUTPUT);	// Set pin 10 as an OUTPUT
}

// loop() uses the fade variable to set the brightness of the LED. Each time
// through loop we decrease fade by 1. An if statement checks to make sure we
// don't set fade too low.
void loop()
{
	fade = fade - 1; // Decrease fade by 1
	
	if (fade < 0)	// If fade is less than (<) 0, execute the code inside
	{
		fade = 255;	// Set fade back to 255 (top value)
	}
	
	analogWrite(10, fade); // Write the fade variable out to pin 10.
	
	delay(10);	// Wait 10 ms (1/100th of a second)
}
