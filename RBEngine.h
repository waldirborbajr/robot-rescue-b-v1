/*
RBEngineLib.h - Simple debugging utilities.
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

#include <Arduino.h>

class RBEngine {
  private:

  public:

    // Motor A
    const byte ENA  =  9; // Digital  9
    const byte INA1 =  2; // Digital  2
    const byte INA2 =  3; // Digital  3

    // Motor B
    const byte ENB  = 10; // Digital 10
    const byte INB3 =  4; // Digital  4
    const byte INB4 =  5; // Digital  5

    const byte SPEED = 90;

    void motorB_Slow_Forward() {
      digitalWrite(INB3, LOW); // Forward motion
      digitalWrite(INB4, HIGH);
      for (byte b = SPEED; b < 255; b++) {
        analogWrite(ENB, b);
        delay(1000);
      }
    }

    void motorB_Forward() {
      analogWrite(ENB, 0);

      digitalWrite(INB3, LOW); // Forward motion
      digitalWrite(INB4, HIGH);
      for (byte m_speed = SPEED; m_speed < 255; m_speed++)
      {
        analogWrite(ENB, m_speed);
        delay(1000);
      }
    }

    void motorB_Reverse() {
      analogWrite(ENB, 0);

      digitalWrite(INB3, HIGH); // Reverse motion
      digitalWrite(INB4, LOW);
      for (byte m_speed = SPEED; m_speed < 255; m_speed++)
      {
        analogWrite(ENB, m_speed);
        delay(1000);
      }
    }
};
