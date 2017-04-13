#include <Arduino.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

#include "classes/board.h"
#include "classes/player.h"
#include "classes/bot.h"

// Initialize variables
Adafruit_ILI9341 tft = Adafruit_ILI9341(PLDuino::LCD_CS, PLDuino::LCD_DC);
PLDTouch touch(PLDuino::TOUCH_CS, PLDuino::TOUCH_IRQ);

Board gameBoard;
Player player_O;
Bot bot_X;

bool game_over = false;

void setup()
{
  // open the serial port at 9600 bps:
  Serial.begin(9600);

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

  gameBoard.drawBoard(tft);

    /*
   * While the game isn't finished,
   *  1: Check who's turn it in
   *  2:  if it's bot_X turn, bot_X place X
   *  3:  if it's player_O turn, player_O place O
   *  4: Check game over
   */
   delay(200);
   bot_X.place_X(tft, 0, 0);
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

//   save_played_piece
//   if(game_over){
//    return
//   }
};

void loop(){};
