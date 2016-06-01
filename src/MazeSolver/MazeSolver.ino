#include <Car.h>
#include <Buzzer.h>

Car car(75);
Buzzer buzzer(6);

const int leftLED = 4;
const int rightLED = 5;

void setup() {
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
  
  buzzer.countdown();
}

void loop() {
  execute(); 
}

// Written out maze instructions. Turn signals are used.
void execute() {
  car.goForwards();
  delay(2000);
  car.stopMoving();
  delay(500);
  
  digitalWrite(leftLED, HIGH);
  car.turnLeft();
  digitalWrite(leftLED, LOW);
  car.stopMoving();
  delay(500);
  
  car.goForwards();
  delay(4000);
  car.stopMoving();
  delay(500);
  
  digitalWrite(rightLED, HIGH);
  car.turnRight();
  digitalWrite(rightLED, LOW);
  car.stopMoving();
  delay(500);
  
  car.goForwards();
  delay(7000);
  car.stopMoving();
  delay(500);
  
  digitalWrite(rightLED, HIGH);
  car.turnRight();
  digitalWrite(rightLED, LOW);
  car.stopMoving();
  delay(500);
  
  car.goForwards();
  delay(5000);
  car.stopMoving();
  delay(500);
  
  digitalWrite(leftLED, HIGH);
  car.turnLeft();
  digitalWrite(leftLED, LOW);
  car.stopMoving();
  delay(500);
  
  car.goForwards();
  delay(6000);
  car.stopMoving();
  delay(500);
  
  digitalWrite(leftLED, HIGH);
  car.turnLeft();
  digitalWrite(leftLED, LOW);
  car.stopMoving();
  delay(500);
  
  car.goForwards();
  delay(4000);
  car.stopMoving();
  delay(500);

  // Robot will keep celebrating until turned off.
  while (true) {
    buzzer.celebrate();
  }
}
