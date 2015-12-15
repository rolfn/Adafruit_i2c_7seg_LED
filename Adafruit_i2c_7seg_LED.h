//
//  https://github.com/rolfn/Adafruit_i2c_7seg_LED
//
//  Copyright 2015 Rolf Niepraschk
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program. If not, see http://www.gnu.org/licenses/

#ifndef ADAFRUIT_I2C_7SEG_LED_H
#define ADAFRUIT_I2C_7SEG_LED_H

#include <ht16k33.h> // see: https://github.com/lpaseen/ht16k33

#define DIGIT_1 0
#define DIGIT_2 2
#define DIGIT_3 6
#define DIGIT_4 8
#define POINTS  4

#define COLON 0x02             // 1.2": middle colon      0.56": middle colon
#define POINT_UPPER_LEFT 0x04  // 1.2": upper left point
#define POINT_LOWER_LEFT 0x08  // 1.2": lower left point
#define POINT_UPPER_RIGHT 0x10 // 1.2": upper right point
#define MINUS 0x40
#define BLANK 0x10

class Adafruit_LED : public HT16K33 {
 public:
  Adafruit_LED(); // the class itself
  void setDigit(uint8_t pos, uint8_t d);
  void setDigit(uint8_t pos, uint8_t d, boolean decimalPoint);
  void setSymbol(uint8_t pos, uint8_t d);
  void clearPosition(uint8_t pos);
  void clearAllDigits(void);
  void setPoint(uint8_t d);
  void togglePoint(uint8_t d);
  void clearPoint(uint8_t d);
  void clearAllPoints(void);
 private:
};

#endif
