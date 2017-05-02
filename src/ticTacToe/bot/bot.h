#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>


class Bot{
  public:
    Bot();
    Point place_X(Adafruit_ILI9341 &tft, int col, int row);
};
