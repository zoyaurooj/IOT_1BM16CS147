const int ledGreen = 2;
const int button =3;
int state=0;

void setup() {
  // put your setup code here, to run once:
 

  pinMode(ledGreen, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(ledGreen, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  state= digitalRead(button);
  if(state==1){
    digitalWrite(ledGreen, HIGH);
  }
  else{
    digitalWrite(ledGreen, LOW);
  }

}
