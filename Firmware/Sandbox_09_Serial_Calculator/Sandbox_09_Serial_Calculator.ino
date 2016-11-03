// Sandbox 09: Serial Calculator

/* While you probably can't have a very stimulating conversation with the 
   Digital Sandbox, it can send you some very interesting information. It's 
   great at math, so let's have the Sandbox do some calculating for us! Trouble 
   is, how do we get it to print numbers (without Morse code)? Enter serial 
   communication!

   This experiment introduces Serial Communication. New functions include
   Serial.begin() and Serial.println(). Serial is a form of data transmission 
   where we can send a string of 1's and 0's between two devices and actually 
   form a set of characters. So 01101000 01100101 01101100 01101100 01101111 
   00101100 00100000 01110111 01101111 01110010 01101100 01100100 becomes 
   "Hello, world."
*/  

// Let's create a base value to do math on. This time, we'll use the "long"
// variable type -- a 32-bit variable, which can be anywhere from 
// -2,147,483,648 to 2,147,483,647.
long multiplier = 1;

void setup()
{
	// To initialize serial communication, we need to use the Serial.begin()
	// function. The number inside the function determines the baud rate -- the
	// communication speed. 9600 is a very standard, default speed. Good for
	// most debugging.
	Serial.begin(9600);
	
	// Serial.println() is used to print a message out to the serial monitor
	// you can print variables, or static text defined inside quotes ("").
	Serial.println("Powers of 2!");
}

void loop()
{
	if (digitalRead(12) == HIGH)	// If the button is pressed
	{
		// On top of printing static messages (embedded inside quotes), we can
		// also print the value of variables.
		Serial.println(multiplier);
		
		// Multiply the multiplier variable by 2. To multiply we use the 
		// asterisk (*) character.
		multiplier = multiplier * 2;
			
		delay(250);	// Short delay for visibility on the serial monitor.
	}
}
