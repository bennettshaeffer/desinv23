//ARDUINO ROW 6
//ONLY OUTPUTSs

//list of Digital Pins for soft buttons
int button26 = A1;
int button27 = A2;
int button28 = A3;
int button29 = A4;
int button30 = A5;

//keeping track of what state the buttons are in
int button26Reading;
int button27Reading;
int button28Reading;
int button29Reading;
int button30Reading;

//Challenge pins
int led_Circuit = 0;
int servo_Circuit = 1;
int dc_1_Circuit = 2;
int dc_2_Circuit = 3;

void setup() {
  pinMode(button26, INPUT_PULLUP);
  pinMode(button27, INPUT_PULLUP);
  pinMode(button28, INPUT_PULLUP);
  pinMode(button29, INPUT_PULLUP);
  pinMode(button30, INPUT_PULLUP);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

}

void loop() {
  button26Reading = digitalRead(button26);
  button27Reading = digitalRead(button27);
  button28Reading = digitalRead(button28);
  button29Reading = digitalRead(button29);
  button30Reading = digitalRead(button30);

  //LED Circuit NA

  //Servo Circuit
  if (button27Reading == 0 && button28Reading == 0) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1 Circuit
  if (button27Reading == 0 && button28Reading == 0) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }


  //DC 2 Circuit
  if (button27Reading == 0 && button28Reading == 0) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
