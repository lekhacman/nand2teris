#include <stdio.h>

typedef unsigned char *bytePointer;

void showBytes(bytePointer data, size_t len);

int main() {
    int num = 12345;
    showBytes((bytePointer) &num, sizeof(int));
}

void showBytes(bytePointer data, size_t len) {
    for (int i = 0; i < len; ++i) {
        printf("%.2x ", data[i]);
    }
    printf("\n");
}

