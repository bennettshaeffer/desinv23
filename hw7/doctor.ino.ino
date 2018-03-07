/*
 * Wanted to make the on off times independent but the whole way arduinos treat arrays is dumb so I just took code from here: https://www.arduino.cc/reference/en/language/variables/utilities/sizeof/
 */

int timeArray[] = {1500, 200, 250, 3000, 100, 256, 10, 270, 1352, 360, 638};  //Random Numbers represent the mysteries of health (or something idk)

void setup() {
  pinMode(13, OUTPUT);
  
}

void loop() {

  for(int i = 0; i < (sizeof(timeArray)/sizeof(int)); i ++)   //arduinos are super annoying
  {
    digitalWrite(13, HIGH);
    delay(timeArray[i]);
    digitalWrite(13,LOW);
    delay(timeArray[i]);
    if(i == (sizeof(timeArray)/sizeof(int)) - 1){
      i == 0;
    }
  }
}
