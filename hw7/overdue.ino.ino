/*
 * Super fake "low frequency oscillator" modulation on the LEDPIN
 * 
 * I know it does not produce a square wave, its just a fragment from a past idea (also it technically produces square waves so whatever)
 */

int led = 13;
int squareLFO = 1000;
int dir = 0;
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13,HIGH);
  delay(squareLFO);
  digitalWrite(13,LOW);
  delay(squareLFO);
  
  if(dir == 0)
  {
    squareLFO = squareLFO - 100;
    if(squareLFO == 0)
    {
      dir = 1;
      squareLFO = 100;
    }
  }
  else
  {
    squareLFO = squareLFO + 100;
    if(squareLFO == 1000)
    {
      dir = 0;
      squareLFO = 900;
    }
  }
}
