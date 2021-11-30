#include <Arduino.h>
#include <Servo.h>
Servo motorLinks;  // create servo object to control a servo
Servo motorRechts;
int posR = 0;    // variable to store the servo position
int posL = 0;
//int revertimer = delay(2000);

const int echo = 3;
const int trig = 5;
const int LED = 2;
const int lichtSensorEen = 8; //the tracking module attach to pin 8
long duration;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  motorLinks.attach(10);  // attaches the servo on pin 9 to the servo object
  motorRechts.attach(11);
  pinMode(LED, OUTPUT);
  pinMode(lichtSensorEen, INPUT); // set trackingPin as INPUT
}
void Right(){
  motorRechts.write(45);
  motorLinks.write(0);
  return;
}
void Left(){
  motorRechts.write(0);
  motorLinks.write(90);
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
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
/*
  if(distance <= 10)
  {
    Backwards();
    delay(1000);
    Right();
    delay(600);
  }

  if(distance >= 10)
  {
    Straight();
  }
*/

  boolean waarde = digitalRead(lichtSensorEen); // read the value of tcrt5000
  if(waarde == HIGH) //if it is HiGH
  { 
    
    Serial.println("hoog");
    digitalWrite(LED, LOW);
  }
  if(waarde == LOW)
  {
    Serial.println("laag");
    digitalWrite(LED, HIGH);
  }
 
}