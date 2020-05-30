#include <stdio.h>
#include <math.h>

unsigned char hexToDec(char hex) {
    switch (hex)
    {
        case 0:
        case '0':
            return 0;
        case 1:
        case '1':
            return 1;
        case 2:
        case '2':
            return 2;
        case 3:
        case '3':
            return 3;
        case 4:
        case '4':
            return 4;
        case 5:
        case '5':
            return 5;
        case 6:
        case '6':
            return 6;
        case 7:
        case '7':
            return 7;
        case 8:
        case '8':
            return 8;
        case 9:
        case '9':
            return 9;
        case 'A':
        case 'a':
            return 10;
        case 'B':
        case 'b':
            return 11;
        case 'C':
        case 'c':
            return 12;
        case 'D':
        case 'd':
            return 13;
        case 'E':
        case 'e':
            return 14;
        case 'F':
        case 'f':
            return 15;
        default:
            return hex;
    }
}

char decToHex(char decimal) {
    switch (decimal)
    {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'a';
        case 11:
            return 'b';
        case 12:
            return 'c';
        case 13:
            return 'd';
        case 14:
            return 'e';
        case 15:
            return 'f';
        default:
            return decimal;
    }
}

unsigned char negate(unsigned char decimal, char size) {
    if (decimal == 0) {
        return decimal;
    } else {
        return ((unsigned char) pow(2, size)) - decimal;
    }
}

int main() {
    char list[] = {'1', '4', '7', 'A', 'E'};

    printf("hex\tdecimal\tdecimal\thex\n");
    for (int i = 0; i < 5; ++i) {
        char c = list[i];
        unsigned char decimal = hexToDec(c);
        unsigned char negation = negate(decimal, 4);
        printf("%c\t%d\t\t%d\t\t%c\n", c, decimal, negation, decToHex((signed char) negation));
    }
}
