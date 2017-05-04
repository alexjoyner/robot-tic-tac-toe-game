#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <PLDuino.h>
#include <PLDTouch.h>

void printArray(Point pointArray[], int num_elements);
void clearArray(Point pointArray[], int num_elements);
void print_board(char board[3][3]);
Point getCenterPoint(Point arr[], int num_elements);
bool isBetweenPoints(Point, Point, Point);
