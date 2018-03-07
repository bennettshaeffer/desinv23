/*
 * displays the amount of minutes until your meeting in number of flashes
 */

int minutes = 5;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if(minutes == 0){
    digitalWrite(13, HIGH);   //static on when the meeting starts
    return 1;
  }
  for(int count = 0; count < minutes; count++){
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(300);
    count ++;
  }
  delay((minutes * 60000));
  minutes = minutes - 1;
 
}
