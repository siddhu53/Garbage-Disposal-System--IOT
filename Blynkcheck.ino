#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>


char auth[]="T7dVXgctLFyz8WHbzJWfdaH9dPdG1cmQ";
char ssid[]="siddhu";
char pass[]="123456789";

#define IR D1
bool ir;
void setup()
{
  Serial.begin(9600);
  pinMode(IR,INPUT_PULLUP);
  Blynk.begin(auth,ssid,pass);
 }
 void loop()
 {
  ir = digitalRead(IR);
  if(ir==0)
  {
    Serial.println("Object present");
    delay(2000);
    Blynk.notify("Alert:Hello it worked");
    }
    else if(ir==1)
    {
      Serial.println("empty");
      delay(2000);
      }
      Blynk.run();
  }
