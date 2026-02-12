#include <stdio.h>

#define N 10

int input(int* a);
void sort(int* a);
void output(int* a);

int main() {
    int data[N];

    if (input(data) == 0) {
        printf("n/a\n");
        return 0;
    }

    sort(data);
    output(data);

    return 0;
}

int input(int* a) {
    for (int* p = a; p < a + N; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    char term;
    if (scanf("%c", &term) == 1 && term != '\n' && term != ' ' && term != '\0') {
        return 0;
    }
    return 1;
}

void sort(int* a) {
    for (int i = 0; i < N - 1; i++) {
        for (int* p = a; p < a + N - 1 - i; p++) {
            if (*p > *(p + 1)) {
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
    }
}

void output(int* a) {
    for (int* p = a; p < a + N; p++) {
        printf("%d%s", *p, (p < a + N - 1) ? " " : "");
    }
}