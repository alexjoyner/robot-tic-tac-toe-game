#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

#include "ticTacToe.h"
#include "./utils/utils.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(PLDuino::LCD_CS, PLDuino::LCD_DC);
PLDTouch touch(PLDuino::TOUCH_CS, PLDuino::TOUCH_IRQ);

TicTacToe::TicTacToe(){
  drawBoard();
}
void TicTacToe::drawBoard(){
  /*
 * Max width X: 320
 * Max Height Y: 240
 */
  drawBoardLine(Point point(0, 80), Point point(320, 80));
  drawBoardLine(Point point(0, 160), Point point(320, 160));
  drawBoardLine(Point point(107, 0), Point point(214, 0));
  drawBoardLine(Point point(214, 0), Point point(214, 240));
}

void TicTacToe::drawBoardLine(Point start, Point end){
    Serial.println(start.x);
    tft.drawLine(
          start.x, start.y,
          end.x, end.y,
          0xffff
    );
}

void TicTacToe::play(){
    /*
   * While the game isn't finished,
   *  1: Check who's turn it in
   *  2:  if it's bot_X turn, bot_X place X
   *  3:  if it's player_O turn, player_O place O
   *  4: Check game over
   */
   delay(200);
   bot_X.place_X(tft, 1, 0);
   player_O.place_O(tft, touch);
   delay(2000);
   bot_X.place_X(tft, 1, 2);
   player_O.place_O(tft, touch);
   delay(2000);
   bot_X.place_X(tft, 1, 1);
   player_O.place_O(tft, touch);
   delay(2000);
   bot_X.place_X(tft, 0, 1);
   player_O.place_O(tft, touch);
}
