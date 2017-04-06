#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

class Player{
  public:
    Player();
    void place_O(Adafruit_ILI9341 &tft, PLDTouch touch);
  private:
    void check_placing_O(Adafruit_ILI9341 &tft, PLDTouch touch);
    Point prev_pt;
    bool started = false;
    bool finished = false;
    int tempX_points[100]; 
    int temp_current_X_point = 0;
    int total_points_in_O = 0;
};

