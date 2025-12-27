//Import library for LCD
#include <LiquidCrystal.h>
 
#define RED_LED 7
#define YELLOW_LED 6
#define GREEN_LED 5
 
//Digital pin info for the Ultrasonic Sensor
const int trig_pin = 14;
const int echo_pin = 15;
 
//Variables measuring time and distance for Ultrasonic Sensor
float timing = 0.0;
float distance = 0.0;
float inches = 0.0;
float radius = 14.25;   // cm
float height = 22.32;  // cm
 
//Slope equation constants (example values, adjust as needed)
float m = -1.0;   // slope
float b = height; // intercept
 
//The constant (unchangeable) values to digital pin values
const int rs = 31, en = 33, d4 = 29, d5 = 27, d6 = 25, d7 = 23;
 
//Constant value to store the digital pin of the buzzer
const int buzzer = 9;
 
//Initializes the LCD object using the constant variables
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
  digitalWrite(trig_pin, LOW);
  digitalWrite(buzzer, LOW);
 
  lcd.begin(16, 2);
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(trig_pin, LOW);
  delay(2);
 
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
 
  timing = pulseIn(echo_pin, HIGH);
  distance = (timing * 0.034) / 2;   // cm
  inches = distance / 2.54;
 
  // --- NEW CALCULATIONS ---
  // Apply slope equation Y = mx + b
  float slopeValue = m * distance + b;
 
  // Water height = bucket height - measured distance
  float waterHeight = height - distance;
  if (waterHeight < 0) waterHeight = 0;
 
  // Volume of water in bucket (cylinder)
  float volume = 3.1416 * radius * radius * waterHeight;
 
  // Print results
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | ");
  Serial.print(inches);
  Serial.print(" in | Slope Y: ");
  Serial.print(slopeValue);
  Serial.print(" | Volume: ");
  Serial.print(volume);
  Serial.println(" cm^3");
  Serial.print("Water Height: ");
  Serial.print(waterHeight);
  Serial.println(" cm");
 
  // --- EXISTING LED + BUZZER LOGIC ---
  if (distance >= 12.5) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    tone(buzzer, 500, 1000);
    lcd.clear();
    lcd.print("Low");
  }
  else if (distance >= 5) {
    lcd.clear();
    lcd.print("Medium");
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    noTone(buzzer);
  }
  else {
    lcd.clear();
    lcd.print("High");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    noTone(buzzer);
  }
 
  delay(5000);
}
 