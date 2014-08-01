/* 
  Arduino program to control high speed camera, LED light, and solenoid (trigger stimulus) during habituation
  experiment. 
  
  Send out 30 total pulses. 
  First 15 pulses will simulatenously turn on camera, LED light, and solenoid (trigger stimulus) - for one second.
  Next 15 pulses (16-30) will simulatenously turn on LED light and solenoid - for one second. 
  
  Created 13 July 2014 by Victoria Norton
*/
 
const int pinCam = 7;                   //pin the camera is connected to
const int pinSol = 53;                  //pin the solenoid is connected to
const int pinLED = 13;                  //pin the LED light is connected to

void setup()
{
  pinMode(pinCam, OUTPUT);              //sets the 'pinCam' as output pin
  pinMode(pinSol , OUTPUT);             //sets the 'pinStim' as output pin
  pinMode(pinLED, OUTPUT);              //sets the 'pinLED' as output pin
}

void loop()
{   
  for(int i = 0; i < 31; i++)
  {
    if(i < 16)
    {
        digitalWrite(pinCam, HIGH);     //turns camera on                          
        digitalWrite(pinLED, HIGH);     //turns LED on
        digitalWrite(pinSol, HIGH);     //turns stimulus on
      
        delay(1000);                    //keeps on for a second               

        digitalWrite(pinCam, LOW);      //turns camera off                          
        digitalWrite(pinLED, LOW);      //turns LED off      
        analogWrite(pinSol, LOW);       //turns stimulus off
        
        delay(1000);                    //turns off for a second               
    }
    else
    {
        digitalWrite(pinLED, HIGH);     //turns LED on
        digitalWrite(pinSol, HIGH);     //turns stimulus on
      
        delay(1000);                    //keeps on for a second               

        digitalWrite(pinLED, LOW);      //turns LED off      
        analogWrite(pinSol, LOW);       //turns stimulus off
        
        delay(1000);                    //turns off for a second         
    }
  }    
  delay(90000);
}
