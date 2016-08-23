#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte polishLetter[8] = {
  B00000,
  B00000,  
  B01110,
  B10001,
  B11111,
  B10000,
  B01110,
  B00010,  
};

void setup() {
  lcd.createChar(0, polishLetter);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(3, 0);
  lcd.print("Kocham");
  lcd.setCursor(5, 1);
  lcd.print("Ci");
  lcd.write(byte(0));
  lcd.print(" Olu" );
  lcd.print(" :*" );
}
