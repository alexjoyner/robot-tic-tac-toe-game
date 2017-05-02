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
    player_O.place_O(tft, touch);
    moves ++;
    if(check_win(board) != 0){
      Serial.print("Winner: ");
      Serial.print(check_win(board));
      Serial.print("\n");
    }else{
      Serial.print("No Winner yet");
    };
    bot_X.place_X(tft, board);
    moves ++;
  }
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
