/* Will Langas
 * Calibrating Thermistor
 * Connect a thermistor with a resistor to an analog pin
 * Voltage Divider Circuit
 * 6/2/2017
 */

int thermistor = A1; //Input the analog pin being used here

void setup() {
 pinMode(thermistor, INPUT); //Declares the pin as an input
 
 Serial.begin(9600);
 Serial.println("System Initiated"); //Startup message
}

void loop() {
  int tempRead = (analogRead(thermistor)); 
  
  Serial.println(tempRead); //Prints the analog read value 
  delay(5000); 
}

//To use the program, have a thermometer constantly monitoring the real temperature
//Plot the real temperature on the y axis and the serial value on the x
//Find a liner regression equation. This can then be utilized in calorimtery, heat transfer, etc. 
