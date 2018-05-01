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
int led_Circuit = 2;
int servo_Circuit = 3;
int dc_1_Circuit = 4;
int dc_2_Circuit = 5;

void setup() {
  Serial.begin(9600);

  pinMode(button21, INPUT);
  pinMode(button22, INPUT);
  pinMode(button23, INPUT);
  pinMode(button24, INPUT);
  pinMode(button25, INPUT);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

}

void loop() {
  button21Reading = analogRead(button21);
  Serial.print("Button 21 reading = ");
  Serial.println(button21Reading);
  button22Reading = analogRead(button22);
  Serial.print("Button 22 reading = ");
  Serial.println(button22Reading);
  button23Reading = analogRead(button23);
  Serial.print("Button 23 reading = ");
  Serial.println(button23Reading);
  button24Reading = analogRead(button24);
  Serial.print("Button 24 reading = ");
  Serial.println(button24Reading);
  button25Reading = analogRead(button25);
  Serial.print("Button 25 reading = ");
  Serial.println(button25Reading);

  //LED Circuit
  if (button24Reading == 1023 && button25Reading == 1023) {
    digitalWrite(led_Circuit, HIGH);
  }
  else {
    digitalWrite(led_Circuit, LOW);
  }

  //Servo Circuit
  if (button22Reading == 1023) {
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }

  //DC 1 Circuit NA

  //DC 2 Circuit
  if (button22Reading == 1023 && button23Reading == 1023) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
