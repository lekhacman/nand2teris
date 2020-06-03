#include <stdio.h>
#include <limits.h>

//int tadd_ok(int x, int y) {
//    long sum = ((long ) x) + ((long) y);
//    return !(sum > INT_MAX || sum < INT_MIN); // return 1 if ok
//}

int tadd_ok(int x, int y) {
    int sum = x + y;
    if (x >= 0 && y >= 0 && sum < 0) {
        return 0;
    } else if (x < 0 && y < 0 && sum >= 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    printf("ok? %d\n", tadd_ok(2147483647, 2));
    printf("ok? %d\n", tadd_ok(1, 2));
    printf("ok? %d\n", tadd_ok(-2147483648, -2));
}
