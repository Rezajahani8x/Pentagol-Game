#include <stdio.h>

//rotation function

/*
     A
      * | * | *
      * | * | *
      * | * | *

clockwise:
A[0][0] --> A[0][2]        A[0][1] --> A[1][2]    A[0][2] --> A[2][2]
A[1][0] --> A[0][1]        A[1][1] --> A[1][1]    A[1][2] --> A[2][1]
A[2][0] --> A[0][0]        A[2][1] --> A[1][0]    A[2][2] --> A[2][0]

counter-clockwise:
A[0][0] --> A[2][0]      A[0][1] --> A[1][0]    A[0][2] --> A[0][0]
A[1][0] --> A[2][1]      A[1][1] --> A[1][1]    A[1][2] --> A[0][1]
A[2][0] --> A[2][2]      A[2][1] --> A[1][2]    A[2][2] --> A[0][2]

 
   2  |  1
 -----|-----        cw = +     ccw = -
   3  |  4


*/

void rotation(int square_region, char direction, char board[6][6]) {

// assign value of each elements to seperated variables
    // then reasign the values with their new place

    if (square_region == 2) {
        char b1, b2, b3, b4, b5, b6, b7, b8, b9;
        b1 = board[0][0];
        b2 = board[0][1];
        b3 = board[0][2];
        b4 = board[1][0];
        b5 = board[1][1];
        b6 = board[1][2];
        b7 = board[2][0];
        b8 = board[2][1];
        b9 = board[2][2];
        if (direction == '+') {
            board[0][2] = b1;
            board[0][1] = b4;
            board[0][0] = b7;
            board[1][2] = b2;
            board[1][1] = b5;
            board[1][0] = b8;
            board[2][2] = b3;
            board[2][1] = b6;
            board[2][0] = b9;
        }

        if (direction == '-') {

            board[0][2] = b9;
            board[0][1] = b6;
            board[0][0] = b3;
            board[1][2] = b8;
            board[1][1] = b5;
            board[1][0] = b2;
            board[2][2] = b7;
            board[2][1] = b4;
            board[2][0] = b1;
        }
    }


    if (square_region == 1) {
        char b1, b2, b3, b4, b5, b6, b7, b8, b9;
        b1 = board[0][3];
        b2 = board[0][4];
        b3 = board[0][5];
        b4 = board[1][3];
        b5 = board[1][4];
        b6 = board[1][5];
        b7 = board[2][3];
        b8 = board[2][4];
        b9 = board[2][5];
        if (direction == '+') {
            board[0][5] = b1;
            board[0][4] = b4;
            board[0][3] = b7;
            board[1][5] = b2;
            board[1][4] = b5;
            board[1][3] = b8;
            board[2][5] = b3;
            board[2][4] = b6;
            board[2][3] = b9;
        }

        if (direction == '-') {
            board[0][5] = b9;
            board[0][4] = b6;
            board[0][3] = b3;
            board[1][5] = b8;
            board[1][4] = b5;
            board[1][3] = b2;
            board[2][5] = b7;
            board[2][4] = b4;
            board[2][3] = b1;
        }
    }


    if (square_region == 3) {
        char b1, b2, b3, b4, b5, b6, b7, b8, b9;
        b1 = board[3][0];
        b2 = board[3][1];
        b3 = board[3][2];
        b4 = board[4][0];
        b5 = board[4][1];
        b6 = board[4][2];
        b7 = board[5][0];
        b8 = board[5][1];
        b9 = board[5][2];
        if (direction == '+') {
            board[3][2] = b1;
            board[3][1] = b4;
            board[3][0] = b7;
            board[4][2] = b2;
            board[4][1] = b5;
            board[4][0] = b8;
            board[5][2] = b3;
            board[5][1] = b6;
            board[5][0] = b9;
        }

        if (direction == '-') {
            board[3][2] = b9;
            board[3][1] = b6;
            board[3][0] = b3;
            board[4][2] = b8;
            board[4][1] = b5;
            board[4][0] = b2;
            board[5][2] = b7;
            board[5][1] = b4;
            board[5][0] = b1;
        }
    }

    if (square_region == 4) {
        char b1, b2, b3, b4, b5, b6, b7, b8, b9;
        b1 = board[3][3];
        b2 = board[3][4];
        b3 = board[3][5];
        b4 = board[4][3];
        b5 = board[4][4];
        b6 = board[4][5];
        b7 = board[5][3];
        b8 = board[5][4];
        b9 = board[5][5];
        if (direction == '+') {
            board[3][5] = b1;
            board[3][4] = b4;
            board[3][3] = b7;
            board[4][5] = b2;
            board[4][4] = b5;
            board[4][3] = b8;
            board[5][5] = b3;
            board[5][4] = b6;
            board[5][3] = b9;
        }

        if (direction == '-') {
            board[3][5] = b9;
            board[3][4] = b6;
            board[3][3] = b3;
            board[4][5] = b8;
            board[4][4] = b5;
            board[4][3] = b2;
            board[5][5] = b7;
            board[5][4] = b4;
            board[5][3] = b1;
        }
    }

}






































