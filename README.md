# Casper

This is a maze solving and collision avoiding robot.
It is written in C++ and Arduino.

Please see the sketch and images for the setup. [Instructions are to be followed from here.](https://learn.sparkfun.com/tutorials/ardumoto-shield-kit-hookup-guide)

The recommended operating environment is on thin carpet and with a wheel speed of 75. For collision avoiding, a wall detection threshold of 30cm or more is ideal.

Please note that the maze solver uses feedforward control and requires pre-programmed instructions.

Tests:
[Enclosed testing with a threshold of 15cm and improperly calibrated turning angles.](https://www.youtube.com/watch?v=2yFTkYMe1jQ) Very poor at getting out of corners and hits many walls.
[Enclosed testing with a threshold of 30cm and proper turning angles.](https://www.youtube.com/watch?v=V22wO23BzBc) Much better at getting out of corners and hits much fewer walls.

Final Results:
[Maze solving in action is found here.](https://www.youtube.com/watch?v=xZCYPncAxf0) Floor markers are used as the expected path.
[Real world collision avoidance is found here.](https://www.youtube.com/watch?v=qjraKy9OzuM)

Final Note:
Try more sensors to avoid blind spots!
