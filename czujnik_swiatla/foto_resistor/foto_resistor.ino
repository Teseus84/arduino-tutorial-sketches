boolean debug = false;

void setup() {
  if (debug) {
    Serial.begin(9600);
    while (!Serial);
  }
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  int light = analogRead(A0);
  if (debug) {
    Serial.println(light);
    delay(1000);
  }
  if (light > 900) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}
