/*
 * Adafruit_i2c_7seg_LED.h
 * 
 * Simple Library for the Adafruit 7-segment displays with a ht16k33 chip.
 * See: https://github.com/rolfn/Adafruit_i2c_7seg_LED
 * 
 * Copyright:  Rolf Niepraschk 
 * License: GPLv3
 *
 */
 
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
    0x00, // <blank>
};

// Constructor
Adafruit_7Seg::Adafruit_7Seg() {
}

void Adafruit_7Seg::setDigit(uint8_t pos, uint8_t d, boolean decimalPoint) {
  if (d < sizeof(ssTable)) {
    Adafruit_7Seg::setSymbol(pos, decimalPoint ? ssTable[d] | 0x80 : ssTable[d]);
  }
} // setDigit

void Adafruit_7Seg::setDigit(uint8_t pos, uint8_t d) {
  Adafruit_7Seg::setDigit(pos, d, false);
} // setDigit

void Adafruit_7Seg::setDigitNow(uint8_t pos, uint8_t d, boolean decimalPoint) {
  setDigit(pos, d, decimalPoint);
  sendLed();
} // setDigitNow

void Adafruit_7Seg::setDigitNow(uint8_t pos, uint8_t d) {
  setDigit(pos, d);
  sendLed();
} // setDigitNow

void Adafruit_7Seg::clearDigit(uint8_t pos) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = 0;
  }
} // clearDigit

void Adafruit_7Seg::clearDigitNow(uint8_t pos) {
  clearDigit(pos);
  sendLed();
} // clearDigit

void Adafruit_7Seg::setSymbol(uint8_t pos, uint8_t d) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = d;
  }
} // setSymbol

void Adafruit_7Seg::setSymbolNow(uint8_t pos, uint8_t d) {
  setSymbol(pos, d);
  sendLed();
} // setSymbolNow

void Adafruit_7Seg::clearAllDigits(void) {
  displayRam[DIGIT_1] = displayRam[DIGIT_2] =
    displayRam[DIGIT_3] = displayRam[DIGIT_4] = 0;
} // clearAllDigits

void Adafruit_7Seg::clearAllDigitsNow(void) {
  clearAllDigits();
  sendLed();
} // clearAllDigitsNow

void Adafruit_7Seg::setPoint(uint8_t d) {
  displayRam[POINTS] |= d;
} // setPoint

void Adafruit_7Seg::setPointNow(uint8_t d) {
  setPoint(d);
  sendLed();
} // setPointNow

void Adafruit_7Seg::togglePoint(uint8_t d) {
  displayRam[POINTS] ^= d;
} // togglePoint

void Adafruit_7Seg::togglePointNow(uint8_t d) {
  togglePoint(d);
  sendLed();
} // togglePointNow

void Adafruit_7Seg::clearPoint(uint8_t d) {
  displayRam[POINTS] &= ~d;
} // clearPoint

void Adafruit_7Seg::clearPointNow(uint8_t d) {
  clearPoint(d);
  sendLed();
} // clearPointNow

void Adafruit_7Seg::clearAllPoints(void) {
  displayRam[POINTS] = 0;
} // clearAllPoints

void Adafruit_7Seg::clearAllPointsNow(void) {
  clearAllPoints();
  sendLed();
} // clearAllPointsNow

uint8_t Adafruit_7Seg::getDigitPosition(uint8_t nb) {
  switch (nb) {
    case 1:
      return DIGIT_1;
      break;
    case 2:
      return DIGIT_2;
      break;
    case 3:
      return DIGIT_3;
      break;
    case 4:
      return DIGIT_4;
      break;
    default:
      return 255;
  }
} // getDigitPosition

