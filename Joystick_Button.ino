#include <ezButton.h>

#include <LiquidCrystal.h>


const int rs = 12, en =11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN   7  // Arduino pin connected to SW  pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int cursor = 4;
int prev_x_val = 500;
int prev_y_val = 0;

ezButton button(SW_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  button.setDebounceTime(0); // checks immediately 
  // to be sure that pushbutton is in HIGH/LOW state
}

void loop() {
  Serial.end();
  Serial.begin(9600);
  while (Serial.available() == false) {}
  String user_input = Serial.readString();
  user_input.trim();
  if (user_input == "stop") {
    Serial.println("---");
    Serial.println("Program Terminated");
    while (1 + 1 == 2) {}
  }

  button.loop(); // does the debouncing

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  
  // Note: if you want to increase twice in the same direction,
  // bring joystick back to the center and then move it to the side again
  if (x_Joystick_movement(xValue, prev_x_val)) {
    if (xValue <= 400)  {
      cursor = cursor + 1;
      lcd.setCursor(cursor,0);
      Serial.println("Increased");   
    }
    else if (xValue >= 600) {
      cursor = cursor - 1;
      lcd.setCursor(cursor - 1,0);
      Serial.println("Decreased");    
    }
  }

  if (button.isPressed()) {
    Serial.end();
    Serial.begin(9600);
    Serial.println("Give the text that you want to see on the LCD: ");
    while (Serial.available() == false) {}
    String desired_txt = Serial.readString();
    desired_txt.trim();
    lcd.print(desired_txt);    
  }

  prev_x_val = xValue;
}

bool x_Joystick_movement(int xcurrent, int xprevious) {
  // Detetcts movement change horizontally
  int reading_current = map(xcurrent, 0, 1023, 0, 12);
  int reading_previous = map(xprevious, 0, 1023, 0, 12);
  int change = abs(reading_current - reading_previous);
  Serial.print("Change in x position of joystick: ");
  Serial.println(change);
  if (change >= 5) { 
    // anything more than the center, which is 6
    return true;
  }
  else {
    return false;
  }
}
