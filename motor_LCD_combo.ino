/*
Note: don't use pin 7 for the motor operations ("motorPin")
Python .format() in C++
char sec_val_info[100];
sprintf(sec_val_info, "This is seconds %s", str_sec);
//Serial.println("True");
Serial.println(sec_val_info);
char sec_len_info[100];
sprintf(sec_len_info, "This is seconds length %d", sec_len);
Serial.println(sec_len_info);
*/

const int motorPin = 9;
#include <LiquidCrystal.h>


const int rs = 12, en =11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  lcd.begin(8, 2);
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0, 2); // in (col, row) format
  lcd.print("GO ENGINEERING");
  //delay(1000);
  lcd.setCursor(3, 0);
  lcd.print(millis()/1000);
  Serial.println(millis());
  if (Serial.available()) {
    int speed = Serial.parseInt();
    //Serial.println(speed);
    if (speed >= 0 && speed <= 255) {
       analogWrite(motorPin, speed);
    }
 }  
}

/* Scrapped up code: 
cd.setCursor(0, 2); // in (col, row) format
  lcd.print("GO ENGINEERING");
  //delay(1000);
  int seconds = (millis()/1000);
  Serial.println(millis()/1000);
  String str_sec = String(seconds);
  Serial.println(str_sec);
  Serial.println("***");
  int sec_len = str_sec.length();
  int whole_num_len = floor(seconds);

  lcd.setCursor(4 - whole_num_len, 0); 
  // number goes to left when digit amount increases
  lcd.print(str_sec.substring(0, whole_num_len));
  lcd.setCursor(4, 0);
  lcd.print(".");
  lcd.setCursor(5, 0);
  int str_len = str_sec.length();
  lcd.print(str_sec.substring((whole_num_len), sec_len - whole_num_len));
*/
