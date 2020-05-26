#include <stdio.h>

char * getBinary(char hex);

int main() {
    // char str[] = getBinary('1');
    printf("%s", getBinary('1'));

    return 0;
}

char * getBinary(char hex) {
    switch (hex)
    {
    case '0':
        return "0000";
        break;
    case '1':
        return "0001";
        break;
    default:
        return "";
        break;
    }
}
