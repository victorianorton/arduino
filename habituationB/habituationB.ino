/* 
  Arduino program to control high speed camera, LED light, and solenoid (trigger stimulus) during habituation
  experiment. 
  
  Send out 45 total signals. 
  First 30 pulses will simultaneously turn on LED light, and solenoid (trigger stimulus) - for one second.
  Then there is a 3 second pause, before the next 15 signals which simultaneously turn on  camera, LED light, and solenoid - for one second. 
  
  Created 13 July 2014 by Victoria Norton
*/
 
const int pinCam = 7;                 //pin the camera is connected to
const int pinSol = 53;                //pin the solenoid which is connected to the stimulus
const int pinLED = 13;                //pin the LED light is connected to

void setup()
{
  pinMode(pinCam, OUTPUT);            //sets the 'pinCam' as output pin
  pinMode(pinSol , OUTPUT);           //sets the 'pinStim' as output pin
  pinMode(pinLED, OUTPUT);            //sets the 'pinLED' as output pin
}

void loop()
{   
  for(int i = 0; i < 46; i++)
  {
    if(i < 31)
    {
      digitalWrite(pinLED, HIGH);     //turns LED on
      digitalWrite(pinSol, HIGH);     //turns solenoid on
      
      delay(1000);                    //keeps on for a second               

      digitalWrite(pinLED, LOW);      //turns LED off      
      analogWrite(pinSol, LOW);       //turns solenoid off
        
      delay(1000);                    //turns off for a second               
    }
    else if(i == 31)
    {
      delay(3000);                    //pause for 3 seconds
    }
    else 
    {
      digitalWrite(pinCam, HIGH);     //turns camera on                          
      digitalWrite(pinLED, HIGH);     //turns LED on
      digitalWrite(pinSol, HIGH);     //turns solenoid on
      
      delay(1000);                    //keeps on for a second               

      digitalWrite(pinCam, LOW);      //turns camera off                          
      digitalWrite(pinLED, LOW);      //turns LED off      
      analogWrite(pinSol, LOW);       //turns solenoid off
        
      delay(1000);                    //turns off for a second               
    }
  }    
  delay(90000);
}