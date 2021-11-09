int R=2;
int Y=3;
int G=4;


void setup() {
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R,HIGH);
  delay(5000);
  digitalWrite(R,LOW);
  delay(1000);
  digitalWrite(Y,HIGH);
  delay(500);
  digitalWrite(Y,LOW);
  delay(1000);
  digitalWrite(G,HIGH);
  delay(3000);
  digitalWrite(G,LOW);
  delay(1000);
}
