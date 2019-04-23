#include <DualVNH5019MotorShield.h>
#include "Arduino.h"
#include "JoystickLib.h"

// Create joystick instance attached to pins A0 (X-axis) and A1
// Y-axis. This will also set the default threshold values.
Joystick stick(A0, A1);
// This stick library only updates on change in analog stick value?

DualVNH5019MotorShield motorShield;

int maxSpeed = 400;
int curSpeed = 0;

void setup() {
  Serial.begin(9600);
  motorShield.init(); //Method of motor library to set up it's pins
  stick.calibrate();
}

void loop() {
  stick.loop(); //This functionneeds to be called to enable readings from this library.

//  Serial.print("X = ");
//  Serial.println(stick.getX());
//
//  Serial.print("Y = ");
//  Serial.println(stick.getY());

  int stickX = stick.getX();





    if (75 < stickX <= 100)
  {
    curSpeed = 400;
  }
     else if (50 < stickX <= 75)
  {
    curSpeed = 300;
  }
    else if (25 < stickX <= 50)
  {
    curSpeed = 200;
  }
    else if (10 < stickX <= 25)
  {
    curSpeed = 100;
  }
   else if (0 <= stickX <= 10)
  {
    curSpeed = 0;
  }
  
  Serial.println(curSpeed);

  motorShield.setM1Speed(curSpeed);
 
  //delay(300);
}
