const int diodeLastIndex = 4;
boolean debug = false;

void setup() {
  if (debug) {
    Serial.begin(9600);
    while (!Serial);
  }
  pinMode(A0, INPUT);
  for (int i = 0; i <= diodeLastIndex; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  int value;
  int light = analogRead(A0);
  if (debug) {
    Serial.println(light);
    delay(1000);
  }

  if (light > 900) {
    value = 1;
  } else {
    value = 0;
  }

  for (int i = 0; i <= diodeLastIndex; i++) {
    digitalWrite(i, value);
  }
}
