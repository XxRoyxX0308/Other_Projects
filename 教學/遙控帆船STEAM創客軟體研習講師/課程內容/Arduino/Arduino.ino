#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(13);
  servo1.write(180);
}

void loop() {
  servo1.write(180);
  delay(500);
  servo1.write(90);
  delay(500);
  servo1.write(0);
  delay(500);
}