

void setup() {
Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop() {
  int vol = analogRead(A0) * (5.0 / 1023.0*100);   // read temperature value of LM35
Serial.print("Tep:");
 Serial.print(vol);
 Serial.println("C");
if (vol<28)                     // low temperature area and LED setup
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
}
else if (vol>=28 && vol<=30)                            
 {
   digitalWrite(13, LOW);

  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
}
else if (vol>30)                               //  low temperature area and LED setup

{
   digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
}
 }
