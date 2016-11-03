// Sandbox 06: Number Storage with Variables

/* The herky-jerky fading from experiment four accomplished the task, but just 
   think of all the values we were missing! How do we make the LED fade 
   smoothly? You can whip out 256 minutely different analogWrite() blocks, or 
   you can reduce it to one, using variables.

   Variables are like storage containers for numbers. We can put any number in a 
   variable, and either recall it and put it to use, or manipulate it to change
   the value it stores. Anywhere you stick a literal number (like "0" or "255") 
   you can instead use a variable.
*/

// To declare a variable you need two things: a type and a name. The type
// determines how much space in memory the variable takes up. The most standard
// variable type is int. int's can be either positive or negative. They take up
// 16-bits of space in your Arduino, so they can be anywhere from -32768 (2^15)
// to 32767 (2^15 - 1).
int fade;	// Decalare an int type of variable called "fade"

// Anything defined in the space _above_ setup() is GLOBAL. A global variable
// can be used in both the setup() and loop() functions. We'll want to use fade
// in both of those functions.

void setup()
{
	pinMode(5, OUTPUT);	// Set pin 5 as an OUTPUT
	
	fade = 0;	// Set fade to 0, give it an initial value
}

void loop()
{
	// Set the LED on pin 5 to the value of "fade":
	analogWrite(5, fade);
	
	// Increment fade by 1. Code math takes the value on the right side of the
	// equation, and stores it into the variable on the left side.
	// This equation says take the original value of fade, add 1 to it, and
	// store that sum in the fade variable.
	fade = fade + 1;	// Increment fade by 1
	
	delay(500); // Wait half a second
}
