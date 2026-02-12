#include <stdio.h>

#define NMAX 10

int input(int* a, int* n, int* c);
void output(int* a, int n);
void shift(int* a, int n, int c);

int main() {
    int n, c, data[NMAX];

    if (input(data, &n, &c) == 0) {
        printf("n/a\n");
        return 0;
    }

    shift(data, n, c);
    output(data, n);

    return 0;
}

int input(int* a, int* n, int* c) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) return 0;
    for (int* p = a; p < a + *n; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    if (scanf("%d", c) != 1) return 0;
    return 1;
}

void output(int* a, int n) {
    for (int* p = a; p < a + n; p++) {
        printf("%d%s", *p, (p < a + n - 1) ? " " : "");
    }
    printf("\n");
}

void shift(int* a, int n, int c) {
    c = c % n;
    if (c < 0) c = n + c;

    int temp[NMAX];
    for (int i = 0; i < n; i++) {
        int new_index = (i - c + n) % n;
        temp[new_index] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}