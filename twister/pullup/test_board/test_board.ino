int button1 = A1;
int button2 = A2;
int button3 = A3;
int button4 = A4;
int button5 = A5;

int oneRead;
int twoRead;
int threeRead;
int fourRead;
int fiveRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
}

void loop() {
  oneRead = digitalRead(button1);
  twoRead = digitalRead(button2);
  threeRead = digitalRead(button3);
  fourRead = digitalRead(button4);
  fiveRead= digitalRead(button5);

  Serial.print("1: ");
  Serial.println(oneRead);
  Serial.print("2: ");
  Serial.println(twoRead);
  Serial.print("3: ");
  Serial.println(threeRead);
  Serial.print("4: ");
  Serial.println(fourRead);
  Serial.print("5: ");
  Serial.println(fiveRead);
}
