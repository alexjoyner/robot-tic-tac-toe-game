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
