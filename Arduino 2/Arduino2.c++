#include <math.h>
#define rec 2
#define S_port 9600
#define d 100

void setup(){
  Serial.begin(S_port);
  pinMode(rec, INPUT);
}
void loop(){
  if(digitalRead(rec) == 0){
      int binary[8];
      int val = 0;
      delay(110);
      for(int i = 0; i < 8; i++){
        binary[i] = digitalRead(rec) == 0 ? 1 : 0;
        delay(d);
      }
      for(int i = 0; i < 8; i++){
        Serial.print(binary[i]);
        binary[i] = binary[i]*pow(2, 7-i);
        if(binary[i] > 0) binary[i]++;
      }
      for(int i = 0; i < 8; i++){
         val = val + binary[i];
      }
      Serial.println();
      Serial.println(val);
      delay(d);
  }
}