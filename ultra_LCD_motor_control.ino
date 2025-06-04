const int motorPin = 9;
#include <LiquidCrystal.h>


const int rs = 12, en =11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 8;
const int echoPin = 13;
int current_time;
int init_time;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  while (Serial.available() == false) {}
  String choice = Serial.readString();
  choice.trim();
  Serial.println(choice);
  if (choice == "ultrasound") {
  lcd.clear();
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH); 
  // pulseIn() returns duration in microseconds
  // Calculating the distance
  int distance_in_cm = duration * 0.034 / 2;
  // speed of sound = 340 m/s
  // speed of sound/ms = 0.34 m/ms or 34 cm/ms microseconds
  // Prints the distance on the Serial Monitor
  int distance_in_m = distance_in_cm / 100;
  Serial.print("Distance: ");
  Serial.println(distance_in_cm);
  Serial.println(distance_in_m);
  lcd.setCursor(1, 0);
  lcd.print("Distance: ");
  lcd.setCursor(11, 0);
  lcd.print(distance_in_cm);
  lcd.setCursor(12 + String(distance_in_cm).length(), 0);
  lcd.print("cm");
  Serial.end();
  Serial.begin(9600);
  } 
  else if (choice == "motor") {
    Serial.println("Give Speed and then time of operation in seconds (separately): ");
    Serial.end();
    Serial.begin(9600);
    while (Serial.available() == false) {} 
    int speed = Serial.parseInt();
    Serial.end();
    Serial.begin(9600);
    while (Serial.available() == false) {} 
    int time_of_oper = Serial.parseInt();
    Serial.println("Speed: ");
    Serial.println(speed);
    Serial.println("Time: ");
    Serial.println(time_of_oper);  
    // Goes at desired speed for time specified
    init_time = millis();
    if (speed >= 0 && speed <= 255) {
      bool stopped = false;
      analogWrite(motorPin, speed);
      while (stopped == false) {
        current_time = millis();
        String second_choice = Serial.readString();
        Serial.println("This is second choice: ");
        Serial.println(second_choice);
        second_choice.trim();
        delay(1000);
        if (second_choice == "ultrasound") {
          lcd.clear();
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          int duration = pulseIn(echoPin, HIGH); 
          // pulseIn() returns duration in microseconds
          // Calculating the distance
          int distance_in_cm = duration * 0.034 / 2;
          // speed of sound = 340 m/s
          // speed of sound/ms = 0.34 m/ms or 34 cm/ms microseconds
          // Prints the distance on the Serial Monitor
          int distance_in_m = distance_in_cm / 100;
          Serial.print("Distance: ");
          Serial.println(distance_in_cm);
          Serial.println(distance_in_m);
          lcd.setCursor(1, 0);
          lcd.print("Distance: ");
          lcd.setCursor(11, 0);
          lcd.print(distance_in_cm);
          lcd.setCursor(12 + String(distance_in_cm).length(), 0);
          lcd.print("cm");
          Serial.end();
          Serial.begin(9600);
        }
        else if (second_choice == "stop") {
          Serial.println("ENTERED STOP");
          analogWrite(motorPin, 0);
          stopped = true;
        }
        if ((current_time - init_time) >= (time_of_oper * 1000)) {
          Serial.println("AHHAAAAAAAAH");
          Serial.println(choice);
          analogWrite(motorPin, 0);
          stopped = true;
        }
      }
    }
    Serial.end();
    Serial.begin(9600);
  }
}
