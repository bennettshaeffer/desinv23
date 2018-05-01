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
int led_Circuit = 2;
int servo_Circuit = 3;
int dc_1_Circuit = 4;
int dc_2_Circuit = 5;

//LED Circuit Checker
int row_1 = 6;
//int row_2 = 7;
int row_3 = 8;
int row_4 = 9;
int row_5 = 10;
int row_6 = 11;

void setup() {
  Serial.begin(9600);

  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT);
  pinMode(button10, INPUT);

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
  button6Reading = analogRead(button6);
  Serial.print("Button 5 reading = ");
  Serial.println(button6Reading);
  button7Reading = analogRead(button7);
  Serial.println(button7Reading);
  button8Reading = analogRead(button8);
  Serial.println(button8Reading);
  button9Reading = analogRead(button9);
  Serial.println(button9Reading);
  button10Reading = analogRead(button10);

  //LED Circuit
  if (button8Reading == 1023) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button7Reading == 1023 && button9Reading == 1023 && row_1 == 1 && row_3 == 1 && row_4 == 1 && row_5 == 1 && row_6 == 1) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1
  if (button7Reading == 1023) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if (button7Reading == 1023) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
