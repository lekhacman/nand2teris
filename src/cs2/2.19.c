#include <stdio.h>
#include <math.h>

int t2u(char t, char w);

int main() {
    char list[] = {-1, -5, -6, -4, 1, 8};

    for (int i = 0; i < 6; ++i) {
        // 4 bits => complement = pow(2, 4) = 16
        printf("%d\t%d\n", list[i], t2u(list[i], 4) );
    }
}

int t2u(char t, char w) {
    return t >= 0 ? t : t + pow(2, w);
}
