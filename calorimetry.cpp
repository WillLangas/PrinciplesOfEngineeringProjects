/* Calorimetry Project
 * March 2nd, 2017
 * William Chin, Jack Kelly, Will Langas
 * Transistor base pin in series with 10k resistor 
 * Transistor collector pin to 12V mechanical Relay
 * 12V Power source, DC motor to pin 3~
 * Immersion Heater to Relay output
 */
 
int tempi = analogRead(A1)*0.247-70.19; //Calculates temp from the normal 0-1023 analog output, sets as the variable: tempi
int waterMass = 386; //Sets the water mass in grams

void setup()
{
  pinMode(A1, INPUT); //Sets an analog input pin for the thermistor 
  pinMode(3, OUTPUT); //Sets an output to a PWM pin for the motor that stirs the water
  pinMode(4, OUTPUT); //Sets the output for the LED/Lightbulb/Immersion Heater

  Serial.begin(9600); //Starts the Serial Monitor at Port 9600

  Serial.print("initial temp is "); //Sets a format for printing the temperature to the serial monitor
  Serial.println(tempi);  //Print the temperature in the Serial Monitor 
}

void loop()
{
    digitalWrite(4, HIGH);  //Turns the Heater/LED on through the transistor and relay
    delay(10000);           //Waits 10 seconds
    digitalWrite(4, LOW);   //Turns the Heater/LED off through the transistor and relay
    analogWrite(3,100);    //Turns the motor on
    delay(10000);          //Waits 10 seconds
    analogWrite(3,0);     //Turns the motor off
    
int tempf = analogRead(A1)*0.247-70.19;  //Calculates the new temperature from 0-1023 output, sets as the variable: tempf
    Serial.println (tempf); //Prints the value of the final temperature 
    Serial.println("The change in temperature is:");
int changeTemp = tempf-tempi; //Defines a variable for the difference in temperature   
    Serial.println(changeTemp); //Prints the change in temperature
  
int changeTempCelcius = (changeTemp - 32)/1.8; //Converts the change in temperature variable to celcius 
int QHeatJoules = 3000; //Sets the value of Q to 3000 (Power = energy/time)
int specificHeatCapacity = QHeatJoules/(changeTempCelcius*waterMass); //Does an equation that calculate the specific heat capacity 
   Serial.println("The specific heat capacity of water is "); 
   Serial.print(specificHeatCapacity); //Prints the specific heat capacity of the liquid to the serial monitor 
}
