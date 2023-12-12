int button1 = 2;
int button2 = 4;
int button3 = 6;
int button4 = 8;

int input1 = 5;
int input2 = 7;
int input3 = 3;
int input4 = 1;

int ping = 13;

int enableUp = 9;
int enableDown = 10;

int motoAtack = 12;

float distance;

void setup()
{
  //Serial.begin(9600);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);


  
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

  pinMode(ping, OUTPUT);
  
  pinMode(enableUp,OUTPUT);
  digitalWrite(enableUp,HIGH);
  pinMode(enableDown,OUTPUT);
  digitalWrite(enableDown,HIGH); 
}

void loop()
{
  if(digitalRead(button1) == HIGH) {
  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  digitalWrite(input4,HIGH);
  digitalWrite(input3,LOW);
  }
  else if (digitalRead(button2) == HIGH){
  digitalWrite(input1,LOW);
  digitalWrite(input2,HIGH);
  digitalWrite(input4,LOW);
  digitalWrite(input3,HIGH);
  }
  else if (digitalRead(button3) == HIGH) {
  digitalWrite(input1,HIGH);
  digitalWrite(input2,LOW);
  digitalWrite(input4,LOW);
  digitalWrite(input3,LOW);
  }
  else if (digitalRead(button4) == HIGH){
  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(input4,LOW);
  digitalWrite(input3,HIGH);
  }
  else {
  digitalWrite(input1,LOW);
  digitalWrite(input2,LOW);
  digitalWrite(input4,LOW);
  digitalWrite(input3,LOW);
  }
  
  digitalWrite(ping, HIGH);
  delay(00010);
  digitalWrite(ping, LOW);
  
  pinMode(ping,INPUT);
  distance = pulseIn(ping,HIGH);
  distance = distance/2;
  distance = distance*0.034029;
  pinMode(ping,OUTPUT);
  
  
  Serial.println(distance);
  
  if (distance <= 141.90){
    pinMode(motoAtack,OUTPUT);
    digitalWrite(motoAtack,HIGH);
  }
  else {
    digitalWrite(motoAtack,LOW);
  }
    
  delay(1000);
  
}