#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

#include "ticTacToe.h"
#include "./classes/utils/utils.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(PLDuino::LCD_CS, PLDuino::LCD_DC);
PLDTouch touch(PLDuino::TOUCH_CS, PLDuino::TOUCH_IRQ);

TicTacToe::TicTacToe(){
  initPLDuinoProject();
  drawBoard();
}
void TicTacToe::initPLDuinoProject(){
  // Set pin modes and initialize stuff
  // NB: This line is necessary in all sketches which use PLDuino library stuff.
  PLDuino::init();

  // Power-on LCD and set it up
  PLDuino::enableLCD();
  tft.begin();
  tft.setRotation(3);

  // Initialize touch screen
  touch.init(1);

  // Clear the screen.
  tft.fillScreen(ILI9341_BLACK);
}
void TicTacToe::drawBoard(){
  /*
 * Max width X: 320
 * Max Height Y: 240
 */
  const Point top_horizontal_start = new Point(0, 80);
  const Point top_horizontal_end = new Point(320, 80);
  const Point bottom_horizontal_start = new Point(0, 160);
  const Point bottom_horizontal_end = new Point(320, 160);
  const Point left_vertival_start = new Point(107, 0);
  const Point left_vertival_end = new Point(107, 240);
  const Point right_vertival_start = new Point(214, 0);
  const Point right_vertival_end = new Point(214, 240);

  drawBoardLine(top_horizontal_start, top_horizontal_end);
  drawBoardLine(bottom_horizontal_start, bottom_horizontal_end);
  drawBoardLine(left_vertival_start, left_vertival_end);
  drawBoardLine(right_vertival_start, right_vertival_end);
}

void TicTacToe::drawBoardLine(const Point& start, const Point& end){
    //Serial.println(start.x);
    // tft.drawLine(
    //       start.x, start.y,
    //       end.x, end.y,
    //       0xffff
    // );
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
