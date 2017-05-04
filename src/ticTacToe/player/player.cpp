#include "player.h"
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>
#include "../../utils/utils.h"
#include "../ticTacToe.h"
Player::Player(){}

void Player::place_O(Adafruit_ILI9341 &tft, PLDTouch touch, char board[3][3]){
  Point placedIn = getPositionInput(tft, touch);
  TicTacToe::sendSelectionToRobot('o', placedIn);
  board[placedIn.x][placedIn.y] = 'o';
}

Point Player::getPositionInput(Adafruit_ILI9341 &tft, PLDTouch touch){
  bool finished = false;
  while(!finished){
    if(touch.dataAvailable()){
        Point pt = touch.read();
        Point position = TicTacToe::getQuadrantOfPoint(pt);
        TicTacToe::drawO(position.x, position.y);
        return position;
        finished = true;
    }
  }
}
