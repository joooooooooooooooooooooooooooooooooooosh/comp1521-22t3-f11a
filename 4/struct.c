#include <stdio.h>
#include <stdlib.h>

struct point2D {
    int row;
    char x;
    int col;
} typedef point2D_t;

int main(int argc, char **argv) {
    point2D_t point;
    // &point = 1000
    // &point.row = &point + offset to get to row
    //            = 1000 + 0
    // &point.x   = &point + offset to get to x
    //            = 1000 + 4 = 1004
    // &point.col = 1000 + 5 = 1005
    return EXIT_SUCCESS;
}

