#include <stdio.h>


//cordinate=(dy)10 = 10d+y
//int(cordinate/10)=Row
//cordinate - Row x 10=Column

/*white player = 1 w
black player = 0 b */

int result_of_game(int r) {
	switch (r) {
	case 1:
		printf("The WHITE Player has won the game!\n");
		break;
	case 0:
		printf("The BLACK Player has won the game!\n");
		break;
	case 5:
		printf("The Game has been brought to a DRAW!\n");
	}
	return 0;
}