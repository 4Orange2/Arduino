// Name-age Communicator

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50);
}

void loop()
{
  Serial.println("hi, what's your name and age? Type it in [name]; [age] format");
  while (Serial.available() == false) {}
  
  char huamn_info[50];
  String init_string = Serial.readString();
  init_string.toCharArray(huamn_info, 50);
  String age_str = "";
  String name_str = "";
  for (int exit = 0; exit < strlen(huamn_info); exit++) {
    if (isAlpha (huamn_info[exit])) {
      name_str.concat(huamn_info[exit]);
      Serial.println(name_str);
      }
    if (isDigit(huamn_info[exit])) { 
      age_str.concat(huamn_info[exit]);
      Serial.println(age_str);
      }
    }
  String sentence = "Your name is ";
  sentence.concat(name_str);
  sentence.concat(", and you are ");
  sentence.concat(age_str);
  sentence.concat(" years old.");
  Serial.println(sentence);
}
