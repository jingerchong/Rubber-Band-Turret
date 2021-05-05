
#include <Servo.h> 

int servo1Pin = 3; 
int servo2Pin = 4;
int servo3Pin = 5;
int switchPin = 2;
int potentiometer1AnalogPin = 0;
int potentiometer2AnalogPin = 2;
int state = 0;
int counter = 0;
int servoCurrent = 20;
int potentiometer1Reading;
int potentiometer2Reading;

Servo Servo1; 
Servo Servo2;
Servo Servo3;
void setup() { 
   Servo1.attach(servo1Pin); 
   Servo2.attach(servo2Pin);
   Servo3.attach(servo3Pin);
   pinMode(switchPin, INPUT);
   digitalWrite(switchPin, HIGH);
}

void loop(){ 
   potentiometer1Reading = analogRead(potentiometer1AnalogPin);
   potentiometer2Reading = analogRead(potentiometer2AnalogPin);
   state = digitalRead(switchPin);
   if (counter < 2) {
    if (state == LOW) {
    Servo3.write(servoCurrent+70);
    delay(500);
    servoCurrent = servoCurrent + 50;
    Servo3.write(servoCurrent);
    counter = counter + 1;
   } else {
    Servo3.write(servoCurrent);
   }} else{
    servoCurrent = 20;
    counter = 0;
   }
   Servo1.write(90-(512-potentiometer1Reading)/50);
   Servo2.write(90-(512-potentiometer2Reading)/30);
   delay(300);
}
