/*
 Stepper Motor Control - one revolution
 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 The motor should revolve one revolution in one direction, pauses for 1 second then
 one revolution in the other direction, then pauses for 1 second. It repeats the process indefinitely. 
 */

#include <Stepper.h>

const int stepsPerRevolution = 2010;  // Number of steps in 1 revolution. 
//NOTE: AS you will observe when running the code, this is a random number and not the correct number of steps in 1 revolution – 
//your task is to find a method to figure out how many actual steps in one revolution with good precision! 
//You will be asked to provide that number and your method in the assessment!

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // set the motor speed at 15 rpm (note: you can play with this number but the motor has a permitted range of speed so not all number will work!:
  myStepper.setSpeed(20);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution in one direction:
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
