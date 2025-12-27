/*
  SOS Morse Code

  Blinks the LED for 3 short blinks, 3 long blinks, then 3 short blinks again

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 14 September 2025
  By Ishmael Kwayisi
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 3; i++){
    digitalWrite(12, HIGH);  // turn the Red LED on (HIGH is the voltage level)
    digitalWrite(10, HIGH);  // keep the Yellow LED off 
    digitalWrite(8, HIGH);  // keep the Green LED off 
    delay(500);
    digitalWrite(12, LOW);  // turn the Red LED on (HIGH is the voltage level)
    digitalWrite(10, LOW);  // keep the Yellow LED off 
    digitalWrite(8, LOW);  // keep the Green LED off  
    delay(500);                     // wait for a second
  }
  for (int i = 0; i < 3; i++){
    digitalWrite(12, HIGH);  // turn the Red LED on (HIGH is the voltage level)
    digitalWrite(10, HIGH);  // keep the Yellow LED off 
    digitalWrite(8, HIGH);  // keep the Green LED off 
    delay(1000);
    digitalWrite(12, LOW);  // turn the Red LED on (HIGH is the voltage level)
    digitalWrite(10, LOW);  // keep the Yellow LED off 
    digitalWrite(8, LOW);  // keep the Green LED off  
    delay(1000);                     // wait for a second
  }
  for (int i = 0; i < 3; i++){
    digitalWrite(12, HIGH);  // turn the Red LED on (HIGH is the voltage level)
    digitalWrite(10, HIGH);  // keep the Yellow LED off 
    digitalWrite(8, HIGH);  // keep the Green LED off 
    delay(500);
    digitalWrite(12, LOW);  // turn the Red LED on (HIGH is the voltage level)
    digitalWrite(10, LOW);  // keep the Yellow LED off 
    digitalWrite(8, LOW);  // keep the Green LED off  
    delay(500);                     // wait for a second
  }
}