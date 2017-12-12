/* Titration Automation Final Code
   Will Langas and Jake Whisler
   GBS STEM PoE
   5/25/2017
   Momentary Pushbutton to Digital Pin 3
   DC Motor through L293D IC Chip (12V)
   Vernier Ph sensor through analog pin 1
   7 and 4 inch pnuematic cylinders to pins 9 and 8 respectively through MOSFEDs (4 in spring loaded)
   Solenoid Valve Dropper to 7 through MOSFED
*/

/**********************/
/*INPUT VARIABLE BELOW*/
/**********************/

float baseToAdd = 33; //Enter the amount of base in mL to be added here

float delayTimer = baseToAdd / 0.005217 + 0.0244; //Calculates how long the dripper should be on, Uses experimental data

void setup() {
  Serial.begin(9600); //Starts the Serial Monitor at port 9600

  pinMode(9, OUTPUT); //Big Cylinder pin declaration, (Output)
  pinMode(8, OUTPUT); //Small Cylinder pin declaration (Output)
  pinMode(7, OUTPUT); //Dropper pin declaration (Output)
  pinMode(5, OUTPUT); //Motor pin declaration (Output)
  pinMode(3, INPUT); //Start Button pin declaration (Input)
  pinMode(A1, INPUT); //PH Sensor pin declaration (Analog Input)

  Serial.println("System Initiated"); //Start message to the serial monitor

  digitalWrite(8, LOW); //Small cylinder out of solution
  delay(7500);
  digitalWrite(9, HIGH); //Big cylinder to the start solution
  delay(7500);
  digitalWrite(8, HIGH); //Sensor into the start solution

}


void loop() {

  if (digitalRead(3) == 0) { //Starts the following code once the button is pressed
    Serial.println("Titration Beginning"); //Prints when the button is pressed

    digitalWrite(8, LOW); //Raise the small cylinder
    delay(7500);
    digitalWrite(9, LOW); //Bring the big cylinder to the titration position
    delay(7500);
    digitalWrite(8, HIGH); //Put the sensor and motor into the solution
    delay(7500);

    float initialPH = analogRead(A1) * -0.01868917 + 13.8122802; //Calculate the initial pH
    Serial.print("The initial pH is ");
    Serial.println(initialPH); //Print the intial pH to the serial monitor
    analogWrite(5, 100); //Start the motor stirring, medium-ish speed

    digitalWrite(7, HIGH);
    delay(delayTimer); //Turns on the dropper for a given amount of time
    digitalWrite(7, LOW);
    delay(1000);

    float finalPH = analogRead(A1) * -0.01868917 + 13.8122802; //Calculate the final pH
    Serial.print("The final pH is "); //Print the final pH to the serial monitor
    Serial.println(finalPH);
    analogWrite(5, 0); //Turns the motor off

    digitalWrite(8, LOW); //Raises sensor out of water
    delay(7500);
    digitalWrite(9, HIGH); //Turntable back to start solution
    delay(7500);
    digitalWrite(8, HIGH); //Sensor back into start solution
  }
}
