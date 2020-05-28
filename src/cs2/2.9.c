#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define PIXEL_LENGTH 3

typedef bool pixel[PIXEL_LENGTH];

struct node {
    char color[10];
    struct node *left;
    struct node *right;
};

void create(struct node * tree) {
    struct node black;
    strcpy(black.color, "black");
    struct node blue;
    strcpy(blue.color, "blue");
    struct node green;
    strcpy(green.color, "green");
    struct node cyan;
    strcpy(cyan.color, "cyan");
    struct node red;
    strcpy(red.color, "red");
    struct node magenta;
    strcpy(magenta.color, "magenta");
    struct node yellow;
    strcpy(yellow.color, "yellow");
    struct node white;
    strcpy(white.color, "white");

    struct node r0, r1, rg00, rg01;


//    rg00.left = &black;
//    rg00.right = &blue;
//
//    r0.left = &rg00;
//    r0.right = &rg01;

    tree->left = &black;
    tree->right = &blue;

}

void showByte(pixel b);

bool nand(bool a, bool b);


void nand3(pixel out, const pixel a, const pixel b);
void not3(pixel out, const pixel in);
void and3(pixel out, const pixel a, const pixel b);
void or3(pixel out, const pixel a, const pixel b);
void xor3(pixel out, const pixel a, const pixel b);

int main() {

    struct node colors;
    create(&colors);
    printf("%s\n", colors.left->color);
    return 0;
}

void showByte(pixel b) {
    printf("[ ");
    for (int i = 0; i < PIXEL_LENGTH; ++i) {
        printf("%d ", b[i]);
    }
    printf("]\n");
}

bool nand(bool a, bool b) {
    return !(a & b);
}

void nand3(pixel out, const pixel a, const pixel b) {
    for (int i = 0; i < PIXEL_LENGTH; ++i) {
        out[i] = nand(a[i], b[i]);
    }
}

void not3(pixel out, const pixel in) {
    return nand3(out, in, in);
}

void and3(pixel out, const pixel a, const pixel b) {
    pixel _nand;
    nand3(_nand, a, b);
    return not3(out, _nand);
}

void or3(pixel out, const pixel a, const pixel b) {
    pixel notA, notB;
    not3(notA, a);
    not3(notB, b);

    return nand3(out, notA, notB);
}

void xor3(pixel out, const pixel a, const pixel b) {
    pixel notA, notB, notAAndB, notBAndA;
    not3(notA, a);
    not3(notB, b);
    and3(notAAndB, notA, b);
    and3(notBAndA, a, notB);

    return or3(out, notAAndB, notBAndA);
}
