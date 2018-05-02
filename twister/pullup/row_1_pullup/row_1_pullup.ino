//ARDUINO ROW 1
//LED CIRCUIT CHECKER

//list of Digital Pins for soft buttons
int button1 = A1; 
int button2 = A2;
int button3 = A3;
int button4 = A4;
int button5 = A5;

//keeping track of what state the buttons are in
int button1Reading; 
int button2Reading;
int button3Reading;
int button4Reading;
int button5Reading;

//Challenge pins
int led_Circuit = 4;
int servo_Circuit = 13;
int dc_1_Circuit = 2;
int dc_2_Circuit = 3;

//LED Circuit Checker
//int row_1 = 5;
int row_2 = 6;
int row_3 = 9;
int row_4 = 10;
int row_5 = 11;
int row_6 = 12;


void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);

  pinMode(led_Circuit, OUTPUT);
  pinMode(servo_Circuit, OUTPUT);
  pinMode(dc_1_Circuit, OUTPUT);
  pinMode(dc_2_Circuit, OUTPUT);

  //pinMode(row_1, INPUT);
  pinMode(row_2, INPUT);
  pinMode(row_3, INPUT);
  pinMode(row_4, INPUT);
  pinMode(row_5, INPUT);
  pinMode(row_6, INPUT);

}

void loop() {
  button1Reading = digitalRead(button1);
  button2Reading = digitalRead(button2);
  button3Reading = digitalRead(button3);
  button4Reading = digitalRead(button4);
  button5Reading = digitalRead(button5);
  
  //LED Circuit
  if(button5Reading == 0 && row_2 == 1 && row_3 == 1 && row_4 == 1 && row_5 == 1) {
    digitalWrite(led_Circuit, HIGH);
  }
  else 
   {
    digitalWrite(led_Circuit, LOW);
   }

  //Servo Circuit
  if(button3Reading == 0 && button4Reading == 0 && button5Reading == 0){
    digitalWrite(servo_Circuit, HIGH);
  }
  else {
    digitalWrite(servo_Circuit, LOW);
  }
  
  //DC 1
  if(button5Reading == 1023) {
    digitalWrite(dc_1_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_1_Circuit, LOW);
  }

  //DC 2
  if(button1Reading == 0 && button2Reading == 0 && button3Reading == 0 && button4Reading == 0 && button5Reading == 0) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
