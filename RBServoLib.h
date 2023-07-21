/*
RBServoLib.h - Simple debugging utilities.
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
*/

#ifndef RB_SERVO_LIB_H__
#define  RB_SERVO_LIB_H__

#include <Servo.h>
#include <Arduino.h>

class RBServoLib
{

  private:

    bool _attached;
    Servo _servo;
    int _servoPin;

  public:

    RBServoLib()
      : _servoPin(9)
      , _attached(false)
    {}

    void attach()
    {
      if (_attached)
        return;

      _attached = true;
      _servo.attach(_servoPin);
    }

    void detach()
    {
      if (! _attached)
        return;

      _attached = false;
      _servo.detach();
    }

    void setPin(int pin) {
      _servoPin = pin;
    }



};


#endif

