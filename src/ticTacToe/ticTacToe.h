#include "./bot/bot.h"
#include "./player/player.h"



class TicTacToe{
  public:
    TicTacToe();
    void play();
    void drawBoard();
  private:
    bool game_over;
    bool playedTiles[3][3] = {
      {0,0,0},
      {0,0,0},
      {0,0,0}
    };
    Player player_O;
    Bot bot_X;
    void initPLDuinoProject();
    void drawBoardLine(Point&, Point&);
    void checkGameOver(Point, int);
};
