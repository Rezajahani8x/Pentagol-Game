#include <stdio.h>

//this function  is used to update board while pieces are placed graphically

int update(int a, int b, int c, int d, char board[6][6], int player) {
	int x = (a + c) / 2;
	int y = (b + d) / 2;

	//centre of circle which has been fullfilled with the color

	char piece;
	if (player == 1) {
		piece = 'w';
	}
	if (player == 0) {
		piece = 'b';
	}

	//i define the very first centre and using a loop I change it and i compare to reach the circle I want to
	//change the stack in array based on that.
	int dy, dx;
	int i, j;
	//dy=defined y   dx=defined x;

	dy = 50;
	for (i = 0; i <= 5; i++) {
		dx = 50;
		for (j = 0; j <= 5; j++) {
			if (x == dx && y == dy) {
				board[i][j] = piece;
			}
			dx = dx + 100;
		}
		dy = dy + 100;
	}
	return 0;
}