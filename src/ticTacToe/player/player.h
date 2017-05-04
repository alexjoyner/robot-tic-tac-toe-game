#ifndef PLAYER_H
#define PLAYER_H
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

class Player{
  public:
    Player();
    void place_O(Adafruit_ILI9341 &tft, PLDTouch touch, char board[3][3]);
  private:
    Point getPositionInput(Adafruit_ILI9341 &tft, PLDTouch touch);
};

#endif
