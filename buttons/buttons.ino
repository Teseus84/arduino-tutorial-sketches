void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}


boolean diodeState = 0;

void loop() {
  if (digitalRead(12) == HIGH) {
    delay(20);
    diodeState = !diodeState;
    digitalWrite(13, diodeState);
    while (digitalRead(12) == HIGH);
    delay(20);

  }
}
