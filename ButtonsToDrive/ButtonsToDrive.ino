//Libraries Used
#include <DualVNH5019MotorShield.h> //All the libraries made by the manufacturer of our motor shield

//Motor Shield Declration
DualVNH5019MotorShield motorShield;

//Forward Button Declrations
const int fwdBtnPin = 3; //Forward Button Pin Definition
int fwdBtnState; //Button state logic variable

//Time Variables for Motor Speed
unsigned long oldTime;
unsigned long curTime;

//Motor Speed Logic variables

//DO NOT CHANGE THESE UNLESS YOU KNOW WHAT YOU ARE DOING
int initialSpeed = 100;
int m1Speed = 100;
//DO NOT CHANGE THE ABOVE

//Change these to affact how fast the car will be allowed to go/Acccel.
int maxSpeed = 400; //The upper limit you want the car to be able to go, is measured in millivolts
int spdIncInterval = 500; //Speed Increase Interval - decreasing this will make more steps occur per unit time (In milliseconds)
int spdMod = 10; //Speed increase modifier, increasing this will increase the amount of speed gained every step

void setup() {
  // put your setup code here, to run once:
  pinMode(fwdBtnPin, INPUT); //Declares button pin as an input
  
  motorShield.init(); //Method of motor library to set up it's pins

  oldTime = millis(); // Time logic, dont touch;

  Serial.begin(9600); //Serial output init, dont touch
}

void loop() {
  // put your main code here, to run repeatedly:
  fwdBtnState = digitalRead(fwdBtnPin); //Constatnly update button state

  if ( fwdBtnState == HIGH ) // if button is pressed
  {
    motorShield.setM1Speed(m1Speed); //set motor speed

    curTime = millis(); //get current time
    
    if ((curTime - oldTime) >= spdIncInterval) //If enough time has passed, speed up (If our current time minus our older time is equal to or greater than our interval)
    {
      if (m1Speed < maxSpeed) //Are we less than our max speed?
      {
        m1Speed += spdMod; //add our speed modifier to our total current speed
      }
      else
      {
        m1Speed = maxSpeed; // if we are at our max speed, just keep it there.
      }
      oldTime = curTime; // Set the oldTime to the current time to maintain consistent interval
    }
    
  }
  else //if we arent pressing the forward button
  {
    motorShield.setM1Speed(0); //stop the motor
    m1Speed = initialSpeed; // reset our current speed to our initial speed. This keeps the car from going max speed when we press the fwd button again
  }

  //Serial Logging Code
  Serial.println("M1 Speed = ");
  Serial.println(m1Speed);
}//Created in Spring 2019 for WSU GoBabyGo Programming Team

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
