#define FSRPIN A3
#define ECGPIN A4
#define SKINPIN A5
// Bridge
#include <Bridge.h>

float p = 0;
float e = 0;
float s = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Bridge.begin();
}

void loop() {
  p = analogRead(FSRPIN);
  e = analogRead(ECGPIN);
  s = analogRead(SKINPIN);
  Serial.print("FSR Pressure: ");
  Serial.println(p);
  Serial.print("ECG Value: ");
  Serial.println(e);
  Serial.print("Skin Value: ");
  Serial.println(s);

  // Bridge

  Bridge.put("p",String(p));
  Bridge.put("e",String(e));
  Bridge.put("s",String(s));
  
  //delay(200); //每秒回傳一次資料
}
