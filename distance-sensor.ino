// Room temperature sensor, with integra

//include LCD library
#include <LiquidCrystal.h>

//set up pin connections
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const int trigPin = 5;
const int echoPin = 6;

//initialise variables
float voltage = 0;
float degreesC = 0;
float distance = 0;

void setup() {
  //set up LCD
  lcd.begin(16, 2);
  lcd.clear();
  
  //set up sensor
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  distance = getDistance();
  Serial.print(distance);
  Serial.println(" in");

  voltage = analogRead(A0) * 0.004882813;   //convert analog reading to a voltage value
  degreesC = round((voltage - 0.5) * 100.0); //convert voltage value to a temperature in degrees Celsius and round to the nearest degree

  lcd.clear();                              //clear the LCD

  if (distance <= 10) {
    lcd.setCursor(0, 0);                      //set the cursor to the lower left position
    lcd.print("Welcome Home Tim");

    lcd.setCursor(0, 1);                      //set the cursor to the top left position
    lcd.print("Room Temp: ");
    lcd.print(degreesC, 0);
    lcd.print((char)223);
    lcd.print("C");
    
    delay(5000);                              //show message for 5 seconds

  } else {
    lcd.setCursor(0,0);
    lcd.print("Standing by");
  }

  delay(100);                              //delay for 1 second between each reading
}

//------------------FUNCTIONS-------------------------------

//
//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR [1]
float getDistance()
{
  float echoTime;                   //time it takes for a ping to bounce off an object
  float calculatedDistance;

  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  echoTime = pulseIn(echoPin, HIGH);

  calculatedDistance = echoTime / 148.0;  //half the bounce time multiplied by the speed of sound

  return calculatedDistance;
}