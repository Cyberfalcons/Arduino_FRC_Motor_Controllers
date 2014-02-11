//Adapted from the sample code on the arduino website. http://arduino.cc/en/Tutorial/Knob


// The FRC motor controllers (Jaguar, Victor, Talon) use servo signals to control their outputs. 
// My experimentation seems to show that full backwards is "0" on the servo, full forwards is "180".
// With the following code, the arduino can send control signals to a Jaguar, Victor or Talon. Power 
// the arduino off the PD board (12 volts is fine). Wire the potentiometer so such that the "signal" 
// pin is wired to Analog 0.


#include <Servo.h> 
 
Servo myservo;  // create servo object. 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  
  dir=digitalRead(switchpin);          // read value from digital pin
  val = map(val, 0, 1023, 90, 179); 
//  if(dir==0){
//    val = map(val, 0, 1023, 80, 179);     // scale it to use it with the servo (value between 0 and 180) 
//  }else{
//    val = map(val, 0, 1023, 80, 0);
//  }
    
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
}
