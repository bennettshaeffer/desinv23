//ARDUINO ROW 2
//SERVO CIRCUIT CHECKER

//list of Digital Pins for soft buttons
int button6 = A1;
int button7 = A2;
int button8 = A3;
int button9 = A4;
int button10 = A5;

//keeping track of what state the buttons are in
int button6Reading;
int button7Reading;
int button8Reading;
int button9Reading;
int button10Reading;

//Challenge pins
int led_Circuit = 0;
int servo_Circuit = 1;
int dc_1_Circuit = 2;
int dc_2_Circuit = 3;

//LED Circuit Checker
int row_1 = 5;
//int row_2 = 6;
int row_3 = 9;
int row_4 = 10;
int row_5 = 11;
int row_6 = 12;


void setup() {
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

  pinMode(row_1, INPUT);
  //pinMode(row_2, INPUT);
  pinMode(row_3, INPUT);
  pinMode(row_4, INPUT);
  pinMode(row_5, INPUT);
  pinMode(row_6, INPUT);
}

void loop() {
  button6Reading = digitalRead(button6);
  button7Reading = digitalRead(button7);
  button8Reading = digitalRead(button8);
  button9Reading = digitalRead(button9);
  button10Reading = digitalRead(button10);

  //LED Circuit
  if (button8Reading == 0) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button7Reading == 0 && button9Reading == 0 && row_1 == 1 && row_3 == 1 && row_4 == 1 && row_5 == 1 && row_6 == 1) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1
  if (button7Reading == 0) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if (button7Reading == 0) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
