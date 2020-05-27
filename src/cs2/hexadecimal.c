#include <stdio.h>
#include <string.h>

int hexToDecimal(char hex);
char * decimalToBinary(int decimal);
char * hexToBinary(char hex[]);

int main() {
    printf("%s", hexToBinary("25b9d2"));

    return 0;
}

char * hexToBinary(char hex[]) {
    char result[sizeof(hex)*4];
    for (int i = 0; i < sizeof(hex); ++i) {

    }
}

int hexToDecimal(char hex) {
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
            return 99;
    }
}

char * decimalToBinary(int decimal) {
    switch (decimal)
    {
        case 0:
            return "0000";
        case 1:
            return "0001";
        case 2:
            return "0010";
        case 3:
            return "0011";
        case 4:
            return "0100";
        case 5:
            return "0101";
        case 6:
            return "0110";
        case 7:
            return "0111";
        case 8:
            return "1000";
        case 9:
            return "1001";
        case 10:
            return "1010";
        case 11:
            return "1011";
        case 12:
            return "1100";
        case 13:
            return "1101";
        case 14:
            return "1110";
        case 15:
            return "1111";
        default:
            return "";
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
