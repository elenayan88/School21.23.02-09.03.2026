#include <stdio.h>

int main(void) {
    float x;
    float y;

    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a\n");
        return 1;
    }

    float res = x * x + y * y;

    if (res <= 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }

    return 0;
}