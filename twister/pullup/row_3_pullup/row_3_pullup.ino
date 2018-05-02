//ARDUINO ROW 3
//DC 1 CIRCUIT CHECKER

//list of Digital Pins for soft buttons
int button11 = A1;
int button12 = A2;
int button13 = A3;
int button14 = A4;
int button15 = A5;

//keeping track of what state the buttons are in
int button11Reading;
int button12Reading;
int button13Reading;
int button14Reading;
int button15Reading;

//Challenge pins
int led_Circuit = 0;
int servo_Circuit = 1;
int dc_1_Circuit = 2;
int dc_2_Circuit = 3;

//LED Circuit Checker
int row_1 = 5;
int row_2 = 6;
//int row_3 = 9;
int row_4 = 10;
int row_5 = 11;
int row_6 = 12;

void setup() {
  pinMode(button11, INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP);
  pinMode(button13, INPUT_PULLUP);
  pinMode(button14, INPUT_PULLUP);
  pinMode(button15, INPUT_PULLUP);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

  pinMode(row_1, INPUT);
  pinMode(row_2, INPUT);
  //pinMode(row_3, INPUT);
  pinMode(row_4, INPUT);
  pinMode(row_5, INPUT);
  pinMode(row_6, INPUT);
}

void loop() {
  button11Reading = digitalRead(button11);
  button12Reading = digitalRead(button12);
  button13Reading = digitalRead(button13);
  button14Reading = digitalRead(button14);
  button15Reading = digitalRead(button15);

  //LED Circuit
  if (button13Reading == 0) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button14Reading == 0) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1
  if (button15Reading == 0 && row_1 == 1 && row_2 == 1 && row_4 == 1 && row_5 == 1 && row_6 == 1) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if (button12Reading == 0 && button15Reading == 0) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
