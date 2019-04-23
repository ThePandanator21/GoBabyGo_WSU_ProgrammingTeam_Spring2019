#include "Arduino.h"
#include "JoystickLib.h"

// Create joystick instance attached to pins A0 (X-axis) and A1
// Y-axis. This will also set the default threshold values.
Joystick stick(A0, A1);

void setup() {
  Serial.begin(9600);
  stick.calibrate();
}

void loop() {
  stick.loop();

  Serial.print("X = ");
  Serial.println(stick.getX());

  Serial.print("Y = ");
  Serial.println(stick.getY());

  delay(300);
}
