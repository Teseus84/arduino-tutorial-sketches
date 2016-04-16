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

int SCROLL_COUNT = 13;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print(":)");
}

void loop() {

  for (int i = 0; i <= SCROLL_COUNT; i++) {
    lcd.scrollDisplayRight();
    delay(250);
  }

  for (int i = 0; i <= SCROLL_COUNT; i++)  {
    lcd.scrollDisplayLeft();
    delay(250);
  }

}
