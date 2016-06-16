/*
 *  Author: Abhishek Pratapa
 *  Date: Thursday, June 16, 2016
 *  Title: Actuator Code (Version 1.0)
 */

//initiate led's which are going to be standins for 5v relays
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;

//initiate buttons which we will use for the sequencing
int button1 = 3;
int button2 = 4;
int button3 = 5;
int button4 = 6;
int button5 = 7;

//initiate the value of the button pressed where zero is the neutral
int value = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital LED pins as outputs.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  // initialize the digital button pins as inputs.
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //read the buttons in this sequence being pulled down constitutes an on action
  if(digitalRead(button1) == LOW){
  	value = 1;
  }else if(digitalRead(button2) == LOW){
  	value = 2;
  }else if(digitalRead(button3) == LOW){
  	value = 3;
  }else if(digitalRead(button4) == LOW){
  	value = 4;
  }else if(digitalRead(button5) == LOW){
  	value = 5;
  }
  
  //run the automated sequence using a state machine response
  if(value == 1){
    //pattern 1
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(1000);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(2000);
  }else if(value == 2){
    //pattern 2
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(1000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(2000);
  }else if(value == 3){
    //pattern 3
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(1000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(2000);
  }else if(value == 4){
    //pattern 4
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(1000);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    delay(500);
  }else if(value == 5){
    //pattern 5
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    delay(1000);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    delay(1000);
  }
  
  //reset all the values and actuation sequences
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  value = 0;
  
  //add delay for processor sake
  delay(30);
}
