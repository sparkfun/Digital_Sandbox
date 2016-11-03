// Sandbox 12: Thermal Alert!

/* “Is it hot in here, or is it just me?” Using a temperature sensor, which is
 able to precisely measure the room temperature, we can answer that question 
 once and for all!
 
 This experiment explores the analog input even further. This time we're 
 reading the input of an analog temperature sensor. Using some math we can
 convert that value to a voltage, and then to celsius and fahrenheit 
 temperatures.
 
 To do math with decimals, we need to introduce a new variable type: float.
 float variables allow us to escape the realm of the integer to calculate
 divisions to a very precise level.
 
 Also notice that we've defined some constant int variables for our LED
 and sensor pins. This is good practice -- it makes your code more readable
 and it allows you to quickly change the pin throughout your code if need be.
 */

// New variable type: float! float varaibles allow you to use decimal values.
// Other variables we've used -- int and long -- are integers. No decimal points
// allowed. floats are great, but only use them when you really need to. They
// require a lot more storage space and processor power.
// The thermalAlert variable is a constant. If the temperature reading is above
// this point, we'll turn the red LED on.
const float thermalAlert = 80.0;

// Lets also decloare some global variables for our LED and sensor pins. This
// makes swapping those pins much easier. And our code below will become much
// more readable.
const int temperaturePin = A0;	// Temperature sensor is connected to A0
const int redLEDPin = 9;		// Red LED is connected to pin 9
const int greenLEDPin = 11;		// Green LED is connected to pin 11

void setup()
{
  // Set the temperature sensor pin as an INPUT:
  pinMode(temperaturePin, INPUT);

  // Set the LED pins as OUTPUTs:
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  // Initialize Serial, set the baud rate to 9600.
  Serial.begin(9600);
}

void loop()
{
  // Read the raw 0-1023 value of temperature into a variable.
  long rawTemp = analogRead(temperaturePin);

  // Calculate the voltage, based on that value. To calculate voltage, we
  // multiply by the maximum voltage (5V), and divide by the maximum ADC
  // value (1023).
  float voltage = rawTemp * (5 / 1023.0);
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Calculate the celsius temperature, based on that voltage. The celsius
  // temperature is calculated by subtracting 0.5V from the reading, then
  // multiplying that small value by 100.
  float celsius = (voltage - 0.5) * 100;
  Serial.print("Celsius: ");	// Print "Celsius: "
  Serial.print(celsius);		// Print the celsius temp
  Serial.println(" °C");		// Print " °C" and a new line

  // Use a common equation to convert celsius to fahrenheit. F = C*9/5 + 32.
  float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.print("Fahrenheit: ");	// Print "Fahrenheit: "
  Serial.print(fahrenheit);		// print the fahrenheit temp
  Serial.println(" °F");			// Print " °F" and a new line
  Serial.println();				// Print a blank line

  // Now check the temperature, and turn on either the red or green LED 
  // depending on that value.
  if (fahrenheit >= thermalAlert)
  {
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
  }
  else
  {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
  }

  delay(1000);	// Wait a second between readings
}


