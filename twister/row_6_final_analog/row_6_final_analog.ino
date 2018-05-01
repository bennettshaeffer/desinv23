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
int led_Circuit = 2;
int servo_Circuit = 3;
int dc_1_Circuit = 4;
int dc_2_Circuit = 5;

void setup() {
  Serial.begin(9600);

  pinMode(button26, INPUT);
  pinMode(button27, INPUT);
  pinMode(button28, INPUT);
  pinMode(button29, INPUT);
  pinMode(button30, INPUT);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

}

void loop() {
  button26Reading = analogRead(button26);
  Serial.print("Button 21 reading = ");
  Serial.println(button26Reading);
  button27Reading = analogRead(button27);
  Serial.print("Button 22 reading = ");
  Serial.println(button27Reading);
  button28Reading = analogRead(button28);
  Serial.print("Button 23 reading = ");
  Serial.println(button28Reading);
  button29Reading = analogRead(button29);
  Serial.print("Button 24 reading = ");
  Serial.println(button29Reading);
  button30Reading = analogRead(button30);
  Serial.print("Button 25 reading = ");
  Serial.println(button30Reading);

  //LED Circuit NA

  //Servo Circuit
  if (button27Reading == 1023 && button28Reading == 1023) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1 Circuit
  if (button27Reading == 1023 && button28Reading == 1023) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }


  //DC 2 Circuit
  if (button27Reading == 1023 && button28Reading == 1023) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
