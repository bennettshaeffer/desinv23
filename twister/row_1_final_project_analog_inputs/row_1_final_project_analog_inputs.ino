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
int led_Circuit = 2;
int servo_Circuit = 3;
int dc_1_Circuit = 4;
int dc_2_Circuit = 5;

//LED Circuit Checker
//int row_1 = 6;
int row_2 = 7;
int row_3 = 8;
int row_4 = 9;
int row_5 = 10;
int row_6 = 11;

void setup() {
  Serial.begin(9600);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);

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
  button1Reading = analogRead(button1);
  Serial.print("Button 1 reading = ");
  Serial.println(button1Reading);
  button2Reading = analogRead(button2);
  Serial.println(button2Reading);
  button3Reading = analogRead(button3);
  Serial.println(button3Reading);
  button4Reading = analogRead(button4);
  Serial.println(button4Reading);
  button5Reading = analogRead(button5);
  
  //LED Circuit
  if(button5Reading == 1023 && row_2 == 1 && row_3 == 1 && row_4 == 1 && row_5 == 1) {
    digitalWrite(led_Circuit, HIGH);
  }
  else 
   {
    digitalWrite(led_Circuit, LOW);
   }

  //Servo Circuit
  if(button3Reading == 1023 && button4Reading == 1023 && button5Reading == 1023){
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
  if(button1Reading == 1023 && button2Reading == 1023 && button3Reading == 1023 && button4Reading == 1023 && button5Reading == 1023) {
    digitalWrite(dc_2_Circuit, HIGH);
  }
  else {
    digitalWrite(dc_2_Circuit, LOW);
  }

}
