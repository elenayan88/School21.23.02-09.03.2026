#include <stdio.h>

int find_max(int a, int b);

int main() {
    int a, b;

    if (scanf("%d %d", &a, &b) == 2) {
        printf("%d\n", find_max(a, b));
    } else {
        printf("n/a\n");
    }

    return 0;
}

int find_max(int a, int b) { return (a > b) ? a : b; }