
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte sensorPin = 6;
byte indicator = 10;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  lcd.init();
  lcd.backlight();
  pinMode(sensorPin, INPUT);
  pinMode(indicator, OUTPUT);
  
  
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
  delay(2000);
}
else if (vol>=28 && vol<=40)                            
 {
   digitalWrite(13, LOW);

  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  delay(2000);
}
else if (vol>40)                               //  low temperature area and LED setup

{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(2000);
}


byte state = digitalRead(sensorPin);
digitalWrite(indicator, state);
if (state==1) {
  lcd.setCursor(2, 0);
  lcd.print("Heat detected");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(vol);
  lcd.print("C");
  delay(4500);
  lcd.clear();
  delay(1000);
}

else if (state==0) {
  lcd.setCursor(1,0);
  lcd.print("No Heat");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(vol);
  lcd.print("C");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Turning fan on ");
  digitalWrite(3, HIGH);
 
  
  delay(2000);
}
digitalWrite(3, LOW);
 }
