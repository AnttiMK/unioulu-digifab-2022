#include <Servo.h>

const int coinButton = 4;
const int choice1 = 2;
const int choice2 = 3;
const int servo1_pin = 8;
const int servo2_pin = 9;
Servo servo1;
Servo servo2;

int itemChoice;

void setup() {
  pinMode(coinButton, INPUT_PULLUP);
  pinMode(choice1, INPUT_PULLUP);
  pinMode(choice2, INPUT_PULLUP);

  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  // Wait until coin is dropped
  while (true) {
    if (digitalRead(coinButton) == LOW) break;
  }
  
  // Wait until choice is made
  while (true) {
    if (digitalRead(choice1) == LOW) {
      itemChoice = 1;
      break;
    } 
    if (digitalRead(choice2) == LOW) {
      itemChoice = 2;
      break;
    }
  }
  
  // Delays are cool
  delay(250);
  
  // Drop item according to the user's choice, 
  // and return to initial state
  switch(itemChoice) {
    case 1:
      servo1.write(90);
      delay(1500);
      servo1.write(0);
      break;
    case 2:
      servo2.write(90);
      delay(1500);
      servo2.write(0);
      break;
  }
}
