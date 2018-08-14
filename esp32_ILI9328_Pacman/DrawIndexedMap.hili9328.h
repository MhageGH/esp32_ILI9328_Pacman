/*
Copyright (c) 2015 coord.e

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef _ILI9328_SPI_H
#define _ILI9328_SPI_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <SPI.h>

#define TFT_WIDTH 320
#define TFT_HEIGHT 240

#define CS_HIGH (*CSPort |= CSPinSet)
#define CS_LOW (*CSPort &= ~CSPinSet)
#define WRITE16(d) SPI.transfer(d)

class ili9328SPI {
public:
  ili9328SPI(uint8_t cs, uint8_t reset);

  void     begin();
  void     drawPixel(int16_t x, int16_t y, uint16_t color);
  void     fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c);
  void     drawFastHLine(int16_t x0, int16_t y0, int16_t w, uint16_t color);
  void     drawFastVLine(int16_t x0, int16_t y0, int16_t h, uint16_t color);
  uint16_t color565(uint8_t r, uint8_t g, uint8_t b);

  private:

  void     setblock(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1);
  void     writereg16(uint16_t com, uint16_t dat);
  void     writecom16(uint16_t com);
  void     writedat16(uint16_t dat);
  void     init();

  uint8_t CSpin, RSTpin;
  uint32_t CSPinSet;
  volatile uint32_t *CSPort;

public:
  void fillScreen(uint16_t color);
  void fillImage(void *image, int x, int y, int w, int h);
  void setblock1(uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1);
  void drawFastHLine1(int16_t x0, int16_t y0, int16_t w, uint16_t color);
};

#endif // _ILI9328_SPI_H
