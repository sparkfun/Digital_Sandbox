// Sandbox 13: Sound Detecting

/* Introducing the fabulously groundbreaking SOUND (Sandbox’s Over/Under Nominal 
   Decibels) System! Microphone check 1..2..1..2. With the SOUND you’ll always 
   have an adjustable sound level detector handy!

   In this experiment we’ll use the Sandbox’s on-board microphone to measure 
   volume levels and display them on the LEDs. The microphone produces a sound 
   wave, which is just another analog voltage that we can measure. The louder 
   the sound, the higher the amplitude of the wave and the larger the voltage.
   
   This sketch introduces the concept of arrays. Arrays are a collection of 
   variables, which can all be accessed and manipulated with a single variable
   name. To keep track of which variable within the array is being called, we
   use an index.
   
   We also use for loops for the first time in this experiment. For loops are a
   looping construct we use to run a block of code for a specified number of
   iterations. Instead of looping indefinitely, like we do with the loop()
   function, a for loop allows us to loop five, ten, twenty...however many times
   we need.
*/

const int slidePin = A3;	// A constant variable to store our slide pot pin
const int micPin = A2;		// A constant variable to store our microphone pin

// Now let's create an ARRAY of variables. An array is a collection of variables,
// all referenced with an array name and an INDEX. This is how we create an
// array containing 5 values:
const int ledPins[5] = {4, 5, 6, 7, 8};
// Our array is called "ledPins". Each value in the array can be referenced
// using a specific index, called within the square brackets directly following
// the array name. The index STARTS AT 0.
// For example, ledPins[0] is 4, ledPins[1] is 5, and ledPins[4] is 8 (the last
// value in the array).

void setup()
{
	// Set up our mic and slide pot pins as INPUTs
	pinMode(slidePin, INPUT);
	pinMode(micPin, INPUT);
	
	// Now let's use a for loop to set each ledPins as an input.
	// There are three parts to defining a for loop: (1) variable declaration,
	// (2) a test (like an if statment), (3) increment. As long as the test
	// returns true, we continuously run through the for loop. Each time through
	// the loop, the increment part happens. Eventually we want to exit the for
	// loop after everything we need to happen has happened.
	// In this example, we create a variable, i, and set it to 0. Each time 
	// through the loop we increase i by 1 (i++). At that point, if i is bigger
	// than 5, we exit the for loop.
	// We can also use the variable declared in the for loop. In this case we
	// use it to index the array. Arrays and for loops work hand-in-hand.
	for (int i=0; i<5; i++)
	{
		// First time through, set ledPins[0] (pin 4) to OUTPUT
		// 2nd time through, set ledPins[1] (pin 5) to OUTPUT
		// ...
		// 5th time through, set ledPins[4] (pin 8) to OUTPUT)
		// Then exit the for loop because i >= 5.
		pinMode(ledPins[i], OUTPUT);
	}
}

void loop()
{
	int maximum = analogRead(slidePin);	// Read the slide pot sensor into a var
	int micReading = analogRead(micPin);	// Read the microphone value in
	
	// Again, we'll use a for loop to cycle through each LED in the ledPins
	// array.
	for (int i=0; i<5; i++)
	{
		if (micReading > ((maximum / 5) * (i+1)))
		{	// If the microphone reading is greater than a scaled value
			digitalWrite(ledPins[i], HIGH);	// Turn on that LED
		}
		else
		{	// Otherwise, turn off that LED
			digitalWrite(ledPins[i], LOW);
		}
	}
}
