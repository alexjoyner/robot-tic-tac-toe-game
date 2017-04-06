#include "board.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

Board::Board(){}

void Board::drawBoard(Adafruit_ILI9341 &tft){
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
  drawBoardLine(tft, left_vert_startX,0,left_vert_startX,240,width);
//  Draw Right Vertical line
  drawBoardLine(tft, right_vert_startX,0,right_vert_startX,240,width);
//  Draw Top Horizontal Line
  drawBoardLine(tft, 0,top_hori_startY,0,top_hori_startY + width,320);
//  Draw Bottom Horizontal Line
  drawBoardLine(tft, 0,bot_hori_startY,0,bot_hori_startY + width,320);
}

void Board::drawBoardLine(Adafruit_ILI9341 &tft, int startX, int startY, int endX, int endY, int width){
  for(int i = 0; i < width; i++){
    tft.drawLine(
          startX + i, startY,
          endX + i, endY,
          0xffff
    );
  }
}

