
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "T7dVXgctLFyz8WHbzJWfdaH9dPdG1cmQ";
char ssid[] = "siddhu";
char pass[] = "123456789";



#define PLAY_E 5 //NodeMCU pin d1
#define REC 2    //NodeMCU pin d4
#define PLAY_L 4 //NodeMCU pin d2

#define IR1 D5
#define IR2 D6
#define IR3 D7

bool ir1;
bool ir2;
bool ir3;

int recordTime ;

void setup() 
{

  pinMode(REC,OUTPUT);
  pinMode(PLAY_L,OUTPUT);
  pinMode(PLAY_E,OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  
  Serial.begin(9600); 
  Blynk.begin(auth,ssid,pass);

}

void loop() 
{
  ir1= digitalRead(IR1);
  ir2= digitalRead(IR2);
  ir3= digitalRead(IR3);
  
    while (Serial.available() > 0) {
          char C = (char)Serial.read();
          
            if(C =='p' || C =='P'){
            playSignal ();
            break; 
            }
               
            else if(C =='r' || C =='R'){
              record(3000);              
            }
             
            else if(C =='l' || C =='L'){
              playSignal_L (1000);             
			  }             
           
     
    }

    
      
  if(ir1==0)
  { 
   Serial.println("Person enters into cabin...");
   //Blynk.notify("Alert:Dry waste basket is full ..");
   playSignal();
   delay(1000);
   }
  else if(ir2==0)
  { 
   Serial.println("Dry Dustbin is Full");
   Blynk.notify("Alert:Dry waste basket is full .."); 
   delay(2000);
   }

   else if(ir3==0)
  { 
   Serial.println("Wet Dustbin is Full");
   Blynk.notify("Alert:Wet waste basket is full .."); 
   delay(2000);
   }
   
   Blynk.run();
  delay(1000);
}
 
void record(int t) //t is the recording time (us)
{
      recordTime =t;
      digitalWrite(REC, HIGH);
      //Serial.println("Recording started");
      delay(t);
      digitalWrite(REC, LOW);
      //Serial.println("Recording Stopped ");
}

void playSignal ()
{
   digitalWrite(PLAY_E, HIGH);
  delay(50);
  digitalWrite(PLAY_E, LOW);  
    //Serial.println("Playbak Started"); 
    if(recordTime == 0)
    {
      delay(recordTime + 5000);
    } 
    else
    {
      delay(recordTime);
    }
  //Serial.println("Playbak Ended");
  
}

void playSignal_L (int l) 
{
     digitalWrite(PLAY_L, HIGH); 
     //Serial.println("Playbak L Started");  
     delay(l);
     digitalWrite(PLAY_L, LOW);
     //Serial.println("Playbak L Ended");    
}
