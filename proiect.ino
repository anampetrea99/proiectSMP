/*
 * Petrea Ana-Maria, 333AA
 * PROIECT SMP 2020
 * Sistem de alimentare cu apa proaspata pentru pasari
 */
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
const int pumpPin = 11;
long duration;
int distance;
byte customChar[] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000
};

void setup() {
  lcd.begin(16,2); 
  //pinMode(pumpPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.createChar(0, customChar);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  lcd.setCursor(0,0); // Seteaza locatia initiala a cursorului pe ecranul LCD
  lcd.print("Water level: "); // Afiseaza textul dintre ghilimele pe ecranul LCD
  
  if(distance >= 5){
    lcd.setCursor(0,1);
    lcd.write(byte(0));
    lcd.setCursor(2,1);
    lcd.write(byte(0));
    //Pornesc pompa pentru ca nivelul de apa e prea scazut:
    //digitalWrite(pumpPin, HIGH);
    //delay(800);
    //digitalWrite(pumpPin, LOW);
  } else if(distance >= 4 and distance < 5){
    lcd.setCursor(0,1);
    lcd.write(byte(0));
    lcd.setCursor(2,1);
    lcd.write(byte(0));
    lcd.setCursor(4,1);
    lcd.write(byte(0));
    delay(10);
  } else if(distance >= 3 and distance < 4){
    lcd.setCursor(0,1);
    lcd.write(byte(0));
    lcd.setCursor(2,1);
    lcd.write(byte(0));
    lcd.setCursor(4,1);
    lcd.write(byte(0)); 
    lcd.setCursor(6,1);
    lcd.write(byte(0));
    delay(10);
  } else if(distance >= 2 and distance < 3){
    lcd.setCursor(0,1);
    lcd.write(byte(0));
    lcd.setCursor(2,1);
    lcd.write(byte(0));
    lcd.setCursor(4,1);
    lcd.write(byte(0)); 
    lcd.setCursor(6,1);
    lcd.write(byte(0));
    lcd.setCursor(8,1);
    lcd.write(byte(0));
    delay(10);
  }
  delay(10);
}
