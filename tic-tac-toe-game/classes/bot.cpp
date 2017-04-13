#include "bot.h"
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

Bot::Bot(){}

void Bot::place_X(Adafruit_ILI9341 &tft, int col, int row){
    tft.drawLine(
          (row * 107) + 10, (col * 80) + 10,
          ((row +1) * 107) - 10, ((col + 1) * 80) - 10,
          0xffff
    );
    tft.drawLine(
          (row * 107) + 10, ((col + 1) * 80) - 10,
          ((row +1) * 107) - 10, (col * 80) + 10,
          0xffff
    );
}
