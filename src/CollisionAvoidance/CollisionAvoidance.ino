#include <Car.h>
#include <WallSensor.h>
#include <Buzzer.h>

Car car(75);
WallSensor sensor(7, 8);
Buzzer buzzer(6);

const int leftLED = 4;
const int rightLED = 5;

const int threshold = 30;

void setup() {
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
  
  buzzer.countdown();
}

void loop() {
  execute();
}

// Avoidance algorithm.
// Check front, then left, then right, then out.
void execute() {
  // Signal left and turn if there is a wall.
  if (sensor.getDistance() < threshold) {
    buzzer.scream();
    car.stopMoving();
    delay(1000);
    digitalWrite(leftLED, HIGH);
    car.turnLeft();
    car.stopMoving();
    delay(1000);
    // Spin around if there is still a wall.
    if (sensor.getDistance() < threshold) {
      buzzer.scream();
      car.stopMoving();
      delay(1000);
      digitalWrite(leftLED, LOW);
      car.turnAround();
      car.stopMoving();
      delay(1000);
      // Signal right and turn if there is still a wall.
      if (sensor.getDistance() < threshold) {
        buzzer.scream();
        car.stopMoving();
        delay(1000);
        digitalWrite(rightLED, HIGH);
        car.turnRight();
        car.stopMoving();
        delay(1000);
        digitalWrite(rightLED, LOW);
      }
    }
    digitalWrite(leftLED, LOW);
    digitalWrite(rightLED, LOW);
  // Go forwards until a wall arrives.
  } else {
    car.goForwards();
  }
}
