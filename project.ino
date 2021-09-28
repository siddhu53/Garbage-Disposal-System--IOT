#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "T7dVXgctLFyz8WHbzJWfdaH9dPdG1cmQ";
char ssid[] = "siddhu";
char pass[] = "123456789";

#define IR1 D0
#define IR2 D1
#define IR3 D2
bool ir1;
bool ir2;
bool ir3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  Blynk.begin(auth,ssid,pass);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  ir1= digitalRead(IR1);
  ir2= digitalRead(IR2);
  ir3= digitalRead(IR3);
  
  if(ir3==0)
  {
   Serial.println("Person is detected");
   
   delay(3000);
   }
   
//  
//  else if(ir1==0 && ir2==0)
//   {
//    Serial.println("Both Baskets are full..");
//    Blynk.notify("Alert:Both Baskets are full");
//    delay(2000);
//    }
//    
  else if(ir1==0)
  { 
   Serial.println("Dry waste basket is full ..");
   Blynk.notify("Alert:Dry waste basket is full ..");
   
   delay(2000);
   }
   
   else if(ir2 ==0)
   {
    Serial.println("wet waste basket is full ..");
    Blynk.notify("Alert:Wrt waste basket is full ..");
    
    delay(2000);
   }



   else
   {
    delay(1000);
   }
   Blynk.run();
}
