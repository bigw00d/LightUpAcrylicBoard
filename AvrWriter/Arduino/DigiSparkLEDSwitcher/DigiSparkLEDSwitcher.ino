void setup() {                
  pinMode(0, OUTPUT); //LED(PB0)
  pinMode(1, OUTPUT); //LED(PB1)   
  pinMode(2, OUTPUT); //LED(PB2)   
}

void loop() {
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  delay(3000);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW); 
  digitalWrite(2, LOW); 
  delay(3000);
}

