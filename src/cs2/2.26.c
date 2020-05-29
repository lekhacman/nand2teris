#include <stdio.h>
#include <string.h>

int strlonger(char *s, char *t) {
    printf("len(s): %lu\n", strlen(s));
    printf("len(t): %lu\n", strlen(t));
    // size_t is an unsigned long type while 0 is int by default
//    size_t prod = strlen(s) - strlen(t);
//    printf("prod hex = 0x%zx\n", prod);

    return strlen(s) > strlen(t);
}

int main() {
    int x = strlonger("abu", "abcd");

    printf("result = %d\n", x);
}
