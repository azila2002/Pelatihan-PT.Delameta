int R =PA0;
int Y =PA1;
int G =PA2;

int button1 =PA5;
int button2 =PA6;
int button3 =PA7;

void setup() {
  pinMode(PA0,OUTPUT);
  pinMode(PA1,OUTPUT);
  pinMode(PA2,OUTPUT);
  pinMode(PA5,OUTPUT);
  pinMode(PA6,OUTPUT);
  pinMode(PA7,OUTPUT);

}

void loop() {
  int readbutton1=digitalRead(button1);
  int readbutton2=digitalRead(button2);
  int readbutton3=digitalRead(button3);
  
  if (readbutton1==1){
  digitalWrite(PA0,HIGH);
  }else{
    digitalWrite(PA0,LOW);
  }
    if (readbutton2==1){
  digitalWrite(PA1,HIGH);
  }else{
    digitalWrite(PA1,LOW);
  }
 if (readbutton3==1){
  digitalWrite(PA2,HIGH);
  }else{
    digitalWrite(PA2,LOW);
  }
 
}
