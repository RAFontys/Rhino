#include <Arduino.h>
#include <Servo.h>
Servo motorLinks; 
Servo motorRechts;

//naam geving aan alle pins
const int LEDgeel = 4;
const int LEDblauw = 12;
const int lichtSensorEen = A0;
const int lichtSensorVijf = A1;
/*
const int RGBgroen = 13;
const int RGBrood = 7;
const int RGBblauw = 2;
*/

void setup() {
  Serial.begin(9600);
  motorLinks.attach(2); 
  motorRechts.attach(13);
  // geeft aan of de pins in- of output moeten zijn
  pinMode(LEDgeel, OUTPUT);
  pinMode(LEDblauw, OUTPUT);
  pinMode(lichtSensorEen, INPUT);
  pinMode(lichtSensorVijf, INPUT);
/*
  pinMode(RGBgroen, OUTPUT);
  pinMode(RGBrood, OUTPUT);
  pinMode(RGBblauw, OUTPUT);
  */
}
// functies voor sturen
void Right(){
  motorRechts.write(180);
  motorLinks.write(180);
  return;
}
void Left(){
  motorRechts.write(0);
  motorLinks.write(0);
  return;
}
void Straight(){
  motorRechts.write(180);
  motorLinks.write(0);
  return;
}
void Backwards(){
  motorRechts.write(0);
  motorLinks.write(180);
  return;
}

void loop() {
  // boolean voor te op te slaan of de lichtsensoren als laatst wit of zwart zagen.  
  int waardeEen = analogRead(lichtSensorEen);
  int waardeVijf = analogRead(lichtSensorVijf);
  Serial.print(waardeEen);
  Serial.print("    ");
  Serial.println(waardeVijf);

  //als bijde sensoren zwart zien gaat i vooruit
  /*
  if(waardeEen == LOW && waardeVijf == LOW)
  {
    Straight();
  }
  // gaat naar links  als sensor een wit detecteert
  if(waardeEen == HIGH)
  { 
    Left();
    digitalWrite(LEDblauw, HIGH);
  }
  // gaat naar rechts  als sensor twee wit detecteert
  if(waardeVijf == HIGH)
  {
    Right();
    digitalWrite(LEDgeel, HIGH);
  }
  digitalWrite(LEDgeel, LOW);
  digitalWrite(LEDblauw, LOW);
  */
/*
  digitalWrite(RGBgroen, HIGH);
  digitalWrite(RGBrood, HIGH);
  digitalWrite(RGBblauw, HIGH);
  */
}