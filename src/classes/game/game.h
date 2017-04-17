#include <Adafruit_ILI9341.h>


class Game{
  public:
    Game();
    addPlayer();
  private:
    int winner_indx;
    int players[];
};
