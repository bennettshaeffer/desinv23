//ARDUINO ROW 4
//DC 2 CIRCUIT CHECKER

//list of Digital Pins for soft buttons
int button16 = A1;
int button17 = A2;
int button18 = A3;
int button19 = A4;
int button20 = A5;

//keeping track of what state the buttons are in
int button16Reading;
int button17Reading;
int button18Reading;
int button19Reading;
int button20Reading;

//Challenge pins
int led_Circuit = 0;
int servo_Circuit = 1;
int dc_1_Circuit = 2;
int dc_2_Circuit = 3;

//LED Circuit Checker
int row_1 = 5;
int row_2 = 6;
int row_3 = 9;
//int row_4 = 10;
int row_5 = 11;
int row_6 = 12;


void setup() {
  pinMode(button16, INPUT_PULLUP);
  pinMode(button17, INPUT_PULLUP);
  pinMode(button18, INPUT_PULLUP);
  pinMode(button19, INPUT_PULLUP);
  pinMode(button20, INPUT_PULLUP);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

  pinMode(row_1, INPUT);
  pinMode(row_2, INPUT);
  pinMode(row_3, INPUT);
  //pinMode(row_4, INPUT);
  pinMode(row_5, INPUT);
  pinMode(row_6, INPUT);
}

void loop() {
  button16Reading = digitalRead(button16);
  button17Reading = digitalRead(button17);
  button18Reading = digitalRead(button18);
  button19Reading = digitalRead(button19);
  button20Reading = digitalRead(button20);

  //LED Circuit
  if (button19Reading == 0) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button19Reading == 0) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1
  if (button20Reading == 0) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if (button16Reading == 0 && button17Reading == 0 && button18Reading == 0 && button19Reading == 0 && button20Reading == 0 && row_1 == 1 && row_2 == 1 && row_3 == 1 && row_5 == 1 && row_6 == 1) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
