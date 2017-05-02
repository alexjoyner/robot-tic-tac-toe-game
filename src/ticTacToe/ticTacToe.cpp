#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

#include "ticTacToe.h"
#include "../utils/utils.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(PLDuino::LCD_CS, PLDuino::LCD_DC);
PLDTouch touch(PLDuino::TOUCH_CS, PLDuino::TOUCH_IRQ);

TicTacToe::TicTacToe(){
  game_over = false;
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
  Point top_horizontal_start(0, 80);
  Point top_horizontal_end(320, 80);
  Point bottom_horizontal_start(0, 160);
  Point bottom_horizontal_end(320, 160);
  Point left_vertival_start(107, 0);
  Point left_vertival_end(107, 240);
  Point right_vertival_start(214, 0);
  Point right_vertival_end(214, 240);

  drawBoardLine(top_horizontal_start, top_horizontal_end);
  drawBoardLine(bottom_horizontal_start, bottom_horizontal_end);
  drawBoardLine(left_vertival_start, left_vertival_end);
  drawBoardLine(right_vertival_start, right_vertival_end);

}

void TicTacToe::drawBoardLine(Point& start, Point& end){
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
   int playerPlay;
  //  while(!game_over){
     Point botPlay = bot_X.place_X(tft, playedTiles);
  //    player_O.place_O(tft, touch);
     checkGameOver(botPlay, playerPlay);
  //  }
}

void TicTacToe::checkGameOver(Point botPlay, int playerPlay) {
  playedTiles[botPlay.x][botPlay.y] = 1;
  Serial.print("Current Board State \n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      Serial.print(playedTiles[i][j]);
      Serial.print(", ");
    }
    Serial.print("\n");
  }
}
