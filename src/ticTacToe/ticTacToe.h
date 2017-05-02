#include "./bot/bot.h"
#include "./player/player.h"



class TicTacToe{
  public:
    TicTacToe();
    void play();
    void drawBoard();
    char check_win(char board[3][3]);
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
