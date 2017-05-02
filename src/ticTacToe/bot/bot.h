#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

#include "../ticTacToe.h"

class Bot : public TicTacToe{
  public:
    Bot();
    Point place_X(Adafruit_ILI9341 &tft, char board[3][3]);
  private:
    char bot = 'x';
    char player = 'o';
    int pick_best_move(char board[3][3]);
    int negamax(char board[3][3]);
};
