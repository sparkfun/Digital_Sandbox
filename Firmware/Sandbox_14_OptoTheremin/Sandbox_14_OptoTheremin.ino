// Sandbox 14: Opto-Theremin (Add-on)

/* In this experiment we’ll attach a speaker to the Sandbox, and turn it into a 
   musical instrument! By using the light sensor to control our speaker’s pitch, 
   we can create a light-controlled theremin - a non-contact, electronic musical 
   instrument.

   By precisely modulating a pin, the Digital Sandbox can create electronic 
   waves which, when routed through a loudspeaker, can produce a musical tone. 
   We can program the Sandbox to control two characteristics of musical tone: 
   pitch and duration.
   
   This experiment introduces the tone() function, which can be used to play a
   specific tone out of a speaker attached to a pin.
   
   You'll also quickly discover the noTone() function, which you'll want to call
   before your ears start bleeding.
*/


// Let's create global variables to reference the pins of our in's and out's:
const int speakerPin = 3;	// The speaker is connected to 3
const int switchPin = 2;	// switch is connected to pin 2
const int sliderPin = A3;	// slider pot is connected to A3
const int lightPin = A1;	// light sensor is connected to A1
const int redPin = 9;		// Red LED is connected to pin 9
const int bluePin = 10;		// Blue LED is connected to pin 10
const int greenPin = 11;	// Green LED is connected to pin 11

void setup()
{
	// Set up our sensors (switch, slider, light) as INPUTs:
	pinMode(lightPin, INPUT);
	pinMode(switchPin, INPUT);
	pinMode(sliderPin, INPUT);
	
	// Set up our speaker and LEDs as OUTPUTs:
	pinMode(speakerPin, OUTPUT);
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}

void loop()
{
	if (digitalRead(switchPin)) // If the switch is in the "1" position:
	{
		digitalWrite(redPin, HIGH);		// Turn on the red LED
		digitalWrite(bluePin, HIGH);	// Turn on the blue LED
		digitalWrite(greenPin, HIGH);	// Turn on the green LED
		
		int light = analogRead(lightPin);	// Read in the light sensor
		// Convert the light sensor reading to a pitch frequency we can hear.
		// We can use the map function to convert a value from one range of
		// values to another, proportionally. This example maps light from
		// 0-60 to a proportional value between 440 and 880:
		int pitch = map(light, 0, 60, 440, 880);	
		
		// The tone function plays a pitch on a pin connected to a speaker.
		// In this case, we play the pitch we just calculated on the speakerPin
		// -defined pin.
		tone(speakerPin, pitch);
		// Once we call tone, that pitch will play until commanded to stop, or
		// a new pitch is defined. Let's delay for a short time, then run back
		// through and play another pitch.
		delay(5 + analogRead(sliderPin));
	}
	else	// Otherwise the switch is in the "0" poisition.
	{
		// noTone stops all sound coming out of the defined pin.
		noTone(speakerPin);			// Silence!
		digitalWrite(redPin, LOW);	// Turn red LED off
		digitalWrite(bluePin, LOW);	// Turn blue LED off
		digitalWrite(greenPin, LOW);// Turn green LED off
	}
}
