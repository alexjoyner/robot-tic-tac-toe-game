#include "./bot/bot.h"
#include "./player/player.h"



class TicTacToe{
  public:
    TicTacToe();
    void play();
    void drawBoard();
  private:
    bool game_over;
    char playedTiles[3][3] = {
      {'-', '-', '-'},
      {'-', '-', '-'},
      {'-', '-', '-'}
    };
    Player player_O;
    Bot bot_X;
    void initPLDuinoProject();
    void drawBoardLine(Point&, Point&);
    void checkGameOver(Point, int);
};
