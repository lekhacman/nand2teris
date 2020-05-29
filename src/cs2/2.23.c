#include <stdio.h>

int fn1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fn2(unsigned word) {
    return ((int) word << 24) >> 24;
}

int main() {
    int words[] = {
            0x00000076,// 118	        118 118
            0x87654321,// -2023406815	33	33
            0x000000C9,// 201	        201	-55
            0xEDCBA987,// -305419897	135	-121
    };

    for (int i = 0; i < 4; ++i) {
        printf("%d\t%d\t%d\n", words[i], fn1(words[i]), fn2(words[i]));
    }

    int x = 53191;
    printf("x: %d\n", x);
    printf("hex: %x\n", x);
    short sx = (short) x;
    printf("sx: %d\n", sx);
    printf("hex: %x\n", sx);
    int y = sx;
    printf("y: %d\n", y);
    printf("hex: %x\n", y);
}

//f1    0000 0076 8765 4321 0000 00C9 EDCB A987
//      7600 0000 2100 0000 C900 0000 8700 0000 (shift left 6 hex)
//      0000 0076 0000 0021 0000 00C9 0000 0087 (shift right 6 hex)
//      0000 0076 0000 0021 0000 00C9 0000 0087 (cast int)

//f2    0000 0076 8765 4321 0000 00C9 EDCB A987
//      7600 0000 2100 0000 C900 0000 8700 0000 (shift left 6 hex)
//      7600 0000 2100 0000 C900 0000 8700 0000 (cast int)
//      0000 0076 0000 0021 FFFF FFC9 FFFF FF87 (shift right 6 hex)
