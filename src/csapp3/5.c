#include <stdio.h>
//xp %rdi
//yp %rsi
//zp %rdx

void decode1(long *xp, long *yp, long *zp) {
    long r8 = *xp;
//    long rcx = *yp;
//    long rax = *zp;
    *xp = *zp;
    *zp = *yp;
    *yp = r8;

//    *yp = r8; // yp = xp
//    *zp = rcx; // zp = yp
//    *xp = rax; // xp = zp
}

int main() {
    long x = 1;
    long y = 2;
    long z = 3;
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    decode1(&x, &y, &z);
    printf("x: %d, y: %d, z: %d\n", x, y, z);
}
