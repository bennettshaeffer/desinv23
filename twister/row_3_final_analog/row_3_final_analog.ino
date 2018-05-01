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
int led_Circuit = 2;
int servo_Circuit = 3;
int dc_1_Circuit = 4;
int dc_2_Circuit = 5;

//LED Circuit Checker
int row_1 = 6;
int row_2 = 7;
//int row_3 = 8;
int row_4 = 9;
int row_5 = 10;
int row_6 = 11;

void setup() {
  Serial.begin(9600);

  pinMode(button11, INPUT);
  pinMode(button12, INPUT);
  pinMode(button13, INPUT);
  pinMode(button14, INPUT);
  pinMode(button15, INPUT);

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
  button11Reading = analogRead(button11);
  Serial.print("Button 5 reading = ");
  Serial.println(button11Reading);
  button12Reading = analogRead(button12);
  Serial.println(button12Reading);
  button13Reading = analogRead(button13);
  Serial.println(button13Reading);
  button14Reading = analogRead(button14);
  Serial.println(button14Reading);
  button15Reading = analogRead(button15);

  //LED Circuit
  if (button13Reading == 1023) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button14Reading == 1023) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1
  if (button15Reading == 1023 && row_1 == 1 && row_2 == 1 && row_4 == 1 && row_5 == 1 && row_6 == 1) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if (button12Reading == 1023 && button15Reading == 1023) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
