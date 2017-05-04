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
  bool startedPlacing = false;
  Point prev_pt;
  Point playPoints[100];
  int count_points = 0;
  int count_every_4th_point = 0;
  while(!finished){
    if (touch.dataAvailable()){
      startedPlacing = true;
      Point pt = touch.read();
      if (prev_pt.x != -1)
        tft.drawLine(
          prev_pt.x, prev_pt.y,
          pt.x, pt.y,
          0xffff
        );
      // To get an accurate average of placed shape
      // only use every 4th point of the shape drawn
      if((pt.x != prev_pt.x) && ((count_points % 4 == 0) || count_points < 4)){
        playPoints[count_every_4th_point] = pt;
        count_every_4th_point ++;
      }
      prev_pt = pt;
      count_points ++;
    }
    else
    {
      if(startedPlacing) {
        finished = true;
      }
      startedPlacing = false;
      // Screen isn't touched currently.
      // Clear previous touch position.
      prev_pt.x = -1;
    }
  }
  //printArray(playPoints, 100);
  Point center = getCenterPoint(playPoints, 100);
  Point placedIn = TicTacToe::getQuadrantOfPoint(center);
  return placedIn;
}
