//Players : Black / White 
//Black --> b   White --> w
//w=1  b=0

#include <stdio.h>


int turn(int player) {
	switch (player) {
	case 0:
		printf("Black player's turn:\n");
		break;
	case 1:
		printf("White player's turn:\n");
	}
	return 0;
}