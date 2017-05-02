#include "./bot/bot.h"
#include "./player/player.h"



class TicTacToe{
  public:
    TicTacToe();
    void play();
    void drawBoard();
  private:
    Player player_O;
    Bot bot_X;
    void drawBoardLine(Point, Point);
};
