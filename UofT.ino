float target = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int vol = analogRead(A0) * (5.0 / 1023.0*100);
  Serial.print("Temp: ");
  Serial.print(vol);
  Serial.println("C");

}
