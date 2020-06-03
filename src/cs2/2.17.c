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
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            'a',
            'b',
            'c',
            'd',
            'e',
            'f'
    };
    bool arr[22][4] = {
            {true, false, true, false},  // A
            {false, false, false, true}, // 1
            {true, false, true, true},   // B
            {false, false, true, false}, // 2
            {false, true, true, true},   // 7
            {true, true, false, false},  // C
            {false, false, false, false},// 0
            {false, false, false, true}, // 1
            {false, false, true, false}, // 2
            {false, false, true, true},  // 3
            {false, true, false, false}, // 4
            {false, true, false, true},  // 5
            {false, true, true, false},  // 6
            {false, true, true, true},   // 7
            {true, false, false, false}, // 8
            {true, false, false, true},  // 9
            {true, false, true, false},  // A
            {true, false, true, true},   // B
            {true, true, false, false},  // C
            {true, true, false, true},   // D
            {true, true, true, false},   // E
            {true, true, true, true},   // F
    };
    printf("hex\tbinary\t\tu\t2's c\n");
    for (int i = 0; i < 22; ++i) {
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
