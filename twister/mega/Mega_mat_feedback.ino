/* Circuit Twister (revised for Arduino Mega)
    By: Bennett Shaeffer, Cade Cahalan, Chelsey Campillo, Ethan Frazin, and Jefrey Nacar
*/

//Button init
int button1 = 2;
int button1Reading;
int button2 = 3;
int button2Reading;
int button3 = 4;
int button3Reading;
int button4 = 5;
int button4Reading;
int button5 = 6;
int button5Reading;
int button7 = 7;
int button7Reading;
int button8 = 8;
int button8Reading;
int button9 = 9;
int button9Reading;
int button10 = 10;
int button10Reading;
int button12 = 11;
int button12Reading;
int button13 = 12;
int button13Reading;
int button14 = 13;
int button14Reading;
int button15 = 14;
int button15Reading;
int button16 = 15;
int button16Reading;
int button17 = 16;
int button17Reading;
int button18 = 17;
int button18Reading;
int button19 = 18;
int button19Reading;
int button20 = 19;
int button20Reading;
int button22 = 20;
int button22Reading;
int button23 = 21;
int button23Reading;
int button24 = 22;
int button24Reading;
int button25 = 23;
int button25Reading;
int button27 = 24;
int button27Reading;
int button28 = 25;
int button28Reading;

//LED init
int ledPin = 26;

//circuit checker init
int led_circuit = 0;
int servo_circuit = 0;
int dc_1_circuit = 0;
int dc_2_circuit = 0;

//hold
unsigned long time;
int hold = 0;
int tBegin = 0;
int tEnd = 0;
int tTime = 3000; //wait 3 seconds

void setup() {
  //more button init
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP);
  pinMode(button13, INPUT_PULLUP);
  pinMode(button14, INPUT_PULLUP);
  pinMode(button15, INPUT_PULLUP);
  pinMode(button16, INPUT_PULLUP);
  pinMode(button17, INPUT_PULLUP);
  pinMode(button18, INPUT_PULLUP);
  pinMode(button19, INPUT_PULLUP);
  pinMode(button20, INPUT_PULLUP);
  pinMode(button22, INPUT_PULLUP);
  pinMode(button23, INPUT_PULLUP);
  pinMode(button24, INPUT_PULLUP);
  pinMode(button25, INPUT_PULLUP);
  pinMode(button27, INPUT_PULLUP);
  pinMode(button28, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);


}

void loop() {
  time = millis();
  button1Reading = digitalRead(button1);
  button2Reading = digitalRead(button2);
  button3Reading = digitalRead(button3);
  button4Reading = digitalRead(button4);
  button5Reading = digitalRead(button5);
  button7Reading = digitalRead(button7);
  button8Reading = digitalRead(button8);
  button9Reading = digitalRead(button9);
  button10Reading = digitalRead(button10);
  button12Reading = digitalRead(button12);
  button13Reading = digitalRead(button13);
  button14Reading = digitalRead(button14);
  button15Reading = digitalRead(button15);
  button16Reading = digitalRead(button16);
  button17Reading = digitalRead(button17);
  button18Reading = digitalRead(button18);
  button19Reading = digitalRead(button19);
  button20Reading = digitalRead(button20);
  button22Reading = digitalRead(button22);
  button23Reading = digitalRead(button23);
  button24Reading = digitalRead(button24);
  button27Reading = digitalRead(button27);
  button28Reading = digitalRead(button28);

  //LED Circuit Checker
  if (button5Reading == 0 && button8Reading == 0 && button13Reading == 0 && button19Reading == 0 && button24Reading == 0 && button25Reading == 0)
  {
    if (hold == 0)    //Condition for timer to start
    {
      tBegin = time;
      tEnd = tBegin + tTime;    //Offsets the end value by three seconds (a dynamic timer)
      hold = 1; 
    }
    if (time >= tEnd)
    {
      led_circuit = 1;    //if circuit is held for 3 seconds, set the circuit as complete
    }
  }
  else
  {
    led_circuit = 0;
  }

  //Servo Circuit Checker
  if (button3Reading == 0 && button4Reading == 0 && button5Reading == 0 && button7Reading == 0 && button9Reading == 0 && button14Reading == 0  && button19Reading == 0 && button22Reading == 0 && button27Reading == 0 && button28 == 0)
  {
    if (hold == 0)
    {
      tBegin = time;
      tEnd = tBegin + tTime;
      hold = 1;
    }
    if (time >= tEnd)
    {
      servo_circuit = 1;
    }
  }
  else
  {
    servo_circuit = 0;
  }

  //DC 1 Circuit Checker
  if (button5Reading == 0 && button7Reading == 0 && button15Reading == 0 && button20Reading == 0 && button27Reading == 0 && button28Reading == 0)
  {
    if (hold == 0)
    {
      tBegin = time;
      tEnd = tBegin + tTime;
      hold = 1;
    }
    if (time >= tEnd)
    {
      dc_1_circuit = 1;
    }
  }
  else
  {
    dc_1_circuit = 0;
  }

  //DC 2 Circuit Checker
  if (button2Reading == 0 && button3Reading == 0 && button4Reading == 0 && button5Reading == 0 && button7Reading == 0 && button12Reading == 0 && button15Reading == 0 && button16Reading == 0 && button17Reading == 0 && button18Reading == 0 && button19Reading == 0 && button20Reading == 0 && button22Reading == 0 && button23Reading == 0 && button27Reading == 0 && button28Reading)
  {
    if (hold == 0)
    {
      tBegin = time;
      tEnd = tBegin + tTime;
      hold = 1;
    }
    if (time >= tEnd)
    {
      dc_2_circuit = 1;
    }
  }
  else
  {
    dc_2_circuit = 0;
  }

  //Feedback part
  if(led_circuit == 1 || servo_circuit == 1 || dc_1_circuit == 1 || dc_2_circuit == 1)
  {
    digitalWrite(ledPin, HIGH);   //When any of the circuits is completed (and has been held for three seconds) the visual feedback is turned on
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

