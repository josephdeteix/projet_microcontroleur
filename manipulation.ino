int motor1pin1 = 2;
int motor1pin2 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  pinMode(9, OUTPUT);
}

void loop() {
  delay(5000);
  // put your main code here, to run repeatedly:
  analogWrite(9,60);

  digitalWrite(motor1pin1, HIGH); //la on leve
  digitalWrite(motor1pin2, LOW);
}