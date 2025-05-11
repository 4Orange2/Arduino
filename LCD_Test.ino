#include <LiquidCrystal.h>


const int rs = 12, en =11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(8, 2);
}

void loop()
{
  lcd.setCursor(0, 2); // in (col, row) format
  lcd.print("GO ENGINEERING");
  //delay(1000);
  lcd.setCursor(3, 0);
  lcd.print(millis()/1000);
  lcd.setCursor(4, 0);
  lcd.print(".");
  lcd.setCursor(5, 0);
  lcd.print(millis()/100);
}
