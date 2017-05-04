#include "utils.h"
#include <PLDuino.h>
#include <PLDTouch.h>

void printArray(Point pointArray[], int num_elements){
  Serial.print("{");
  for(int i = 0; i < num_elements; i++){
    if(pointArray[i].x < 350){
      Serial.print("  ");
      Serial.print(pointArray[i].x);
      Serial.print(":");
      Serial.print(pointArray[i].y);
      Serial.print("  ,");
    }
  }
  Serial.println("}");
}

void clearArray(Point given_array[], int num_elements){
  Point tmp;
  for(int i = 0; i < num_elements; i++){
    given_array[i] = tmp;
  }
}
/*********************************************************************
 ** Function: print_board
 ** Description: Prints out the tic-tac-toe board.
 ** Parameters: char[3][3]
 ** Pre-Conditions: None.
 ** Post-Conditions: None.
 *********************************************************************/
void print_board(char board[3][3]) {

	for (int i = 0; i < 3; i++) {
    Serial.print("\n");
		for (int j = 0; j < 3; j++) {
			Serial.print(" ");
			Serial.print(board[i][j]);
		}
	}
	Serial.print("\n \n");
}

Point getCenterPoint(Point arr[], int num_elements){
  int xTot = 0;
  int yTot = 0;
  int count = 0;
  for (int i = 0; i < num_elements; i++) {
    if(arr[i].x < 350){
      xTot += arr[i].x;
      yTot += arr[i].y;
      count ++;
    }
  }
  int xAvg = xTot / count;
  int yAvg = yTot / count;
  Point center(xAvg, yAvg);
  return center;
}

bool isBetweenPoints(Point test, Point topLeft, Point bottomRight){
  return
    ((test.x >= topLeft.x && test.y >= topLeft.y)
    &&
    (test.x <= bottomRight.x && test.y <= bottomRight.y));
};
