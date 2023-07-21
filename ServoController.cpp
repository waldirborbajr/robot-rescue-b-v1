/*
ServoController.cpp - Interrupt driven Servo library for Arduino using 16 bit timers- Version 1
Copyright (C) 2015 Waldir Borba Junior <wborbajr at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Created by Waldir Borba Junior, June 14, 2015.
*/

/*
https://github.com/netlabtoolkit/VarSpeedServo
*/

#include "Arduino.h"
#include "ServoController.h"

ServoController::ServoController(int rotateServoPin, int elevateServoPin)
{
  azimuthAngle = 0;
  elevationAngle = 0;
  /* remove below */
  //  elevateServo.attach(elevateServoPin);
  //  rotateServo.attach(rotateServoPin);
}

uint8_t ServoController::attachPins(int rotateServoPin, int elevateServoPin)
{
  azimuthAngle = 0;
  elevationAngle = 0;
  
  elevateServo.attach(elevateServoPin);
  rotateServo.attach(rotateServoPin);
}

void ServoController::rotate(int degrees)
{
  //TO DO
  rotateServo.write(degrees);
}


void ServoController::elevate(int degrees)
{
  //TO DO
  elevateServo.write(degrees);
}
