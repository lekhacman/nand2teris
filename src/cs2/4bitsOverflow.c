#include <stdio.h>
#include <math.h>

// suppose we only have 4bits. 1111 = -8 and 0111 = 7
#define MAX 8
#define MIN -7
// lim = pow(2, w-1) = pow(2, 3)
#define LIM 16

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
    printf("decimal hex\n");
    char nine = tadd(4, 5);
    printf("%d\t\t%x\n", nine, nine);
    char four = tadd(1, 3);
    printf("%d\t\t%x\n", four, four);
    char minusNine = tadd(-7, -2);
    printf("%d\t\t%x\n", minusNine, minusNine);

    char x = 127;
    char y = 3;
    char total = x + y;
    printf("%d\t%x\n", total, total);
}
