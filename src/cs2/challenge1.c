#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    printf("arg[1]: %s\n", argv[1]);
    printf("arg[2]: %s\n", argv[2]);
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    printf("sum: %d\n", n1 + n2);

    int x = 0;
    int y = 0;
    printf("Input any 2 numbers: ");
    scanf("%d,%d", &x, &y);
    int mod = x%y;
    
    printf("Sum: %d\n", x + y);
    printf("Diff: %d\n", x - y);
    printf("Product: %d\n", x * y);
    printf("Quotient: %f\n", (float) x / y);
    printf("Modulus: %d\n", mod);
    printf("Modulus * 5: %d\n", mod * 5);

    return 0;
}
