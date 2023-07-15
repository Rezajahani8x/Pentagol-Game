#include <stdio.h>

// Game display
/* 8 rows 8 columns
the first row 6 numbers a border from 3 to 4
and else*/

//ASCII:
// b=98 w=119 .=46

int display(char board[6][6]) {
	printf("  \t1\t2\t3  |  4\t\t5\t6\n\n");
	int i;
	for (i = 0; i <= 2; i++) {
		int j;
		printf("%d\t", i+1);
		for (j = 0; j <= 5; j++) {
			if (j == 3) {
				printf("%c\t\t", board[i][j]);
			}
			if (j == 5) {
				printf("%c", board[i][j]);
				printf("\n\n");
			}
			if (j == 2) {
				printf("%c  |  ", board[i][j]);
			}
			if(j!=2 && j!=5 && j!=3) {
				printf("%c\t", board[i][j]);
			}
		}
	}
	printf("--\t--\t--\t--    --\t--\t--\n\n");
	for (i = 3; i <= 5; i++) {
		int j;
		printf("%d\t", i+1);
		for (j = 0; j <= 5; j++) {
			if (j == 3) {
				printf("%c\t\t",board[i][j]);
			}
			if (j == 5) {
				printf("%c", board[i][j]);
				printf("\n\n");
			}
			if (j == 2) {
				printf("%c  |  ", board[i][j]);
			}
			if (j != 2 && j != 5 && j!=3) {
				printf("%c\t", board[i][j]);
			}
		}
	}
	return 0;
}