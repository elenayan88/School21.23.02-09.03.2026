#include <stdio.h>
#define NMAX 10

int input(int* data, int* n);
void output(int* data, int n);
void squaring(int* data, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 0) {
        printf("n/a\n");
        return 0;
    }

    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int* data, int* n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 0;
    }

    for (int* p = data; p - data < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }

    char c;
    if (scanf("%c", &c) == 1 && c != '\n' && c != ' ' && c != '\0') {
    }

    return 1;
}

void squaring(int* data, int n) {
    for (int* p = data; p - data < n; p++) {
        *p = (*p) * (*p);
    }
}

void output(int* data, int n) {
    for (int* p = data; p - data < n; p++) {
        printf("%d", *p);

        if (p - data < n - 1) {
            printf(" ");
        }
    }
}