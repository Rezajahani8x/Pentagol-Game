#include <stdio.h>
#include "graphics.h"
#include "check.h"
#include "result.h"
#include "input.h"
#include "rotation.h"
#include "turn.h"
#include "display.h"
#include "update.h"
#include <stdlib.h>

//header files added

int main() {
	char board[6][6];
	int i, j;
	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 5; j++) {
			board[i][j] = '.';
		}
	}

	//all houses are . now

	initwindow(600, 600, "Display");
	setbkcolor(4);
	cleardevice();
	setlinestyle(0, 0, 3);
	setcolor(0);
	line(300, 0, 300, 600);
	setlinestyle(0, 0, 3);
	setcolor(0);
	line(0, 300, 600, 300);

	//display has just been set

	//36 rounds maximumly 
	//start with black odd rounds refer to black 
	//even rounds refer to white

	/*
	1-send message and define turn
	2-place piece graphically
	3-update board
	4-send message for rotate
	5-rotate
	6-update board
	7-check (if done finish)
	8-repeat
	*/

	int player;
	int round;
	int end = 0;
	for (round = 1; round <= 36; round++) {
		if (round % 2 == 0) {
			player = 1;
		}
		else {
			player = 0;
		}

		int x, y;
		y = 50;
		for (i = 0; i <= 5; i++) {
			x = 50;
			for (j = 0; j <= 5; j++) {
				int color;
				if (board[i][j] == '.') {
					setcolor(BLUE);
					circle(x, y, 20);
					setfillstyle(SOLID_FILL, RED);
					floodfill(x, y, BLUE);
				}
				if (board[i][j] == 'b') {
					setcolor(BLUE);
					circle(x, y, 20);
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(x, y, BLUE);
				}
				if (board[i][j] == 'w') {
					setcolor(BLUE);
					circle(x, y, 20);
					setfillstyle(SOLID_FILL, WHITE);
					floodfill(x, y, BLUE);
				}
				x = x + 100;
			}
			y = y + 100;
		}

		//circle houses are made now 
		//distance between centres are 100
		//setting the pointer square

		turn(player);

		setcolor(BLUE);
		int a, b, c, d;
		a = 20;
		b = 20;
		c = 80;
		d = 80;
		rectangle(a, b, c, d);
		char key;

		while (true) {
			key = getch();
			if (key == 's') {
				setcolor(BLUE);
				rectangle(a, b + 100, c, d + 100);
				setcolor(RED);
				rectangle(a, b, c, d);
				b = b + 100;
				d = d + 100;
			}
			if (key == 'd') {
				setcolor(BLUE);
				rectangle(a + 100, b, c + 100, d);
				setcolor(RED);
				rectangle(a, b, c, d);
				a = a + 100;
				c = c + 100;
			}
			if (key == 'a') {
				setcolor(BLUE);
				rectangle(a - 100, b, c - 100, d);
				setcolor(RED);
				rectangle(a, b, c, d);
				a = a - 100;
				c = c - 100;
			}
			if (key == 'w') {
				setcolor(BLUE);
				rectangle(a, b - 100, c, d - 100);
				setcolor(RED);
				rectangle(a, b, c, d);
				b = b - 100;
				d = d - 100;
			}
			//fullfill the house with a color
			//update board
			if (key == 'f') {
				if (player == 0) {
					setfillstyle(1, BLACK);
					floodfill((a + c) / 2, (b + d) / 2, BLUE);
					update(a, b, c, d, board, 0);
				}
				if (player == 1) {
					setfillstyle(1, WHITE);
					floodfill((a + c) / 2, (b + d) / 2, BLUE);
					update(a, b, c, d, board, 1);
				}
				break;
			}
		}

		//piece has been setboard has been updated


		printf("Select a region and rotate:\n+ for 90 degrees clockwise\n- for 90 degrees counter-clockwise\n");
		while (true) {
			int square_region;
			char direction;
			scanf_s("%d &c", &square_region, &direction);
			if (square_region >= 1 && square_region <= 4) {
				if (direction == '+' || direction == '-') {
					rotation(square_region, direction, board);
					y = 50;
					for (i = 0; i <= 5; i++) {
						x = 50;
						for (j = 0; j <= 5; j++) {
							int color;
							if (board[i][j] == '.') {
								setcolor(BLUE);
								circle(x, y, 20);
								setfillstyle(SOLID_FILL, RED);
								floodfill(x, y, BLUE);
							}
							if (board[i][j] == 'b') {
								setcolor(BLUE);
								circle(x, y, 20);
								setfillstyle(SOLID_FILL, BLACK);
								floodfill(x, y, BLUE);
							}
							if (board[i][j] == 'w') {
								setcolor(BLUE);
								circle(x, y, 20);
								setfillstyle(SOLID_FILL, WHITE);
								floodfill(x, y, BLUE);
							}
							x = x + 100;
						}
						y = y + 100;
					}

					//board array which is used to store data to check the situation of game is updated
					//also the main display has been updated and drawn again

					//time to check if the game is over!

												//time to check the game situation
							//if victory has already happend we will finish the game with a message
							//if nobody has won yet there is 2 way 
							// first we still have free houses so game is still on  
							//or all the houses are full so the result is DRAW!

					//I use the board array to check the game

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
		if (end == 1) {
			break;
		}
	}

	delay(20000);
	closegraph();
	return 0;
}
