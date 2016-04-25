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
