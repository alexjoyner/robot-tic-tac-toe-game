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
    void initBoard();
    static char check_win(char board[3][3]);
    static Point getQuadrantOfPoint(Point point);
    static void sendSelectionToRobot(char player, Point position);
    static void drawO(int row,int col);
    static void drawX(int row,int col);
  private:
    int moves = 0;
    char board[3][3];
    Player player_O;
    Bot bot_X;
    void runMainLogic();
    void initPLDuinoProject();
    void initBoardLine(Point&, Point&);
    void cleanBoard(char board[3][3]);
    void removePieceFromBoard(Point position);
    void reset();
};
#endif
