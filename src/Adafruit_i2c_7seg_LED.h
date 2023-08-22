/*
 * Adafruit_i2c_7seg_LED.cpp
 * 
 * Simple Library for the Adafruit 7-segment displays with a ht16k33 chip.
 * See: https://github.com/rolfn/Adafruit_i2c_7seg_LED
 * 
 * Copyright:  Rolf Niepraschk 
 * License: GPLv3
 *
 */
 
#ifndef ADAFRUIT_I2C_7SEG_LED_H
#define ADAFRUIT_I2C_7SEG_LED_H

#include <Arduino.h>
#include <ht16k33.h>
/*
https://github.com/lpaseen/ht16k33
*/

#define ADAFRUIT_I2C_7SEG_LED_MAJOR_VERSION 2
#define ADAFRUIT_I2C_7SEG_LED_MINOR_VERSION 0
#define ADAFRUIT_I2C_7SEG_LED_PATCH_VERSION 0

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

class Adafruit_7Seg : public HT16K33 {
  public:
  Adafruit_7Seg(); // the class itself
  // At position pos setting the digit d (0..15) (only in memory)
  void setDigit(uint8_t pos, uint8_t d);
  // As above with optional decimal point
  void setDigit(uint8_t pos, uint8_t d, boolean decimalPoint);
  // As above, but the LED's are also updated with the memory content
  void setDigitNow(uint8_t pos, uint8_t d);
  void setDigitNow(uint8_t pos, uint8_t d, boolean decimalPoint);
  // At position pos deletion of the digit (only in memory)
  void clearDigit(uint8_t pos);
  // As above, but the LED's are also updated with the memory content
  void clearDigitNow(uint8_t pos);
  // At position pos setting the symbol d (only in memory)
  void setSymbol(uint8_t pos, uint8_t d);
  // As above, but the LED's are also updated with the memory content
  void setSymbolNow(uint8_t pos, uint8_t d);
  // Deletion of all digits (only in memory)
  void clearAllDigits(void);
  // As above, but the LED's are also updated with the memory content
  void clearAllDigitsNow(void);
  // At position pos setting the point d (only in memory)
  void setPoint(uint8_t d);
  // As above, but the LED's are also updated with the memory content
  void setPointNow(uint8_t d);
  // At position pos toggeling point d (only in memory)
  void togglePoint(uint8_t d);
  // As above, but the LED's are also updated with the memory content
  void togglePointNow(uint8_t d);
  // Deletion of the point d (only in memory)
  void clearPoint(uint8_t d);
  // As above, but the LED's are also updated with the memory content
  void clearPointNow(uint8_t d);
  // Deletion of all points (only in memory)
  void clearAllPoints(void);
  // As above, but the LED's are also updated with the memory content
  void clearAllPointsNow(void);
  // Returns the internal position of a specific digit number
  uint8_t getDigitPosition(uint8_t nb);
};

#endif
