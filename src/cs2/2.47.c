#include <stdio.h>
#include <math.h>

#define SIZE 5
#define E_SIZE 2
#define F_SIZE 2

void showBits(char list[], char len) {
    printf("[");
    for (int i = 0; i < len; ++i) {
        printf("%d", list[i]);
    }
    printf("]\t");
}
char b2u(char bits[], char len) {
    char result = 0;
    for (char i = 0; i < len; ++i) {
        result += bits[i] * pow(2, len - 1 - i);
    }
    return result;
}

float computeFrac(char bits[], char len) {
    float result = 0;
    for (int i = 0; i < len; ++i) {
        result += bits[i] * pow(2, -1 - i);
    }
    return result;
}

int main() {
    char cases[16][4] = {
            {0,0,0,0},
            {0,0,0,1},
            {0,0,1,0},
            {0,0,1,1},
            {0,1,0,0},
            {0,1,0,1},
            {0,1,1,0},
            {0,1,1,1},
            {1,0,0,0},
            {1,0,0,1},
            {1,0,1,0},
            {1,0,1,1},
            {1,1,0,0},
            {1,1,0,1},
            {1,1,1,0},
            {1,1,1,1},
    };
    char bias = pow(2, E_SIZE - 1) - 1;
    char maxE = pow(2, E_SIZE) - 1;
    printf("Bias: %d\n", bias);
    printf("Max e: %d\n", maxE);

    printf("Bits\te\tE\t2e\tf\t\tM\t\tV\n");
    float v = 0;
    for (int i = 0; i < 16; ++i) {
        showBits(cases[i], 4);

        // initialize
        char eBits[E_SIZE];
        for (int j = 0; j < E_SIZE; ++j) {
            eBits[j] = cases[i][j];
        }
        char fBits[F_SIZE];
        for (int k = 0; k < F_SIZE; ++k) {
            fBits[k] = cases[i][E_SIZE + k];
        }

        // Scenarios
        char e = b2u(eBits, E_SIZE);
        char power;
        float frac = computeFrac(fBits, F_SIZE);
        float m;
        printf("%d\t", e);


        if (e == 0) { // Denormalized
            power = 1 - bias;
            printf("%d\t", power);
            m = frac;
        } else if (e == maxE) { // Infinity/NaN
            printf("_\t_\t_\t\t_\t\t");
            char f = b2u(fBits, F_SIZE);
            if (f == 0) {
                printf("Infinity");
            } else {
                printf("NaN");
            }
            printf("\n");
            continue;
        } else { // Normalized
            power = e - bias;
            printf("%d\t", power);
            m = frac + 1;
        }
        char p2 = pow(2, power);
        printf("%d\t", p2);
        printf("%.2f\t", frac);
        printf("%.2f\t", m);
        printf("%.2f\n", m * p2);
    }
}
