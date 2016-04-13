void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, INPUT_PULLUP); //nnapięcie 5v na pinie
}


boolean diodeState = 0;

void loop() {
  if (digitalRead(12) == LOW) {
    delay(20);
    diodeState = !diodeState;
    digitalWrite(13, diodeState);
    while (digitalRead(12) == LOW);
    delay(20);

  }
}
