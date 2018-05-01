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
int led_Circuit = 2;
int servo_Circuit = 3;
int dc_1_Circuit = 4;
int dc_2_Circuit = 5;

//LED Circuit Checker
int row_1 = 6;
int row_2 = 7;
int row_3 = 8;
//int row_4 = 9;
int row_5 = 10;
int row_6 = 11;

void setup() {
  Serial.begin(9600);

  pinMode(button16, INPUT);
  pinMode(button17, INPUT);
  pinMode(button18, INPUT);
  pinMode(button19, INPUT);
  pinMode(button20, INPUT);

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
  button16Reading = analogRead(button16);
  Serial.print("Button 5 reading = ");
  Serial.println(button16Reading);
  button17Reading = analogRead(button17);
  Serial.println(button17Reading);
  button18Reading = analogRead(button18);
  Serial.println(button18Reading);
  button19Reading = analogRead(button19);
  Serial.println(button19Reading);
  button20Reading = analogRead(button20);

  //LED Circuit
  if (button19Reading == 1023) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button19Reading == 1023) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1
  if (button20Reading == 1023) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if (button16Reading == 1023 && button17Reading == 1023 && button18Reading == 1023 && button19Reading == 1023 && button20Reading == 1023 && row_1 == 1 && row_2 == 1 && row_3 == 1 && row_5 == 1 && row_6 == 1) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
