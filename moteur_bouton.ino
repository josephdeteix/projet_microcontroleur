int motor1pin1 = 2;
int motor1pin2 = 3;

int bouton_haut = 4; 
int etatbouton_haut = 0;

int bouton_bas = 7;
int etatbouton_bas = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode (bouton_haut, INPUT_PULLUP);
  pinMode (bouton_bas, INPUT_PULLUP);
  
  Serial.begin(9600); 
}

void loop() {
  analogWrite(9, 230);
  // put your main code here, to run repeatedly:
etatbouton_haut = digitalRead(bouton_haut);
etatbouton_bas = digitalRead(bouton_bas);

digitalWrite(motor1pin1, LOW);
digitalWrite(motor1pin2, LOW);

if (etatbouton_haut == LOW){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
}

if (etatbouton_bas == LOW){
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
}
}