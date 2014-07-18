/* 
  Arduino program to control high speed camera, LED light, operate camera program, and trigger stimulus. 
  
  First turn on camera. Then send out 30 pulses, on each pulse simulatenously turn on LED light, trigger 
  stimulus, and press button of computer program to record cine. 
  
  Created 13 July 2014 by Victoria Norton
*/

#define WINDOWS 1

int platform = WINDOWS;                //set up OS platform for the keyboard control of the camera program
 
const int pinCam = 3;                  //pin the camera is connected to
const int pinStim = 4;                 //pin the stimulus is connected to
const int pinLED = 5;                  //pin the LED light is connected to

const int xAxis = A1;                  //analog sensor for X axis  
const int yAxis = A2;                  //analog sensor for Y axis

void setup()
{
  pinMode(2, INPUT_PULLUP);             //sets pin 2 as input and turns on pullup resistor, for keyboard
  pinMode(pinCam, OUTPUT);              //sets the 'pinCam' as output pin
  pinMode(pinStim, OUTPUT);             //sets the 'pinStim' as output pin
  pinMode(pinLED, OUTPUT);              //sets the 'pinLED' as output pin
  
  Mouse.begin();                        //starts mouse, so can use the phantom vision program
}

void loop()
{
  int totalPulses = 30;                 //total number of pulses 
  int firstPulses = 15;                 //number of pulses for camera to record 
  
  int xRead = readAxis(0);              //read and scale the x axes
  int yRead = readAxis(1);              //read and scale the y axes
  
  digitalWrite(pinCam, HIGH);           //turns 'pinCam' on                                      --turns camera on                          
  
  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < 15; j++)
    {
        digitalWrite(pinLED, HIGH);    //writes led (can be analog instead of digital)      -- turns LED on
        digitalWrite(pinStim, HIGH);   //writes stimulus                                    -- turns stimulus off
        Mouse.click(button);           //record camera
        delay(500);                    //pauses for a moment to let pinLED and pinStim activate
        
        digitalWrite(pinLED, LOW);     //writes led (can be analog instead of digital)       -- turns LED off      
        digitalWrite(pinStim, LOW);    //writes stimulus                                     -- turns stimulus off
        delay(1000);                 
    }
  
    Mouse.move(xRead, yRead, 0);       //move the mouse
  }
  
  digitalWrite(pinCam, LOW);         //turns 'pinCam' off                                   -- turns camera off
  Mouse.end();                       //stops emulating the mouse connected to the computer
}
