/*
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
*/
#include <LiquidCrystal.h>

long DELAY = 400;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = {
  B00000,
  B10001,
  B00100,
  B00000,
  B10001,
  B01110,
  B00000,
};


byte sadley[8] = {
  B00000,
  B10001,
  B00100,
  B00000,
  B01110,
  B10001,
  B00000,
};



byte normaley[8] = {
  B00000,
  B10001,
  B00100,
  B00000,
  B11111,
  B00000,
  B00000,
};

byte handsDown[8] = {
  B00100,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001,
};


byte handsMiddle[8] = {
  B00100,
  B00100,
  B11111,
  B00100,
  B00100,
  B01010,
  B10001,
};

byte handsUp[8] = {
  B00100,
  B10101,
  B01110,
  B00100,
  B00100,
  B01010,
  B10001,
};

void setup() {
  lcd.createChar(0, smiley);
  lcd.createChar(1, sadley);
  lcd.createChar(2, handsUp);
  lcd.createChar(3, handsDown);
  lcd.createChar(4, handsMiddle);
  lcd.createChar(5, normaley);
  lcd.begin(16, 2);

}

void loop() {
  top();
  middle();
  bottom();
  middle();
}

void top() {
  lcd.setCursor(4, 0);
  lcd.write(byte(0));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  delay(DELAY * 2);
}

void middle() {
  lcd.setCursor(4, 0);
  lcd.write(byte(5));
  lcd.setCursor(4, 1);
  lcd.write(byte(4));
  delay(DELAY);
}
void bottom() {
  lcd.setCursor(4, 0);
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(3));
  delay(DELAY * 2);
}

