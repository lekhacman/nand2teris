#include <stdio.h>

int main() {
    int n = 14;
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * i;
        printf("n: %d\t", i);
        printf("result: %d\n", result);
    }

    printf("result: %d\n", result);
}
