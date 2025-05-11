#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(200);
  Serial.end();
  Serial.begin(9600);
  while (Serial.available() == false) {}
  String user_input = Serial.readString();
  user_input.trim();
  if (user_input == "stop") {
    Serial.println("---");
    Serial.println("Program Terimnated");
    while (1 + 1 == 2) {}
  }
}
