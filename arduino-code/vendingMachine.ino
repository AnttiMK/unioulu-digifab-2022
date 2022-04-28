#include <Servo.h>

const int coinButton = 3;
const int choice1 = 2;
//const int choice2 = 3;
const int servo1_pin = 8;
const int redLed = 5;
const int greenLed = 6;

Servo servo1;
int itemChoice;

void setup() {
  pinMode(coinButton, INPUT_PULLUP);
  pinMode(choice1, INPUT_PULLUP);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  //pinMode(choice2, INPUT_PULLUP);

  servo1.attach(servo1_pin);
  //servo2.attach(servo2_pin);

  servo1.write(180);
  //servo2.write(0);
  digitalWrite(redLed, HIGH);
}

void loop() {
  // Wait until coin is dropped
  while (true) {
    if (digitalRead(coinButton) == LOW) break;
  }

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);

  // Wait until choice is made
  while (true) {
    if (digitalRead(choice1) == LOW) {
      itemChoice = 1;
      break;
    } 
    //if (digitalRead(choice2) == LOW) {
    //  itemChoice = 2;
    //  break;
    //}
  }

  // Delays are cool
  delay(250);

  // Drop item according to the user's choice, 
  // and return to initial state
  switch(itemChoice) {
    case 1:
      servo1.write(60);
      delay(500);
      servo1.write(180);
      break;
    //case 2:
      //servo2.write(60);
      //delay(1500);
      //servo2.write(180);
      //break;
  }
  
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
}
