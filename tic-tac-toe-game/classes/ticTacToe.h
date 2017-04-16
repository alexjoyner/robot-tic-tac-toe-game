#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

#include "player.h"
#include "bot.h"


class TicTacToe{
  public:
    TicTacToe();
    void play();
    void drawBoard();
  private:
    Player player_O;
    Bot bot_X;
    void drawBoardLine(int startX, int startY, int endX, int endY, int width);
};
