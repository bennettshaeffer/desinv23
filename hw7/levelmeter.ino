/*
 * Wasn't sure if this program was just supposed to turn on one light at a time
 * or to turn them all on as the pots value goes up
 * 
 * if the latter, just get rid of the digital pins going low in each it statement
 */

int potPin = A0;
int led1 = 5;
int led2 = 6;
int led3 = 9;

int potValue = 0;

void setup() {
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);

}

void loop() {
  potValue = analogRead(potPin);
  if(potValue >= 0 && potValue < 10){   //give is some wiggle room
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  if(potValue >= 10 && potValue < 341){    
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if(potValue >= 341 && potValue < 682){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else if(potValue >= 682){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
}
