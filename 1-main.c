#include <stdio.h>
#include <stdlib.h>
#include "check.h"
#include "display.h"
#include "input.h"
#include "result.h"
#include "rotation.h"
#include "turn.h"

//headerfiles and functions are added

/*
1-show display
2-send message and place black piece
3-send message and rotate the selected region
4-check if the game is over {victory for either or draw while all the blocks are full}
5-send message and place white piece
6-send message and rotate the selected region
7-check if the game is over{"already explained"}
8-repeat
*/

int main() {
	char board[6][6];
	int i, j;
	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 5; j++) {
			board[i][j] = '.';
		}
	}

	//currently all the houses are .

	display(board);
	int round;
	int end = 0;
	int player;
	/*
	at the highest level we've got 36 rounds
	starting by black player first round and also
	odd rounds refer to black
	on the other hand even rounds refer to white
	*/
	for (round = 1; round <= 36; round++) {
		if (round % 2 == 0) {
			player = 1;
		}
		else {
			player = 0;
		}
		//when end is 0 game is still on if 1 game should end
		turn(player);
		printf("Enter the house:\n");
		while (true) {
			int coordinate, row, column;
			scanf_s("%d", &coordinate);
			row = coordinate / 10;
			column = coordinate - 10 * row;
			if (row >= 1 && row <= 6 && column >= 1 && column <= 6 && board[row-1][column-1]=='.') {
				input(coordinate, player, board);
				system("cls");
				display(board);
				printf("Select the region and direction to rotate:\n");
				while (true) {
					int square_region;
					char direction;
					scanf_s("%d %c", &square_region, &direction);
					if (square_region >= 1 && square_region <= 4) {
						if (direction == '-' || direction == '+') {
							rotation(square_region, direction, board);
							system("cls");
							display(board);
							//time to check the game situation
							//if victory has already happend we will finish the game with a message
							//if nobody has won yet there is 2 way 
							// first we still have free houses so game is still on  
							//or all the houses are full so the result is DRAW!
							int result = check(board);
							if (result != 5) {
								if (result == 1) {
									result_of_game(1);
									end = 1;
									break;
								}
								if (result == 0) {
									result_of_game(0);
									end = 1;
									break;
								}
							}
							else {
								end = 1;
								for (i = 0; i <= 5; i++) {
									for (j = 0; j <= 5; j++) {
										if (board[i][j] == '.') {
											end = 0;
										}
									}
								}
								if (end == 1) {
									result_of_game(5);
								}
							}
							break;
						}
					}
				}
				break;
			}
		}
		if (end == 1)
			break;
	}
}