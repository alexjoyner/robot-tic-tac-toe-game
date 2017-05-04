#include "bot.h"
#include <PLDuino.h>
#include <PLDTouch.h>
#include <Adafruit_ILI9341.h>

#include "../ticTacToe.h"
Bot::Bot(){}

void Bot::place_X(Adafruit_ILI9341 &tft, char board[3][3]){
    int where_to_move = pick_best_move(board, bot, player);
    int row = where_to_move / 10;
    int col = where_to_move % 10;
    TicTacToe::drawX(row, col);
    Point position(row, col);
    TicTacToe::sendSelectionToRobot('x', position);
    board[row][col] = bot;
}

int Bot::pick_best_move(char board[3][3], char player1, char player2) {

	int best_move_score = -9999;
	int best_move_row = -9999;
	int best_move_col = -9999;
	int score_for_this_move = 0;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == '.') {
				board[r][c] = player1; //Try test move.
				score_for_this_move = -(negamax(board, player2, player1));
				board[r][c] = '.'; //Put back test move.
				if (score_for_this_move >= best_move_score) {
					best_move_score = score_for_this_move;
					best_move_row = r;
					best_move_col = c;
				}
			}
		}
	}
	return (10*best_move_row + best_move_col);
}

/*********************************************************************
 ** Function: negamax
 ** Description: Recursively calls itself to play out every possible
 ** position.
 ** Parameters: char[3][3], char, char
 ** Pre-Conditions: pick_best_move has been called.
 ** Post-Conditions: Returns best_score_move to pick_best_move
 *********************************************************************/
int Bot::negamax(char board[3][3], char player1, char player2) {

	int best_move_score = -9999;
	int score_for_this_move = 0;

	//If player 1 wins, then the score is high (good for player1)
	if (TicTacToe::check_win(board) == player1)
		return 1000;

	//If player 2 loses, then the score is low (bad for player1)
	else if (TicTacToe::check_win(board) == player2)
		return -1000;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == '.') {
				board[r][c] = player1; //Try test move.
				score_for_this_move = -(negamax(board, player2, player1));
				board[r][c] = '.'; //Put back test move.
				if (score_for_this_move >= best_move_score) {
					best_move_score = score_for_this_move;
				}
			}
		}
	}

	if (best_move_score == -9999 || best_move_score == 0)
		return 0;

	else if (best_move_score < 0)
		return best_move_score + 1;

	else if (best_move_score > 0)
		return best_move_score - 1; //As the game goes longer, and the recursion goes deeper, the moves near the end are less favorable than in the beginning.

}
