#include <Arduino.h>
#include <Servo.h>
Servo motorLinks;  // create servo object to control a servo
Servo motorRechts;
int posR = 0;    // variable to store the servo position
int posL = 0;
int revertimer = delay(2000);

const int echo = 3;
const int trig = 5;
long duration;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  motorLinks.attach(10);  // attaches the servo on pin 9 to the servo object
  motorRechts.attach(11);
}
void Right(){
    motorRechts.write(90);
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

  if(distance <= 5)
  {
    Backwards();
    Right();
  }

  if(distance >= 5)
  {
    Straight();
  }


  Serial.println("hallo");
}