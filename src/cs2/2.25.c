#include <stdio.h>

float sumElements(float a[], unsigned length) {
    float result = 0;
    for (int i = 0; i < length; ++i) {
        result += a[i];
    }

    return result;
}

int main() {
    float a[] = {1, 2};
    float x = sumElements(a, 0);
    printf("%d\n", x);
}
