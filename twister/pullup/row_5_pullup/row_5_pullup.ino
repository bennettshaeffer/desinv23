//ARDUINO ROW 5
//ONLY OUTPUTSs

//list of Digital Pins for soft buttons
int button21 = A1;
int button22 = A2;
int button23 = A3;
int button24 = A4;
int button25 = A5;

//keeping track of what state the buttons are in
int button21Reading;
int button22Reading;
int button23Reading;
int button24Reading;
int button25Reading;

//Challenge pins
int led_Circuit = 0;
int servo_Circuit = 1;
int dc_1_Circuit = 2;
int dc_2_Circuit = 3;

void setup() {
  pinMode(button21, INPUT_PULLUP);
  pinMode(button22, INPUT_PULLUP);
  pinMode(button23, INPUT_PULLUP);
  pinMode(button24, INPUT_PULLUP);
  pinMode(button25, INPUT_PULLUP);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

}

void loop() {
  button21Reading = digitalRead(button21);
  button22Reading = digitalRead(button22);
  button23Reading = digitalRead(button23);
  button24Reading = digitalRead(button24);
  button25Reading = digitalRead(button25);

  //LED Circuit
  if (button24Reading == 0 && button25Reading == 0) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button22Reading == 0) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1 Circuit NA

  //DC 2 Circuit
  if (button22Reading == 0 && button23Reading == 0) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
