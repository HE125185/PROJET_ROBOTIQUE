// include the library code:
#include<Arduino.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int Vy = A1;
const int Vx = A2;
const int bp = 2;

void setup() {
pinMode(bp,INPUT_PULLUP);
lcd.begin(16,2);
  
Serial.begin(9600);
}

void loop() {
float valeur_x = analogRead(Vx)
float valeur_y = analogRead(Vy)
int valeur_bp = !digitalRead(bp);  
float a = 0.004882813;
}
lcd.setCursor(0,1);
lcd.print("X-axis: ");
lcd.print(String(valeur_x*a));

lcd.setCursor(0,1);
lcd.print("Y-axis: ");
lcd.print(String(valeur_y*a));

 