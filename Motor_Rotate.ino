#include <ezButton.h>
#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 12, en =11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN   7  // Arduino pin connected to SW  pin
#define enable   A5  // Arduino pin connected to SW  pin


const int inPin2 = 6;
const int inPin1 = 10;

const int wait_time = 2000;

int writing = 0;
int init_time = 0;

ezButton button(SW_PIN);

void setup() {
  Wire.setClock(10000);
  lcd.begin(16, 2);
  Serial.begin(9600);
  button.setDebounceTime(0); // checks immediately 
}

void loop() {
  Serial.println("at top");
  button.loop(); // does the debouncing
  int xValue = analogRead(VRX_PIN);
  //Serial.println(xValue);
  
  if (xValue <= 200)  {
    //Serial.print("This is X: ");     
    //Serial.println(xValue);
    analogWrite(enable, 200);
    digitalWrite(inPin2, HIGH);
    digitalWrite(inPin1, LOW);
  }
  else if (xValue >= 800) {
    //Serial.print("This is X: ");
    //Serial.println(xValue);
    analogWrite(enable, 200);
    digitalWrite(inPin2, LOW);
    digitalWrite(inPin1, HIGH);
  }

  if (button.isPressed()) {
    init_time = millis();
    analogWrite(enable, 0);
    digitalWrite(inPin2, LOW);
    digitalWrite(inPin1, LOW);
    // if button is clicked twice
    Serial.println("what's up");
    while (millis() - init_time < wait_time) {
      Serial.println(button.getStateRaw());
      if (button.getStateRaw() == 1) {
        while ((millis() - init_time) < wait_time) {
          if (button.getStateRaw() == 0) {
            Serial.println("terminated");
            // note for future: always clear before you write
            lcd.clear();
            lcd.setCursor(1, 2);
            lcd.print("terminated");
            while (1 + 1 == 2) {}
          }
        }
      }
    }    
    Serial.println("pause mode");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("enter length");
    lcd.setCursor(0, 1);
    lcd.print("of pause");
    writing = millis();
    Serial.print(writing);
    while (millis() - writing < 2500) {}
    lcd.clear();
    lcd.print("to Serial");
    lcd.setCursor(0, 1);
    lcd.print("Monitor");
    Serial.end();
    Serial.begin(9600);
    while (!Serial.available()) {}
    int pause_time = millis();
    int pause = Serial.parseInt() * 1000;
    while (millis() - pause_time < pause) {}
    lcd.clear();
    Serial.print("done");
  }
}
/* Test program to figure out 
if lcd is working and able to use both columns

lcd.clear();
lcd.setCursor(1, 2);
int lcd_print_time = millis();
lcd.print("terminated");

while ((millis() - lcd_print_time) < 5000) {}
int lcd_clear_time = millis();
lcd.clear();

while ((millis() - lcd_clear_time) < 5000) {}
*/