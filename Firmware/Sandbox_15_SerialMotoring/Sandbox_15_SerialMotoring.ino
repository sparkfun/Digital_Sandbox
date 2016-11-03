// Sandbox 15: Serial Motoring

/* Motors make the world go round. Well, not literally, but they make a lot 
   things we use every day spin and actuate. There are tiny vibration motors in 
   cell phones, speedy motors that spin CDs and Blu-Ray discs, and of course, 
   massive engine motors that help propel our cars. In this experiment we’ll 
   explore one of the most fundamental motor types out there - DC motors - and 
   we’ll tell the Sandbox precisely how fast we want the motor to spin.

   In this experiment we'll use analog output to control a motor. We can PWM 
   them just like we do to dim LEDs.
   
   We'll also be exploring the subject of Serial input. In addition to Serial
   printing out to the serial monitor, we'll be reading data in from it too. To
   do that we'll use Serial.available() to check if any data is there, and
   Serial.parseInt() to read it in.
*/

const int slidePin = A3;	// Slide pot is connected to A3
const int motorPin = 3;		// DC motor is connected to pin 3
const int buttonPin = 12;	// Button is connected to pin 12

void setup()
{
	pinMode(slidePin, INPUT);	// Set the slide pot as an input
	pinMode(buttonPin, INPUT);	// Set the button as an input
	
	pinMode(motorPin, OUTPUT);		// Set the motor as an output
	digitalWrite(motorPin, LOW);	// Turn the motor off.
	
	Serial.begin(9600);	// Initialize serial, set the baud rate to 9600
}

void loop()
{
	// Serial.available() will return 0 if nothing has been sent to the serial
	// monitor.
	// If one or more characters have been sent to the Serial Monitor, the
	// Serial.available() function will return that number (1 or greater).
	if (Serial.available())	// If data has been sent to the serial monitor
	{
		// Create a varaible, speed, and read the data from the serial monitor
		// into it. parseInt() reads in a number of characters and turns them
		// into a single integer value.
		int speed = Serial.parseInt();
		
		// Since we're using speed with analogWrite, we need to constrain its 
		// value between 0 and 255. The constrain function will do that for us!
		speed = constrain(speed, 0, 255);	// Constrain speed between 0 and 255
		
		// Print a message, tell us what we just told the Serial Monitor:
		Serial.print("Setting speed to: ");
		Serial.println(speed);
		
		// We can set the speed of the motor with the analogWrite function. It's
		// just like dimming an LED, but this time we're dimming the speed
		// of a motor.
		analogWrite(motorPin, speed);
	}
	
	// If the button is pressed, we'll halt the motor
	if (digitalRead(buttonPin))
	{
		// Set the motor output to LOW (off):
		digitalWrite(motorPin, LOW);
		
		Serial.println("Stopping!");	// Let us know through the serial monitor
		
		delay(250);	// "Debounce" the switch, by delaying for a short moment
	}
}
