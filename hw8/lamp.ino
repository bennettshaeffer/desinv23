/*
 * Cade, Cahalan, Ethan Frazin, Bennett Shaeffer
 * A lamp with 6 independently moving triangles, forming a hexagon
 * Sides of the hexagon are chosen at random, as well as their timing, to give it a little more of an organic feel
 */

#include <Servo.h>
Servo servo;

int myservo[] = {
  5, 6, 9, 10, 11, 12  
};             // an array of pin numbers to which LEDs are attached
int pinCount = 6; // six servos
int pos = 0;    // variable to store the servo position
int currentPin;
int timer = 100;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(myservo[thisPin], OUTPUT);    //initializes all the pins
    
}
}
void loop() {
  currentPin = random(0, 5);    //choses a random pin out of the array
  timer = random(15, 40);       //choses a random time delay
  servo.attach(myservo[currentPin]);
  for (pos = 45; pos <= 135; pos += 1) { // goes from 45 degrees to 135 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(timer);                  // waits a random amount for the servo to reach the position
  }
  for (pos = 135; pos >= 45; pos -= 1) { // goes from 135 degrees to 45 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(timer);                  // waits the same random time for the servo to reach the position
  }
  delay(1500);      //waits some time between movements

  
}
