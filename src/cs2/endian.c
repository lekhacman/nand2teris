#include <stdio.h>
#include <string.h>

typedef unsigned char *bytePointer;

void showBytes(bytePointer data, size_t len);
void showInt(int x);
void showFloat(float x);
void showPointer(void *x);
void showStr(char *str);

int main() {
    int num = 12345;
    showInt(num);

    int i = 0x01234567; // 19088743
    showInt(i); // 67 45 23 01 => little endian
    printf("pointer of i: %p\n", &i);
    showPointer(&i);

    float pi = 3.0;
    showFloat(pi);

    printf("Problem 2.6\n");
    int i26 = 2607352; // 0x0027c8f8 | 00000000001001111100100011111000
//                                                ********************* 21 bits
//  float     2607352.0   0x4a1f23e0 |   01001010000111110010001111100000
    showInt(i26);
    float f26 = 3510593.0f;
    showFloat(f26); // 0x0445564a | 00000100010001010101011001001010
    double d26 = 3510593.0;
    showBytes((bytePointer) &d26, sizeof(d26));

    showStr("Hello World!");
}

void showBytes(bytePointer data, size_t len) {
    printf("Size: %d bytes\n", len);

    for (int i = 0; i < len; ++i) {
        printf("%.2x ", data[i]);
    }
    printf("\n");
}

void showInt(int x) {
    showBytes((bytePointer) &x, sizeof(int));
}

void showFloat(float x) {
    showBytes((bytePointer) &x, sizeof(float));
}

void showPointer(void *x) {
    showBytes((bytePointer) &x, sizeof(void *));
}

void showStr(char *str) {
    showBytes((bytePointer) str, strlen(str));
}
