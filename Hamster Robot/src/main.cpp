#include <Arduino.h>
#include <Servo.h>
#include <UltrasoneDriver.h>
int posR = 0;    // variable to store the servo position
int posL = 0;
const int LEDgeel = 4;
const int LEDblauw = 12;
const int ButtonRood = 7;
const int Button = 8;
const int lichtSensorEen = A0;
const int lichtSensorVijf = A1;

String modes;

void volgLijn()
{
  int waardeEen = analogRead(lichtSensorEen);
  int waardeVijf = analogRead(lichtSensorVijf);
  Serial.print(waardeEen);
  Serial.print("    ");
  Serial.println(waardeVijf);

  //als bijde sensoren zwart zien gaat de hamster vooruit
  
  if(waardeEen < 900 && waardeVijf < 900)
  {
    Straight();
    digitalWrite(LEDgeel, LOW);
    digitalWrite(LEDblauw, LOW);
  }
  // gaat naar links  als sensor een wit detecteert
  if(waardeEen > 900)
  { 
    Left();
    digitalWrite(LEDblauw, HIGH);
  }
  // gaat naar rechts  als sensor twee wit detecteert
  if(waardeVijf > 900)
  {
    Right();
    digitalWrite(LEDgeel, HIGH);
  }
}

void afstandsensorMode()
{
  Distance();
  //haalt de afstand op
  if(newdistance > 16)
  {
    Straight();
    delay(50);
  }
  //als de afstand boven de 16 is zal de hamster gebruik maken van de vooruit methode 
  if(newdistance < 15)
  {
    Backwards();
    delay(50);    
    Serial.println("reversing");
  }   
  //als de afstand van de hamster tot aan een object kleiner is als 15 zal die de achteruit methode gebruiken
}

void loop() {
  afstandsensorMode();
  /*
  if(digitalRead(ButtonRood) == HIGH)
  {
    modes = "afstandsensor";
  	digitalWrite(LEDgeel, HIGH);
  }
  else if(digitalRead(Button) == HIGH)
  {
    modes = "lijn";
    digitalWrite(LEDblauw, HIGH);
  }
  else{
    digitalWrite(LEDgeel, LOW);
    digitalWrite(LEDblauw, LOW);
  }

  if(modes == "afstandsensor")
  {
    afstandsensorMode();
  }
  else if(modes == "lijn")
  {
    volgLijn();
  }
  */
}