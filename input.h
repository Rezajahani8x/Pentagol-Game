#include <stdio.h>

//input for placing pieces on board

int input(int coordinate,int player, char board[6][6]) {
	int row = coordinate / 10;
	int column = coordinate - 10 * row;
	int row_num = row - 1;
	int column_num = column - 1;
	switch (player) {
	case 0:
		board[row_num][column_num] = 'b';
		break;
	case 1:
		board[row_num][column_num] = 'w';
		break;
	}
	return 0;
}