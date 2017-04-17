#include "utils.h"
#include <PLDuino.h>
#include <PLDTouch.h>

void printArray(int given_array[], int num_elements){
  Serial.print("{");
  for(int i = 0; i < num_elements; i++){
    Serial.print(given_array[i]);
    Serial.print(":");
  }
  Serial.println("}");
}

void clearArray(int given_array[], int num_elements){
  for(int i = 0; i < num_elements; i++){
    given_array[i] = 0;
  }
}

// Constructor - The default values are specified in the declaration
Point::Point(int x, int y) : x(x), y(y) { }

// Getters
int Point::getX() const { return x; }
int Point::getY() const { return y; }

// Setters
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

// Public Functions
void Point::setXY(int x, int y) { this->x = x; this->y = y; }

void Point::print() const {
   cout << "Point @ (" << x << "," << y << ")";
}
