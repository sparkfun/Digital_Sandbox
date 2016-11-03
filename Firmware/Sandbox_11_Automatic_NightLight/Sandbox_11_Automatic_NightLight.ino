// Sandbox 11: Automatic Night Light

/* We now have all the programming tools we need to make some totally awesome, 
   interactive projects. Let’s incorporate the light sensor - another analog 
   input component - to create an automatic night light that turns on when it’s 
   dark.

   This experiment continues on with the analogRead() function. This time we're
   going to do something with the analog value! When the output from the light
   sensor gets too low, we'll automatically turn on some LEDs.
   
   If your light sensor isn't triggering correctly, check the output of the
   Serial Monitor to see if there's a better value for the dark variable than
   we've set.
*/

// A const variable is a variable that can't be changed once it's declared.
// The dark variable determines when we turn the LEDs on or off. If the light
// sensor reading is less then or equal to dark, turn the LEDs on. If it's
// greater than, then turn the LEDs off.
const int dark = 10;

void setup()
{
	// Set A1 as an INPUT
	pinMode(A1, INPUT);
	
	// Set our LED pins (4 and 8) as outputs:
	pinMode(4, OUTPUT);
	pinMode(8, OUTPUT);
	
	// Initialize Serial, set the baud rate to 9600 bps.
	Serial.begin(9600);
}

void loop()
{
	// Create a variable, and store the light sensor reading into it:
	int lightValue = analogRead(A1);
	
	// Print the reading from the light sensor:
	Serial.println(lightValue);
	
	// Compare the light sensor value to our dark constant variable.
	if (lightValue <= dark)	// If the light sensor reading is less then "dark"
	{
		digitalWrite(4, HIGH);	// Turn on LED 4
		digitalWrite(8, HIGH);	// Turn on LED 8
	}
	else					// Otherwise, if "lightValue" is greater than "dark"
	{
		digitalWrite(4, LOW);	// Turn LED 4 off
		digitalWrite(8, LOW);	// Turn LED 8 off
	}
	
	delay(100);	// Delay for serial monitor visibility.
}
