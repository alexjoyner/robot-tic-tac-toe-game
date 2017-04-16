#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

#include "ticTacToe.h"


Adafruit_ILI9341 tft = Adafruit_ILI9341(PLDuino::LCD_CS, PLDuino::LCD_DC);
PLDTouch touch(PLDuino::TOUCH_CS, PLDuino::TOUCH_IRQ);

TicTacToe::TicTacToe(){
  Serial.println("Hello World 2");
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

  drawBoard();
}

void TicTacToe::drawBoard(){
  /*
 * Max width X: 320
 * Max Height Y: 240
 */
  int width = 1;
  int left_vert_startX = 107;
  int right_vert_startX = 214;
  int top_hori_startY = 80;
  int bot_hori_startY = 160;
//  Draw Left Vertical Line
  drawBoardLine(left_vert_startX,0,left_vert_startX,240,width);
//  Draw Right Vertical line
  drawBoardLine(right_vert_startX,0,right_vert_startX,240,width);
//  Draw Top Horizontal Line
  drawBoardLine(0,top_hori_startY,0,top_hori_startY + width,320);
//  Draw Bottom Horizontal Line
  drawBoardLine(0,bot_hori_startY,0,bot_hori_startY + width,320);
}

void TicTacToe::drawBoardLine(int startX, int startY, int endX, int endY, int width){
  for(int i = 0; i < width; i++){
    tft.drawLine(
          startX + i, startY,
          endX + i, endY,
          0xffff
    );
  }
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
