#ifndef BOT_H
#define BOT_H
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

class Bot{
  public:
    Bot();
    void place_X(Adafruit_ILI9341 &tft, char board[3][3]);
  private:
    char bot = 'x';
    char player = 'o';
    int pick_best_move(char board[3][3], char player1, char player2);
    int negamax(char board[3][3], char player1, char player2);
};
#endif
