#include <Driver.h>
#include <SonarSensor.h>
#include <FlexSensor.h>
#include <Buzzer.h>
#include <Signals.h>

Driver      driver(100);
SonarSensor sonar(7, 8, 20);
FlexSensor  flex(5, 715);
Buzzer      buzzer(6);
Signals     signals(4, 5);

const int seedPin = 0;
const int stall = 750;

int turn;

void setup() {
  randomSeed(analogRead(seedPin));
  buzzer.countdown();
}

void loop() {
  exec();
}

// Avoidance algorithm. Turns are pseudorandom to avoid walls.
void exec() {
  // If a physical collision is detected, backup and turn.
  if (flex.isFlexed()) {
    driver.stopMoving();
    buzzer.scream();
    signals.blinkBoth();
    driver.goBackwards();
    delay(stall);
    driver.stopMoving();
    delay(stall);
    turn = 1 + (random(10000) % 3);
    fixPos(turn);
    driver.stopMoving();
    delay(stall);
    driver.stopMoving();
  // If a wall is close, turn.
  } else if (sonar.isWall()) {
    driver.stopMoving();
    buzzer.scream();
    turn = 1 + (random(10000) % 3);
    fixPos(turn);
    driver.stopMoving();
    delay(stall);
  // Keep going forwards if no danger is detected.
  } else {
    driver.goForwards();
  }
}

// Maps the random turn to the actual functions.
void fixPos (int turn) {
  switch (turn) {
      case 1:
      goLeft();
      break;
      case 2:
      goRight();
      break;
      default:
      goAround();
      break;
    }
}

// Signal left and turn left.
void goLeft() {
  signals.blinkLeft();
  driver.turnLeft();
}

// Signal right and turn right.
void goRight() {
  signals.blinkRight();
  driver.turnRight();
}

// Signal right and turn around (using a 180 degree right turn).
void goAround() {
  signals.blinkRight();
  driver.turnAround();
}
