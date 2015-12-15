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

#include <Adafruit_i2c_7seg_LED.h>

static const uint8_t ssTable[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F, // 9
    0x77, // A
    0x7C, // b
    0x39, // C
    0x5E, // d
    0x79, // E
    0x71, // F
    0x00, //<blank>
};

// Constructor
Adafruit_LED::Adafruit_LED() {
}

void Adafruit_LED::setDigit(uint8_t pos, uint8_t d, boolean decimalPoint) {
  if (d < sizeof(ssTable)) {
    Adafruit_LED::setSymbol(pos, decimalPoint ? ssTable[d] | 0x80 : ssTable[d]);
  }
} // setDigit

void Adafruit_LED::setDigit(uint8_t pos, uint8_t d) {
  Adafruit_LED::setDigit(pos, d, false);
} // setDigit

void Adafruit_LED::setSymbol(uint8_t pos, uint8_t d) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = d;
    sendLed();
  }
} // setSymbol

void Adafruit_LED::clearPosition(uint8_t pos) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = 0;
    sendLed();
  }
} // clearPosition

void Adafruit_LED::clearAllDigits(void) {
  displayRam[DIGIT_1] = displayRam[DIGIT_2] =
    displayRam[DIGIT_3] = displayRam[DIGIT_4] = 0;
  sendLed();
} // clearAllDigits

void Adafruit_LED::setPoint(uint8_t d) {
  displayRam[POINTS] |= d;
  sendLed();
} // setPoint

void Adafruit_LED::togglePoint(uint8_t d) {
  displayRam[POINTS] ^= d;
  sendLed();
} // togglePoint

void Adafruit_LED::clearPoint(uint8_t d) {
  displayRam[POINTS] &= ~d;
  sendLed();
} // clearPoint

void Adafruit_LED::clearAllPoints(void) {
  displayRam[POINTS] = 0;
  sendLed();
}
