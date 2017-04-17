#include <Adafruit_ILI9341.h>


class Bot{
  public:
    Bot();
    void place_X(Adafruit_ILI9341 &tft, int col, int row);
};
