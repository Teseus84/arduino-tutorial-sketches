void setup() {
  for(int i=0;i<=3;i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  for(int i=0;i<=3;i++){
    digitalWrite(i,HIGH);
    if(i==0){
      digitalWrite(3,LOW);
    }else{
      digitalWrite(i-1,LOW);
    }
    delay(500);
  }

}
