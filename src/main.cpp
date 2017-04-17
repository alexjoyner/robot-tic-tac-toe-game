#include <Arduino.h>

#include "classes/ticTacToe/ticTacToe.h"

bool game_over = false;

void setup(){
  Serial.begin(9600);
  TicTacToe ticTacToe_game;
  ticTacToe_game.play();
};

void loop(){};
