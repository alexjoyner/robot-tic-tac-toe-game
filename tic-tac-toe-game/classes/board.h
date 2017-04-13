#include <Adafruit_ILI9341.h>

class Board{
  public:
    Board();
    void drawBoard(Adafruit_ILI9341 &tft);
  private:
    void drawBoardLine(Adafruit_ILI9341 &tft, int startX, int startY, int endX, int endY, int width);
};

