const int motorPin = 9;
#include <LiquidCrystal.h>


const int rs = 12, en =11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int trigPin = 8;
const int echoPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  while (Serial.available() == false) {}
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
