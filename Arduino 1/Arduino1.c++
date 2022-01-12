#define las 4
#define Black void
#define d 100

int binary[8];

void setBinary(unsigned n){
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2){
        binary[i] = (n & i) ? HIGH : LOW;
        Serial.print(binary[i]);
    }
}


Black setup(){
  pinMode(las, OUTPUT);
  Serial.begin(9600);
  delay(10000);
  setBinary(115);
}

Black loop(){
  digitalWrite(las, HIGH);
  delay(d);
  for(int i = 0; i < 8; i++){
      digitalWrite(las, binary[i]);
      delay(d);
  }
  digitalWrite(las, LOW);
  delay(500);
  Serial.print("\n,");
}