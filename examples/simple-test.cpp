
/*
 * simple-test.cpp
 * 
 * Test of some functions of the Adafruit_i2c_7seg_LED library
 * See: https://github.com/rolfn/Adafruit_i2c_7seg_LED
 * 
 * Copyright:  Rolf Niepraschk 
 * License: GPLv3
 *
 */

#include <Arduino.h>
#include <Adafruit_i2c_7seg_LED.h>

#define DISP1_ADR 0x01 // i2c address: 0x70

Adafruit_7Seg disp1;

void setup() {
  uint8_t pos;

  disp1.begin(DISP1_ADR);
  disp1.setBrightness(10);   // 0..16
  
  for (uint8_t nb = 1; nb <= 4; nb++) {
    pos = disp1.getDigitPosition(nb); // 1 --> DIGIT_1, ...
    for (uint8_t digit = 0; digit < 16; digit++) {
      if (nb < 3) {
        disp1.setDigitNow(pos, digit, true);
      } else {
        disp1.setDigitNow(pos, digit);
        // the same as `disp1.setDigitNow(pos, digit, false)'
      }
      delay(300);
    }
  }
  // only in memory
  disp1.setDigit(DIGIT_1, 2);
  disp1.setDigit(DIGIT_2, 3);
  disp1.setPoint(COLON); 
  disp1.setDigit(DIGIT_3, 5);
  disp1.setDigit(DIGIT_4, 9); 
  delay(1000);
  // send memory content to the LED's
  disp1.sendLed();
  delay(1000);
  disp1.clearAllDigitsNow();
  delay(1000);
  disp1.clearPoint(COLON);
  disp1.sendLed();
}

void loop() {
  // ...
}
