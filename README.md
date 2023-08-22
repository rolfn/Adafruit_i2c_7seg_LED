# Adafruit_i2c_7seg_LED

An Arduino library for Adafruit's 7-segment displays (i2c) like
[this](https://www.adafruit.com/products/879) or
[that](https://www.adafruit.com/products/1269).

The library is much simpler
than the library provided by
[Adafruit](https://github.com/adafruit/Adafruit-LED-Backpack-Library).

It based on Peter Sjoberg's  [ht16k33 library](https://github.com/lpaseen/ht16k33).

With version 2.0.0 the syntax has changed. Functions that do not end in `Now` only work in memory. To actually update the LED's, the `sendLed()` function must be called (see example file [`simple-test.cpp`](examples/simple-test.cpp)).
