#include <stdio.h>
#include <string.h>

int main() {
    const char *m = "mnopqr"; // 6d 6e 6f 70 71 72

    for (int i = 0; i < strlen(m); ++i) {
        printf("%.2x ", m[i]);
    }
}
