#include <Arduino.h>
#include <Servo.h>
Servo motorLinks; 
Servo motorRechts;
int posR = 0;    // variable to store the servo position
int posL = 0;
const int echo = 3;
const int trig = 5;
long duration;
int newdistance;
int arraydistance;
int rotate_array[359];
int max_value = 0;
int caldir = 0;
boolean calibrating = false;
const int LEDgeel = 4;
const int LEDblauw = 12;
const int lichtSensorEen = A0;
const int lichtSensorVijf = A1;

void setup() {
  Serial.begin(9600);
  motorLinks.attach(2); 
  motorRechts.attach(13);
  pinMode(LEDgeel, OUTPUT);
  pinMode(LEDblauw, OUTPUT);
  pinMode(lichtSensorEen, INPUT);
  pinMode(lichtSensorVijf, INPUT);
}
  void Right(){
    motorRechts.write(90);
    motorLinks.write(0);
    return;
  }
  //laat de hamster naar rechts bewegen
  void Left(){
    motorRechts.write(0);
    motorLinks.write(90);
    return;
  }
  //laat de hamster naar links bewegen
  void Straight(){
    motorRechts.write(180);
    motorLinks.write(0);
    return;
  }
  // laat de hamster naar voren bewegen
  void Distance(){
    digitalWrite(trig,LOW);
    delayMicroseconds(2);

    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    duration = pulseIn(echo,HIGH);
    newdistance = duration*0.034/2;
    return;
    delay(50);
  }
  // neem de afstand waar door middel van een input en output sensor de sensoren werken door een soort echo locatie door middel van de newdistande formule wordt de afstand berekent
   void Calibrate(){
    int calcount = 0;

    while(calcount < 359)
    {
        motorLinks.write(360);
        motorRechts.write(360);
        Distance();
        arraydistance = newdistance;
        rotate_array[calcount] = arraydistance;
        calcount++;

        if(max_value < arraydistance)
        {
          max_value = arraydistance;
          caldir = calcount;
        }
    }
    if(calcount == 359)
    {
      motorRechts.write(caldir);
      motorLinks.write(caldir);
    }
    // de calibreer methode maakt een array van 360 waarde's aan elke waarde wordt gevuld met een afstand als alle waarde zijn gevuld zal de hamster naar de verste waarde toe bewegen
  }

  void Backwards(){
    Distance();
    Serial.println(newdistance);    
    motorRechts.write(0);
    motorLinks.write(180);

    while(newdistance < 20)
    {
      Distance();
      motorRechts.write(0);
      motorLinks.write(180);
      Serial.println("waiting");
      Serial.println(newdistance);
      delay(100);
    }

    if(newdistance > 20)
    {
      Calibrate();
    }   
    //de achteruit methode haal altijd de nieuwe waarde va de afstand op als deze nog niet over de 20 is zal die achteruit blijven rijden als zit de afstand waarde hierboven wordt er gebruik gemaakt van de calibreer functie
  }

void loop() {
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
  digitalWrite(LEDgeel, LOW);
  digitalWrite(LEDblauw, LOW);
  */
/*
  digitalWrite(RGBgroen, HIGH);
  digitalWrite(RGBrood, HIGH);
  digitalWrite(RGBblauw, HIGH);
  */
}