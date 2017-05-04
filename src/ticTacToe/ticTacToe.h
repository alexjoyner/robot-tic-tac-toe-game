#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>
#include "./bot/bot.h"
#include "./player/player.h"



class TicTacToe{
  public:
    TicTacToe();
    void play();
    void drawBoard();
    static char check_win(char board[3][3]);
    static Point getQuadrantOfPoint(Point point);
    static void sendSelectionToRobot(char player, Point position);
  private:
    bool moves = 0;
    char board[3][3] = {
      {'.', '.', '.'},
      {'.', '.', '.'},
      {'.', '.', '.'}
    };
    Player player_O;
    Bot bot_X;
    void initPLDuinoProject();
    void drawBoardLine(Point&, Point&);
};
#endif
