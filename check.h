#include <stdio.h>

//check function

//check if the game is over

/*
1-horizental 4
2-vertical 4
3-orib 4
*/

/*
1.horizental     
----|   |----
4 blocks with the same i and each one j++
I)   (i,j) (i,j+1) (i,j+2) (i,j+3) (i-1,j+3)
II)  (i,j) (i,j+1) (i,j+2) (i,j+3) (i-1,j)
III) (i,j) (i,j+1) (i,j+2) (i,j+3) (i+1,j)
IV)  (i,j) (i,j+1) (i,j+2) (i,j+3) (i+1,j+3)
*/

/*
2.vertical
                               4 blocks witch the same j and each one i++
    |      |     _    _     I)  (i,j) (i+1,j) (i+2,j) (i+3,j) (i,j+1)
    |      |    |      |    II) (i,j) (i+1,j) (i+2,j) (i+3,j) (i,j-1)
    |      |    |      |   III) (i,j) (i+1,j) (i+2,j) (i+3,j) (i+3,j+1)
	|_    _|    |      |   IV)  (i,j) (i+1,j) (i+2,j) (i+3,j) (i+3,j-1)
	            |      | 
*/

int check(char board[6][6]) {
	//black
	int i, j;
	int result=5;

	//moving block by block checking if conditions are satisfied
	/*
	when four blocks of horizental blocks are the same value and then one of the 4 choices satisfied it means
	the player has won.we can use this for verical checking too.
	*/

	//horizental
	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 2; j++) {
			if (board[i][j]=='b' && board[i][j + 1]=='b' && board[i][j + 2]=='b' && board[i][j + 3] == 'b') {
				if (board[i - 1][j + 3]=='b' || board[i - 1][j]=='b' || board[i + 1][j]=='b' || board[i + 1][j + 3]=='b') {
					result = 0;
					break;
				}
			}
		}
		if (result == 0) {
			break;
		}
	}
	if (result != 0) {
		//vertical
		for (j = 0; j <= 5; j++) {
			for (i = 0; i <= 2; i++) {
				if (board[i][j]=='b' && board[i + 1][j]=='b' && board[i + 2][j]=='b' && board[i + 3][j] == 'b') {
					if (board[i][j + 1]=='b' || board[i][j - 1]=='b' || board[i + 3][j + 1]=='b' || board[i + 3][j - 1] == 'b') {
						result = 0;
						break;
					}
				}
			}
			if (result == 0) {
				break;
			}
		}
	}

	//white

	//horizental
	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 2; j++) {
			if (board[i][j]=='w' && board[i][j + 1]=='w' && board[i][j + 2]=='w' && board[i][j + 3] == 'w') {
				if (board[i - 1][j + 3]=='w' || board[i - 1][j]=='w' || board[i + 1][j]=='w' || board[i + 1][j + 3] == 'w') {
					result = 1;
					break;
				}
			}
		}
		if (result == 1) {
			break;
		}
	}
	if (result != 1) {
		//vertical 
		for (j = 0; j <= 5; j++) {
			for (i = 0; i <= 2; i++) {
				if (board[i][j]=='w' && board[i + 1][j]=='w' && board[i + 2][j]=='w' && board[i + 3][j] == 'w') {
					if (board[i][j + 1]=='w' || board[i][j - 1]=='w' || board[i + 3][j + 1]=='w' || board[i + 3][j - 1] == 'w') {
						result = 1;
						break;
					}
				}
			}
			if (result == 1) {
				break;
			}
		}
	}

	/*
	checking four blocks on an orib line and then if they carry the same value we check if one of the 4 choices
	is happening.
	we've got 2 types of orib line / , \ we have to check for both.
	*/

	//orib check
	if (result != 0) {
		for (i = 0; i <= 2; i++) {
			for (j = 0; j <= 2; j++) {
				if (board[i][j]=='b' && board[i + 1][j + 1]=='b' && board[i + 2][j + 2]=='b' && board[i + 3][j + 3] == 'b') {
					if (board[i + 2][j + 4]=='b' || board[i + 4][j + 2]=='b' || board[i - 1][j + 1]=='b' || board[i + 1][j - 1] == 'b') {
						result = 0;
						break;
					}
				}
			}
			if (result == 0) {
				break;
			}
		}
		if (result != 0) {
			for (i = 0; i <= 2; i++) {
				for (j = 5; j >= 3; j--) {
					if (board[i][j]=='b' && board[i + 1][j - 1]=='b' && board[i + 2][j - 2]=='b' && board[i + 3][j - 3] == 'b') {
						if (board[i - 1][j - 1]=='b' || board[i + 1][j + 1]=='b' || board[i + 2][j - 4]=='b' || board[i + 4][j - 2] == 'b') {
							result = 0;
							break;
						}
					}
				}
				if (result == 0) {
					break;
				}
			}
		}
	}

	if (result != 1) {
		for (i = 0; i <= 2; i++) {
			for (j = 0; j <= 2; j++) {
				if (board[i][j]=='w' && board[i + 1][j + 1]=='w' && board[i + 2][j + 2]=='w' && board[i + 3][j + 3] == 'w') {
					if (board[i + 2][j + 4]=='w' || board[i + 4][j + 2]=='w' || board[i - 1][j + 1]=='w' || board[i + 1][j - 1] == 'w') {
						result = 1;
						break;
					}
				}
			}
			if (result == 1) {
				break;
			}
		}
		if (result != 1) {
			for (i = 0; i <= 2; i++) {
				for (j = 5; j >= 3; j--) {
					if (board[i][j]=='w' && board[i + 1][j - 1]=='w' && board[i + 2][j - 2]=='w' && board[i + 3][j - 3] == 'w') {
						if (board[i - 1][j - 1]=='w' || board[i + 1][j + 1]=='w' || board[i + 2][j - 4]=='w' || board[i + 4][j - 2] == 'w') {
							result = 1;
							break;
						}
					}
				}
				if (result == 1) {
					break;
				}
			}
		}
	}
	return result;
}








































