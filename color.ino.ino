const int s0 = 5;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;

int redLed = 2;
int greenLed = 3;
int blueLed = 4;

int r = 0;
int g = 0;
int b = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  digitalWrite(s1, HIGH);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  color();
  Serial.print("R intensity: ");
  Serial.print(r, DEC);
  Serial.print("G intensity: ");
  Serial.print(g, DEC);
  Serial.print("B intensity: ");
  Serial.print(b, DEC);

  if(r < b && r < g)
  {
    Serial.println("- (Red Color)");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
  }
  else if(b < r && b < g)
  {
    Serial.println("- (Blue Color)");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
  }
  else if(g < r && b > g)
  {
    Serial.println("- (Green Color)");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
  }
  else
  {
    Serial.println();
  }
  delay(100);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, LOW);
}

void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  r = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  b = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  g = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
