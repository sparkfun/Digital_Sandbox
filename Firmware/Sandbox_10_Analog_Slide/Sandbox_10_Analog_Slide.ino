// Sandbox 10: Do the Analog Slide

/* Digital inputs, like the button, only allow for two input values: HIGH or 
   LOW. But what about the in-betweens? When you turn the volume up on your 
   stereo, you’re not forced to pick between mute and “OMG MY EARS.” For volume 
   control and other “finely-tuned” settings, we need analog inputs.
   
   This experiment introduces analog inputs using the analogRead([analog pin]) 
   function. You can perform an analogRead on any pin that has an 'A' in front
   of it.
   
   analogRead() returns a value between 0 and 1023. 0 is equivalent to 0V, 1023
   is 5V, 512 is 2.5V, and so on.
   
   After uploading this sketch, open the serial monitor and check the output
   of the slider potentiometer.
*/

// 
void setup()
{
	// Set up the slide potentiometer as an INPUT:
	pinMode(A3, INPUT);
	
	// Set up serial, set the baud rate to 9600:
	Serial.begin(9600);
}

void loop()
{
	// Print the value of analog pin 3:
	Serial.println(analogRead(analogRead(A3)));
	
	delay(100);	// Delay for visibility.
}
