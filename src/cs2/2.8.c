#include <stdio.h>
#include <stdbool.h>
// operation ~ = ! = not
// operation & = and
// operation | = or
// operation ^ = XOR (exclusive or) = NOT(AND) = NAND CHIP
//          solution    computed
// a        0100 1110
// b        1110 0001
// ~a       1011 0001   1011 0001
// ~b       0001 1110   0001 1110
//a & b     0100 0000   0100 0000
//a | b     1110 1111   1110 1111 x
//a ^ b     1010 1111   1010 1111 x

#define LENGTH 8

typedef bool byte[LENGTH];

void showByte(byte b);

bool nand(bool a, bool b);
void nand8(byte out, const byte a, const byte b);

void not8(byte out, const byte b);
void and8(byte out, const byte a, const byte b);
void or8(byte out, const byte a, const byte b);
void xor8(byte out, const byte a, const byte b);

int main() {
    byte a = {false, true, false, false, true, true, true, false};
    byte b = {true, true, true, false, false, false, false, true};
    printf("a\t\t");
    showByte(a);
    printf("b\t\t");
    showByte(b);

    byte notA, notB, aAndB, aOrB, aXorB;

    not8(notA, a);
    printf("~a\t\t");
    showByte(notA);
    not8(notB, b);
    printf("~b\t\t");
    showByte(notB);

    and8(aAndB, a, b);
    printf("a & b\t");
    showByte(aAndB);

    or8(aOrB, a, b);
    printf("a | b\t");
    showByte(aOrB);

    xor8(aXorB, a, b);
    printf("a ^ b\t");
    showByte(aXorB);
}

void showByte(byte b) {
    printf("[ ");
    for (int i = 0; i < LENGTH; ++i) {
        printf("%d ", b[i]);
    }
    printf("]\n");
}

bool nand(bool a, bool b) {
    return !(a & b);
}

void nand8(byte out, const byte a, const byte b) {
    for (int i = 0; i < LENGTH; ++i) {
        out[i] = nand(a[i], b[i]);
    }
}

void not8(byte out, const byte b) {
    return nand8(out, b, b);
}

void and8(byte out, const byte a, const byte b) {
    byte _nand;
    nand8(_nand, a, b);
    return not8(out, _nand);
}

void or8(byte out, const byte a, const byte b) {
    byte notA, notB;
    not8(notA, a);
    not8(notB, b);

    return nand8(out, notA, notB);
}

void xor8(byte out, const byte a, const byte b) {
    byte notA, notB, notAAndB, notBAndA;
    not8(notA, a);
    not8(notB, b);
    and8(notAAndB, notA, b);
    and8(notBAndA, a, notB);

    return or8(out, notAAndB, notBAndA);
}
