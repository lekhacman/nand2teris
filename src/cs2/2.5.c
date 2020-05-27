#include <stdio.h>

typedef unsigned char *bytePointer;
void showBytes(bytePointer, size_t);

int main() {
    int a = 0x12345678;
    bytePointer p = (bytePointer) &a;
                         // little     big endian
    showBytes(p, 1); // 78         12
    showBytes(p, 2); // 78 56      12 34
    showBytes(p, 3); // 78 56 34   12 34 56

}

void showBytes(bytePointer data, size_t len) {
    for (int i = 0; i < len; ++i) {
        printf("%.2x ", data[i]);
    }
    printf("\n");
}
