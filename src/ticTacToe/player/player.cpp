#include "player.h"
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>
#include "../../utils/utils.h"

Player::Player(){}


Point Player::place_O(Adafruit_ILI9341 &tft, PLDTouch touch){
  finished = false;
  while(!finished){
    check_placing_O(tft, touch);
  }
}


void Player::check_placing_O(Adafruit_ILI9341 &tft, PLDTouch touch){
  // Check if user touched the screen
  if (touch.dataAvailable())
  {
    // if(started == false){
    //   Serial.println("drawing O");
    // }
    started = true;
    // Read touch position
    Point pt = touch.read();

    // Draw line between current touch and previous touch, if any
    if (prev_pt.x != -1)
      tft.drawLine(
        prev_pt.x, prev_pt.y,
        pt.x, pt.y,
        0xffff
      );
    if(pt.x != prev_pt.x & total_points_in_O % 4 == 0){
      tempX_points[temp_current_X_point] = pt.x;
      temp_current_X_point ++;
    }
    // Update previous touch position. Now it is current touch.
    prev_pt = pt;
    total_points_in_O ++;
  }
  else
  {
    if(started == true) {
      //Serial.println("finished O");
      finished = true;
      //printArray(tempX_points, 100);
      clearArray(tempX_points, 100);
      temp_current_X_point = 0;
      total_points_in_O = 0;
    }
    started = false;
    // Screen isn't touched currently.
    // Clear previous touch position.
    prev_pt.x = -1;
  }
}
