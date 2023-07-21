/*
ServoController.h - Interrupt driven Servo library for Arduino using 16 bit timers- Version 1
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

#ifndef ServoController_h
#define ServoController_h

#include "Arduino.h"
#include <Servo.h>

class ServoController
{
  public:
    ServoController(int rotateServoPin, int elevateServoPin);
    uint8_t attachPins(int rotateServoPin, int elevateServoPin);
    void rotate(int degrees);
    void elevate(int degrees);

  private:
    Servo rotateServo;
    Servo elevateServo;
    byte elevationAngle;
    byte azimuthAngle;

};

#endif
