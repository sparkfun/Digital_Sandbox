// Sandbox 16: Servo Sweeper

/* DC motors are great for spinning an object at high speed with no regard for 
   where it starts or stops. For many applications, though, it’s important to 
   precisely control the position of a motor. Wing flaps in a plane, steering 
   mechanisms in RC cars, and robotic arm platforms are applications that 
   benefit from motorized position control. For those applications we ditch the 
   DC motor and whip out the servo!

   This is the first experiment where you'll import an external library. In this
   case we'll be using the Servo library. Follow the comments as we show how the
   library is included and then used.
*/

// Servos are controlled using the Servo LIBRARY. To include a library, use the
// #include "library" statement.
#include <Servo.h>	// Include the servo library

// To use the servo library, we need to create an instance of the Servo class.
// This is like creating a variable of type "Servo". We can call our servo 
// anything -- in this case we'll call it "myServo"
Servo myServo;	// Create an instance of the servo library

// Create variables for our input and ouput components:
const int switchPin = 2;	// Switch is connected to pin 2
const int slidePin = A3;	// Slide pot is connected to A3
const int servoPin = 3;		// Servo is connected to pin 3

void setup()
{
	// Set the switch and slide pot pins as INPUTS.
	pinMode(switchPin, INPUT);
	pinMode(slidePin, INPUT);
	
	// To use the myServo object we created above, we need to attach it to a
	// pin. Use the attach function, and use servoPin as the pin value.
	myServo.attach(servoPin); // Attach the myServo object to our servoPin:
}

void loop()
{
	if (digitalRead(switchPin))	// If the switch is in the "1" position:
	{
		// Read in the value of the slide pot, and map it to our servo's
		// position range (0-180):
		int angle = map(analogRead(slidePin), 0, 1023, 0, 180);
		
		// Use the write function to set the angle of the servo:
		myServo.write(angle);
	}
}
