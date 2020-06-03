#include <stdio.h>
#include <math.h>

int b2u(char bits[], char len) {
    int result = 0;
    printf("[");
    for (char i = 0; i < len; ++i) {
        printf("%d", bits[i]);
        result += bits[i] * pow(2, len - 1 - i);
    }
    printf("] ");

    return result;
}

int b2t(char bits[], int len) {
    printf("[");
    int result = -bits[0] * pow(2, len - 1);
    printf("%d", bits[0]);

    for (char i = 1; i < len; ++i) {
        printf("%d", bits[i]);
        result += bits[i] * pow(2, len - 1 - i);
    }
    printf("] ");

    return result;
}

int main() {
    char list[3][2][3] = {
            {{1, 0, 0}, {1,0,1}},
            {{0, 1, 0}, {1,1,1}},
            {{1, 1, 0}, {1,1,0}},
    };

    printf("x\t\ty\t\tx.y\ttruncated x.y\n");
    for (int i = 0; i < 3; ++i) {
        char x = b2u(list[i][0], 3);
        printf("%d ", x);
        char y = b2u(list[i][1], 3);
        printf("%d\t", y);
        printf("%d\t%d\t\n", x*y, ((x*y) % 8));
    }

    printf("\n\n");

    printf("x\t\t\ty\t\t\tx.y\ttruncated x.y\n");
    for (int i = 0; i < 3; ++i) {
        char x = b2t(list[i][0], 3);
        printf("%d \t", x);
        char y = b2t(list[i][1], 3);
        printf("%d\t", y);
        signed char xy = (x*y) % 8;
        xy <<= 5;
        xy >>= 5;
        printf("%d\t%d\t\n", x*y, xy);
    }
}
