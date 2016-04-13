void setup() {
  for(int i=0;i<=3;i++){
    pinMode(i,OUTPUT);
  }

}

boolean forward = true;

void loop() {
  if(forward){
    for(int i=0;i<=3;i++){
      digitalWrite(i,HIGH);
      digitalWrite(i-1,LOW);
      if(i!=0){
        delay(500);
      }
  }
    forward = false;
  }else{
    for(int i=3;i>=0;i--){
      digitalWrite(i,HIGH);
      digitalWrite(i+1,LOW);
      if(i!=3){
       delay(500);  
      }
      
    }
    forward = true;
  }
}
