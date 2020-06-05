#include <stdio.h>
#include <math.h>

#define E_SIZE 3
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
    const int totalcases = 32;
    const char size = E_SIZE + F_SIZE;
    char cases[totalcases][size] = {
            {0,0,0,0,0},
            {0,0,0,0,1},
            {0,0,0,1,0},
            {0,0,0,1,1},
            {0,0,1,0,0},
            {0,0,1,0,1},
            {0,0,1,1,0},
            {0,0,1,1,1},
            {0,1,0,0,0},
            {0,1,0,0,1},
            {0,1,0,1,0},
            {0,1,0,1,1},
            {0,1,1,0,0},
            {0,1,1,0,1},
            {0,1,1,1,0},
            {0,1,1,1,1},
            {1,0,0,0,0},
            {1,0,0,0,1},
            {1,0,0,1,0},
            {1,0,0,1,1},
            {1,0,1,0,0},
            {1,0,1,0,1},
            {1,0,1,1,0},
            {1,0,1,1,1},
            {1,1,0,0,0},
            {1,1,0,0,1},
            {1,1,0,1,0},
            {1,1,0,1,1},
            {1,1,1,0,0},
            {1,1,1,0,1},
            {1,1,1,1,0},
            {1,1,1,1,1},
    };
    char bias = pow(2, E_SIZE - 1) - 1;
    char maxE = pow(2, E_SIZE) - 1;
    printf("Bias: %d\n", bias);
    printf("Max e: %d\n", maxE);

    printf("Bits\te\tE\t2e\t\t\tf\t\t\tM\t\t\tV\n");
    float v = 0;
    for (int i = 0; i < totalcases; ++i) {
        showBits(cases[i], size);

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
            printf("_\t_\t\t\t_\t\t\t_\t\t\t");
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
        float p2 = pow(2, power);
        printf("%f\t", p2);
        printf("%f\t", frac);
        printf("%f\t", m);
        printf("%f\n", m * p2);
    }
}
