/* 
  Arduino program to control high speed camera, LED light, and solenoid (trigger stimulus) during habituation
  experiment. 
  
  Send out 30 total pulses. 
  First 15 pulses will simulatenously turn on camera, LED light, and solenoid (trigger stimulus) - for one second.
  Next 15 pulses (16-30) will simulatenously turn on LED light and solenoid - for one second. 
  
  Created 13 July 2014 by Victoria Norton
*/
 
const int pinCam = 53;                   //pin the camera is connected to
const int pinSolen = A0;                 //pin the solenoid which is connected to the stimulus
const int pinLED = 9;                  //pin the LED light is connected to

void setup()
{
  pinMode(pinCam, OUTPUT);              //sets the 'pinCam' as output pin
 // pinMode(pinSolen , OUTPUT);           //sets the 'pinStim' as output pin
  pinMode(pinLED, OUTPUT);              //sets the 'pinLED' as output pin
}

void loop()
{   
  
  for(int i = 0; i < 15; i++)
  {
        digitalWrite(pinCam, HIGH);     //turns 'pinCam' on                                      --turns camera on                          
        digitalWrite(pinLED, HIGH);     //writes led (can be analog instead of digital)      -- turns LED on
        
        digitalWrite(pinSolen, HIGH);

        //analogWrite(pinSolen, HIGH);   //writes stimulus                                    -- turns stimulus off
      
        delay(1000);                    //keeps on for a second               

        digitalWrite(pinCam, LOW);      //turns 'pinCam' off                                      --turns camera on                          
        digitalWrite(pinLED, LOW);      //writes led (can be analog instead of digital)       -- turns LED off      
        analogWrite(pinSolen, LOW);    //writes stimulus         -- turns stimulus off
        
        delay(1000);                    //turns off for a second               
  }     
   
}
