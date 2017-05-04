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
  while (moves < 9){
    player_O.place_O(tft, touch, board);
    moves ++;
    // if(check_win(board) != 0){
    //   Serial.print("Winner: ");
    //   Serial.print(check_win(board));
    //   Serial.print("\n");
    //   return;
    // };
    delay(1000);
    // bot_X.place_X(tft, board);
    // moves ++;
    // print_board(board);
    // if(check_win(board) != 0){
    //   Serial.print("Winner: ");
    //   Serial.print(check_win(board));
    //   Serial.print("\n");
    //   return;
    // };
  }
  Serial.println("CAT!!!");
}

/*********************************************************************
 ** Function: check_win
 ** Description: Checks for three in a row in all directions.
 ** Parameters: char[3][3]
 ** Pre-Conditions: None.
 ** Post-Conditions: Returns the character that that the three in a row consists of.
 *********************************************************************/
char TicTacToe::check_win(char board[3][3]) {

	// Check horizontal, vertical & diagonal through [0][0]
	if (board[0][0] != '.' && (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
		board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
		board[0][0] == board[1][1] && board[0][0] == board[2][2]))

		return board[0][0];

	// Check horizontal, vertical & diagonal through [1][1]
	if (board[1][1] != '.' && (board[1][1] == board[1][0] && board[1][1] == board[1][2] ||
		board[1][1] == board[0][1] && board[1][1] == board[2][1] ||
		board[1][1] == board[2][0] && board[1][1] == board[0][2]))

		return board[1][1];

	// Check horizontal, vertical & diagonal through [2][2]
	if (board[2][2] != '.' && (board[2][2] == board[0][2] && board[2][2] == board[1][2] ||
		board[2][2] == board[2][0] && board[2][2] == board[2][1]))

		return board[2][2];

	return 0;
}

Point TicTacToe::getQuadrantOfPoint(Point point){
  Point tile1_topLeft(0,0);
  Point tile1_bottomRight(107,80);
  Point tile2_topLeft(107,0);
  Point tile2_bottomRight(214,80);
  Point tile3_topLeft(214,0);
  Point tile3_bottomRight(320,80);
  Point tile4_topLeft(0,80);
  Point tile4_bottomRight(107,160);
  Point tile5_topLeft(107,80);
  Point tile5_bottomRight(214,160);
  Point tile6_topLeft(214,80);
  Point tile6_bottomRight(320,160);
  Point tile7_topLeft(0,160);
  Point tile7_bottomRight(107,240);
  Point tile8_topLeft(107,160);
  Point tile8_bottomRight(214,240);
  Point tile9_topLeft(214,160);
  Point tile9_bottomRight(320,240);
  if(isBetweenPoints(point, tile1_topLeft, tile1_bottomRight)){
    Point position(0,0);
    return position;
  }else
  if(isBetweenPoints(point, tile2_topLeft, tile2_bottomRight)){
    Point position(0,1);
    return position;
  }else
  if(isBetweenPoints(point, tile3_topLeft, tile3_bottomRight)){
    Point position(0,2);
    return position;
  }else
  if(isBetweenPoints(point, tile4_topLeft, tile4_bottomRight)){
    Point position(1,0);
    return position;
  }else
  if(isBetweenPoints(point, tile5_topLeft, tile5_bottomRight)){
    Point position(1,1);
    return position;
  }else
  if(isBetweenPoints(point, tile6_topLeft, tile6_bottomRight)){
    Point position(1,2);
    return position;
  }else
  if(isBetweenPoints(point, tile7_topLeft, tile7_bottomRight)){
    Point position(2,0);
    return position;
  }else
  if(isBetweenPoints(point, tile8_topLeft, tile8_bottomRight)){
    Point position(2,1);
    return position;
  }else
  if(isBetweenPoints(point, tile9_topLeft, tile9_bottomRight)){
    Point position(2,2);
    return position;
  }
}

void TicTacToe::sendSelectionToRobot(char player, Point position){
  // int bonus;
  // if(player == 'x'){
  //   bonus = 10;
  // }
  int areaCode = (position.x * 3) + position.y;
  byte OutMatrix[18] = {
     B00000001,
     B00000010,
     B00000011,
     B00000100,
     B00000101,
     B00000110,
     B00000111,
     B00001000,
     B00001001
   };
  byte resultSignal = OutMatrix[areaCode];
  for(int i = 0; i < 8; i++){
    digitalWrite(38+i, bitRead(resultSignal, i) == 1? HIGH : LOW);
  }

}
