

int counter = 0;

void setup() {
  pinMode(13, OUTPUT);

}

void loop() {
 digitalWrite(13, HIGH);
 delay(50);
 digitalWrite(13, LOW);
 delay(50);
 counter += 1;
 if(counter % 29 == 0)    //breaks up the monotony
 {
  delay(random(50, 700));   //not actually sure if it chooses a random number every time but it really does not matter
 }
}
