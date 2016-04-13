// A0 - light sensor (fotorezystor)
// A1 - potentiometer (potencjometr)
// Digital pins:
// 0-4 - diodes
// 11-13 - input pull up pins (INPUT_PULLUP), 11 - mode3, 12 - mode2, 13 mode1

const int LAST_DIODE_INDEX = 4;
const String MODE_1 = "1";
const String MODE_2 = "2";
const String MODE_3 = "3";
const int POTENTIOMETER_SCALE = 3;

boolean forward = true;
String mode = MODE_1;

void setup() {

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  for (int i = 0; i <= LAST_DIODE_INDEX; i++) {
    pinMode(i, OUTPUT);
  }

  for (int i = 11; i <= 13; i++) {
    pinMode(i, INPUT_PULLUP);
  }

}

void loop() {
  if (digitalRead(13) == LOW) {
    changeMode(13, MODE_1);
  }

  if (digitalRead(12) == LOW) {
    changeMode(12, MODE_2);
  }
  if (digitalRead(11) == LOW) {
    changeMode(11, MODE_3);
  }

  if (mode == MODE_1) {
    shine(1);
  }

  if (mode == MODE_2) {
    knightRider();
  }

  if (mode == MODE_3) {
    lightSensor();
  }

}

void changeMode(int dRead, String newMode) {
  delay(20);
  mode = newMode;
  while (digitalRead(dRead) == LOW);
  delay(20);
}

void shine(int value) {
  for (int i = 0; i <= LAST_DIODE_INDEX; i++) {
    digitalWrite(i, value);
  }
}

void knightRider() {

  if (forward) {
    for (int i = 0; i <= LAST_DIODE_INDEX; i++) {
      int delayTime = analogRead(A1) / POTENTIOMETER_SCALE;
      if (isButtonPressed()) {
        return;
      }
      goForward(i);
      if (i != 0) {
        delay(delayTime);
      }
    }
    forward = false;
  } else {
    for (int i = LAST_DIODE_INDEX; i >= 0; i--) {
      int delayTime = analogRead(A1) / POTENTIOMETER_SCALE;
      if (isButtonPressed()) {
        return;
      }
      goBack(i);
      if (i != LAST_DIODE_INDEX) {
        delay(delayTime);
      }
    }
    forward = true;
  }
}

void goForward(int i) {
  digitalWrite(i, HIGH);
  digitalWrite(i - 1, LOW);
}

void goBack(int i) {
  digitalWrite(i, HIGH);
  digitalWrite(i + 1, LOW);
}


boolean isButtonPressed() {
  if (digitalRead(13) == LOW || digitalRead(12) == LOW || digitalRead(11) == LOW) {
    return true;
  }
  return false;
}


void lightSensor() {
  int value;
  int light = analogRead(A0);

  if (light > 900) {
    value = 1;
  } else {
    value = 0;
  }

  shine(value);
}



