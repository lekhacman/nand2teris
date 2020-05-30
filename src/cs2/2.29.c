#include <stdio.h>
#include <math.h>

// suppose we only have 5bits. 11111 = -16 and 01111 = 15
#define BITS 5
#define MAX 15
#define MIN -16
// lim = pow(2, w-1) = pow(2, 4) = 32
#define LIM 32

char b2t(char bits[]) {
    int result = -bits[0] * pow(2, BITS - 1);
    for (char i = 1; i < BITS; ++i) {
        result += bits[i] * pow(2, BITS - 1 - i);
    }

    return result;
}

void showBits(char *b) {
    printf("[");
    for (int i = 0; i < BITS; ++i) {
        printf("%d", b[i]);
    }
    printf("]");
}

char tadd(short a, short b) {
    short result = a + b;
    if (result >= MAX) {
        return (char) (result - LIM);
    } else if (result < MIN) {
        return (char) (result + LIM);
    } else {
        return (char) result;
    }
}

int main() {
    printf("Number of bits:\t\t%d\n", BITS);
    printf("Capacity:\t\t\t%d\n", LIM);
    printf("2's complement max: %d\n", MIN);
    printf("2's complement min: %d\n\n", MAX);

    char cases[][2][BITS] = {
            {{1,0,1,0,0}, {1,0,0,0,1}},
            {{1,1,0,0,0}, {1,1,0,0,0}},
            {{1,0,1,1,1}, {0,1,0,0,0}},
            {{0,0,0,1,0}, {0,0,1,0,1}},
            {{0,1,1,0,0}, {0,0,1,0,0}}
    };

    printf("x\t\ty\t\tx+y\tx+y(5t)\tCase\n");
    for (int i = 0; i < 5; ++i) {
        char x = b2t(cases[i][0]);
        char y = b2t(cases[i][1]);
        printf("%d\t\t", x);
        printf("%d\t\t", y);

        char sum = x + y;
        printf("%d\t", sum);
        char sum5bits = tadd(x, y);
        printf("%d\t\n", sum5bits);


        showBits(cases[i][0]);
        showBits(cases[i][1]);
        printf("\n");
    }
}
