#include "bot.h"
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

Bot::Bot(){}

Point Bot::place_X(Adafruit_ILI9341 &tft, char boardState[3][3]){
    Point choice = findBest(boardState);
    int row = choice.x;
    int col = choice.y;
    tft.drawLine(
          (row * 107) + 10, (col * 80) + 10,
          ((row +1) * 107) - 10, ((col + 1) * 80) - 10,
          0xffff
    );
    tft.drawLine(
          (row * 107) + 10, ((col + 1) * 80) - 10,
          ((row +1) * 107) - 10, (col * 80) + 10,
          0xffff
    );
    return choice;
}

Point Bot::findBest(char boardState[3][3]){
  Point choice;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(boardState[i][j] == '-'){
        Point tmp(i, j);
        choice = tmp;
        goto foundChoice;
      }
    }
  }
foundChoice:
  return choice;
}
