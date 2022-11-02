// C code
//

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50);
}

void loop()
{
  Serial.println("hi, what's your name and age? Type it in [name]; [age] format");
  while (Serial.available() == false) {}
  
  char ch[50];
  //char ch_char_extract[50];
  String init_string = Serial.readString();
  init_string.toCharArray(ch, 50);
  Serial.println(init_string);
  String cool = String(ch[1]);
  cool.concat("HI");
  Serial.println(cool);
  char ch_char_extract[50] = "character extract ";
  char input_string[10];
  char age;
  char age_str[50];
  //sscanf(ch, "%c", input_string);
  for (int exit = 0; exit < strlen("string"); exit++) {
    ch[50] = ch[exit];
    ch_char_extract.concat(ch[exit]);
    Serial.println(ch_char_extract);
    sscanf(ch, "%c", input_string);
    //input_string.concat(new_char);
    Serial.println(input_string);
    }
  //sscanf(ch, "%c", input_string);
  //itoa(age, age_str, DEC);
  //input_string.concat(" hello ");
  //String(input_string).concat(String(age));
  //Serial.println(input_string);
  /*
  for (int exit = 0; exit < strlen("string"); exit++) {
    if (isDigit(ch[exit])) {
      sscnaf(ch, "%c", new_char);
      finalized.concat(new_char);
    }
    println(finalized);
  }
  Serial.println(finalized);
  */
  /*
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  */
}
