/*
  Rescue B v1
  -----------

  Author : Waldir Borba Junior
  Date   : Jun-08-2015
  Version: 1.0.0


#include <ServoController.h>
#include <Servo.h>

Servo servo0;

void setup()
{
servo0.attach(2);
}

void loop() // this function runs repeatedly after setup() finishes
{
  servo0.write(90);
  delay(2000);
  servo0.write(135);
  delay(2000);
  servo0.write(45);
  delay(2000);
}

*/

#include <Servo.h>
#include "RBServoLib.h"
#include "RBEngine.h"

#define DEBUG

// Distance Sensor
unsigned long distanceIR; // Infrared Distance Sensor
unsigned long distanceUS; // Ultrasound Distance Sensor

long previousMillisIR = 0; // will store last time Infrared was updated
long previousMillisUS = 0; // will store last time Ultrasound was updated

long intervalIR = 1000; // interval at which to read Infrared distance (milliseconds)
long intervalUS = 1500; // interval at which to read Ultrasound distance (milliseconds)

// RBServoLib
RBServoLib rbServo;
byte rbServoPin = 5;

void readIR_Distance() {
#ifdef DEBUG
  Serial.println(F("Reading Infrared Distance"));
#endif

  distanceIR = 0;
}

void readUS_Distance() {
#ifdef DEBUG
  Serial.println(F("Reading Ultrasound Distance"));
#endif

  distanceUS = 0;
}

void readFastResponse() {
  readIR_Distance();
}

void readSlowResponse() {
  readUS_Distance();
}

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
  if (Serial.available() > 0)
    Serial.println(F("Starting Rescue Bot v1.0"));
  Serial.flush();
#endif

  pinMode(rbServoPin, OUTPUT);
  rbServo.setPin(rbServoPin);
  rbServo.attach();

}

void loop() {

  // check to see if it's time to mesure Infrared distance
  unsigned long currentMillisIR  = millis();
  unsigned long currentMillisUS  = millis();

#ifdef DEBUG
  Serial.print(F("currentMillisIR "));
  Serial.println(currentMillisIR);
  Serial.print(F("currentMillisUS "));
  Serial.println(currentMillisUS);
#endif

  if ((currentMillisIR - previousMillisIR) > intervalIR ) {
    // save the last time Infrared was read
    previousMillisIR = currentMillisIR;

    readFastResponse();
  }

  if ((currentMillisUS - previousMillisUS) > intervalUS ) {
    // save the last time Ultrasound was read
    previousMillisUS = currentMillisUS;

    readSlowResponse();
  }

}

