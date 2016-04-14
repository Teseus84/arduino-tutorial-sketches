
const int LAST_DIODE_PIN = 4;
boolean forward = true;
int delayTime = 1000;
boolean debug = false;


void setup() {
  if (debug) {
    enableDebug();
  }

  for (int i = 0; i <= LAST_DIODE_PIN; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
}



void loop() {

  if (forward) {
    for (int i = 0; i <= LAST_DIODE_PIN; i++) {
      delayTime = readAndDivide();
      if (debug) {
        sendSerialMessage(delayTime); //debug only
      }
      goForward(i);
      if (i != 0) {
        delay(delayTime);
      }
    }
    forward = false;
  } else {
    for (int i = LAST_DIODE_PIN; i >= 0; i--) {
      delayTime = readAndDivide();
      if (debug) {
        sendSerialMessage(delayTime); //debug only
      }
      goBack(i);
      if (i != LAST_DIODE_PIN) {
        delay(delayTime);
      }
    }
    forward = true;
  }
}

int readAndDivide() {
  int reading = analogRead(A0);
  return reading / 3;
}

void goForward(int i) {
  digitalWrite(i, HIGH);
  digitalWrite(i - 1, LOW);
}

void goBack(int i) {
  digitalWrite(i, HIGH);
  digitalWrite(i + 1, LOW);
}

void enableDebug() {
  Serial.begin(9600); // debug only
  while (!Serial); // debug only
}

void sendSerialMessage(int message) {

  Serial.println(message);  //debug only

}

