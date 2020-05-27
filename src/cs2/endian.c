#include <stdio.h>

typedef unsigned char *bytePointer;

void showInt(int x);
void showFloat(float x);
void showPointer(void *x);

int main() {
    int num = 12345;
    showInt(num);

    int i = 0x01234567; // 19088743
    showInt(i); // 67 45 23 01 => little endian
    printf("pointer of i: %p\n", &i);
    showPointer(&i);

    float pi = 3.14;
    showFloat(pi);

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
