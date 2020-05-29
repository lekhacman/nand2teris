#include <stdio.h>
#include <math.h>
#include "binaryconvert.h"

// [ 0010 1110 0000 ]
// [ 0000 0101 1000 ]
// [ 0000 0010 1000 ]
// [ 0000 0011 0000 ]
// [ 0000 0111 1000 ]
// [ 0000 1000 1000 ]
// [ 0001 1111 1000 ]
// [ 0000 0000 1000 ]
// [ 0000 1100 0000 ]
// [ 0000 0100 1000 ]

int main() {
    char list[][16] = {
            {0,0,1,0, 1,1,1,0, 0,0,0,0},
            {0,0,0,0, 0,1,0,1, 1,0,0,0},
            {0,0,0,0, 0,0,1,0, 1,0,0,0},
            {0,0,0,0, 0,0,1,1, 0,0,0,0},
            {0,0,0,0, 0,1,1,1, 1,0,0,0},
            {0,0,0,0, 1,0,0,0, 1,0,0,0},
            {0,0,0,1, 1,1,1,1, 1,0,0,0},
            {0,0,0,0, 0,0,0,0, 1,0,0,0},
            {0,0,0,0, 1,1,0,0, 0,0,0,0},
            {0,0,0,0, 0,1,0,0, 1,0,0,0}
    };
    for (int i = 0; i < 10; ++i) {
        printf("#%d: %d\t%d\n", i, b2u(list[i], 12), b2t(list[i], 12));
    }
}

int b2u(char bits[], char len) {
    int result = 0;
    printf("[ ");
    for (char i = 0; i < len; ++i) {
        printf("%d ", bits[i]);
        result += bits[i] * pow(2, len - 1 - i);
    }
    printf("]\t");

    return result;
}

int b2t(char bits[], int len) {
    int result = -bits[0] * pow(2, len - 1);
    for (char i = 1; i < len; ++i) {
        result += bits[i] * pow(2, len - 1 - i);
    }

    return result;
}
