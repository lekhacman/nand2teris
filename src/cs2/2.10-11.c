#include <stdio.h>
#include <stdbool.h>

// a b xor
// 0 0 0
// 0 1 1
// 1 0 1
// 1 1 0

void reverseArray(int a[], int len);
void printArr(int arr[], int len);

int main() {

    int arrEven[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int arrOdd[] = {1, 2, 3, 4, 5, 6, 7};

    printArr(arrEven, 10);
    reverseArray(arrEven, 10);
    printArr(arrEven, 10);

    printArr(arrOdd, 7);
    reverseArray(arrOdd, 7);
    printArr(arrOdd, 7);

    return 0;
}

void printArr(int arr[], int len) {
    printf("[ ");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

bool isEven(int num) {
    return (num % 2) == 0 ? true : false;
}

void inplaceSwap(int *x, int *y) {
    //              x    y
    //              0101 1001
    *y = *x ^ *y;//      1100
    *x = *x ^ *y;// 1001
    *y = *x ^ *y;//      0101
}

void reverseArray(int a[], int len) {
    int first, last;
    for (first = 0, last = len - 1; first < last; ++first, --last) {
        inplaceSwap(&a[first], &a[last]);
    }
}
