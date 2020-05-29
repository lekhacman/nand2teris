#include <stdio.h>
#include <stdbool.h>
#include <math.h>

char b2u(const bool bits[], char len);
char b2t(const bool bits[], char len);

int main() {
    char hex[] = {
            'A',
            '1',
            'B',
            '2',
            '7',
            'C',
    };
    bool arr[6][4] = {
            {true, false, true, false},
            {false, false, false, true},
            {true, false, true, true},
            {false, false, true, false},
            {false, true, true, true},
            {true, true, false, false}
    };

    for (int i = 0; i < 6; ++i) {
        printf("0x%c ", hex[i]);
        printf("%d\t", b2u(arr[i], 4));
        printf("%d\n", b2t(arr[i], 4));
    }

    return 0;
}

char b2u(const bool bits[], char len) {
    char result = 0;
    printf("[ ");
    for (char i = 0; i < len; ++i) {
        printf("%d ", bits[i]);
        result += bits[i] * pow(2, len - 1 - i);
    }
    printf("]\t");

    return result;
}

char b2t(const bool bits[], char len) {
    char result = -bits[0] * pow(2, len - 1);
    for (char i = 1; i < len; ++i) {
        result += bits[i] * pow(2, len - 1 - i);
    }

    return result;
}
