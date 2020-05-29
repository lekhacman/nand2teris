#include <stdio.h>
#include <string.h>
#include "hexadecimal.h"


int main() {
    char zeroHex[] = "12fe";
    char size = strlen(zeroHex);
    char zero[size][4];
    hexToBinary(zero, zeroHex, size);
    showBinaryArr(zero, size);

    char ex218[10][3] = {
            "2e0",
            "058",
            "028",
            "030",
            "078",
            "088",
            "1f8",
            "008",
            "0c0",
            "048",
    };
    for (int i = 0; i < 10; ++i) {
        char ex218size = 3;
        char b218[ex218size][4];
        hexToBinary(b218, ex218[i], ex218size);
        showBinaryArr(b218, ex218size);
    }

    return 0;
}

void showBinaryArr(char arr[][4], char len) {
    printf("[ ");
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d", arr[i][j]);
        }
        printf(" ");
    }
    printf("]\n");
}

void hexToBinary(char out[][4], const char hex[], const char len) {
    for (int i = 0; i < len; ++i) {
        char decimal = hexToDecimal(hex[i]);
        decimalToBinary(out[i], decimal);
    }
}

char hexToDecimal(char hex) {
    switch (hex)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default:
            return hex;
    }
}

void decimalToBinary(char out[], char decimal) {
    char map[16][4] = {
            {0, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 0, 1, 1},
            {0, 1, 0, 0},
            {0, 1, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 1},
            {1, 0, 1, 0},
            {1, 0, 1, 1},
            {1, 1, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 1, 0},
            {1, 1, 1, 1},
    };
    for (int i = 0; i < 4; ++i) {
        out[i] = map[decimal][i];
    }
}

//int binaryToDecimal(char *fourBits) {
//    struct Map {
//        char bits[4];
//        int deximal;
//    };
//
//    struct Map map0;
//    strcpy(map0.bits, "0000");
//    map0.deximal = 0;
//
//    struct Map map1;
//    strcpy(map1.bits, "0001");
//    map1.deximal = 1;
//
//
//
////    switch (fourBits)
////    {
////        case "0000":
////            return 0;
////        case "0001":
////            return 1;
////        case "0010":
////            return 2;
////        case "0011":
////            return 3;
////        case "0100":
////            return 4;
////        case "0101":
////            return 5;
////        case "0110":
////            return 6;
////        case "0111":
////            return 7;
////        case "1000":
////            return 8;
////        case "1001":
////            return 9;
////        case "1010":
////            return 10;
////        case "1011":
////            return 11;
////        case "1100":
////            return 12;
////        case "1101":
////            return 13;
////        case "1110":
////            return 14;
////        case "1111":
////            return 15;
////        default:
////            return 99;
////    }
//}

//char * hexToBinary(char hex) {
//    switch (hex)
//    {
//    case '0':
//        return "0000";
//    case '1':
//        return "0001";
//    case '2':
//        return "0010";
//    case '3':
//        return "0011";
//    case '4':
//        return "0100";
//    case '5':
//        return "0101";
//    case '6':
//        return "0110";
//    case '7':
//        return "0111";
//    case '8':
//        return "1000";
//    case '9':
//        return "1001";
//    case 'a':
//        return "1010";
//    case 'b':
//        return "1011";
//    case 'c':
//        return "1100";
//    case 'd':
//        return "1101";
//    case 'e':
//        return "1110";
//    case 'f':
//        return "1111";
//    default:
//        return "";
//    }
//}
