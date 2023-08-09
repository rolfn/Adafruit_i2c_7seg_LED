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

void Adafruit_7Seg::setSymbol(uint8_t pos, uint8_t d) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = d;
    sendLed();
  }
} // setSymbol

void Adafruit_7Seg::clearPosition(uint8_t pos) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = 0;
    sendLed();
  }
} // clearPosition

void Adafruit_7Seg::clearAllDigits(void) {
  displayRam[DIGIT_1] = displayRam[DIGIT_2] =
    displayRam[DIGIT_3] = displayRam[DIGIT_4] = 0;
  sendLed();
} // clearAllDigits

void Adafruit_7Seg::setPoint(uint8_t d) {
  displayRam[POINTS] |= d;
  sendLed();
} // setPoint

void Adafruit_7Seg::togglePoint(uint8_t d) {
  displayRam[POINTS] ^= d;
  sendLed();
} // togglePoint

void Adafruit_7Seg::clearPoint(uint8_t d) {
  displayRam[POINTS] &= ~d;
  sendLed();
} // clearPoint

void Adafruit_7Seg::clearAllPoints(void) {
  displayRam[POINTS] = 0;
  sendLed();
}
