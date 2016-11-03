// Sandbox 08: Reaction Tester

/* Computers are great at doing math and automating boring tasks, but everyone 
   knows that their _true_ purpose is to play games. Let's create a game on the 
   Digital Sandbox! In order to control the game we need to add **input**.
   
   Up to this point, our Digital Sandbox experience has been very one-sided. 
   _Output_ to tiny yellow LEDs. _Output_ to larger white LEDs. _Output_ to RGB 
   LEDs. Change the fade value of the _output_. Output, output, output. Let's 
   flip the tables on the Sandbox, and send some **input** to the board!
   
   This experiment introduces the digitalRead([pin]) function. This is the first
   time we'll use a function that RETURNS A VALUE. Instead of simply creating a
   function call and going to the next line, we need to do something with the
   function -- either assign it to a variable or use it in a conditional.
*/

// The led variable should run between 4 and 8. It's used to control the white
// leds (D4-D8), one at a time.
int led = 4;
// The speed variable controls how fast the LEDs cycle from one to the next.
// A larger value, means a slower cycle.
int speed = 100;

// setup()! Time to set up some OUTPUTs...and INPUTs!
void setup()
{
	// Set the button and switch as INPUTs:
	pinMode(2, INPUT);
	pinMode(12, INPUT);
	
	// Set all LEDs as outputs:
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
}

void loop()
{
	// The first if statement sets the SPEED of the game.
	// digitalRead() can either return HIGH or LOW. If the switch is in the "1"
	// position, the digitalRead() function will return HIGH.
	if (digitalRead(2) == HIGH)	// If the switch is set to 1...
	{
		speed = 50;				// ...set speed to 50 (fast)
	}
	else						// Else the switch will be set to 0...
	{
		speed = 150;			// ...so set the speed to 150 (slow)
	}
	
	// The button on pin 12 will be HIGH when pressed and LOW otherwise.
	if (digitalRead(12) == HIGH)	// If the button is pressed
	{
		digitalWrite(led, HIGH);	// Turn the active LED on, nothing else.
	}
	else							// Otherwise, if the button is released
	{
		digitalWrite(led, LOW);		// Turn the active LED off.
		
		led = led + 1;				// Increment the led variable by 1
		if (led > 8)				// If led is out of our range (4-8)
		{
			led = 4;				// Set it back to the bottom (LED 4).
		}
		
		digitalWrite(led, HIGH);	// Turn on the new LED
		
		delay(speed);				// Delay for speed ms.
	}
	
	// The else statement above will take up the majority of the loop() if the
	// button is released. One LED will turn off, the next will turn on, and
	// a short delay will occur before we loop back.
}
