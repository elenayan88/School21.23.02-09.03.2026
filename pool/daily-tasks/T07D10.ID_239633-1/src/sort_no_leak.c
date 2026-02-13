#include <stdio.h>
#include <stdlib.h>

int input(int** a, int* n);
void sort(int* a, int n);
void output(int* a, int n);

int main() {
    int* data = NULL;
    int n = 0;

    if (input(&data, &n) == 0) {
        printf("n/a");
        if (data != NULL) {
            free(data);
        }
        return 0;
    }

    sort(data, n);
    output(data, n);

    free(data);
    return 0;
}

int input(int** a, int* n) {
    if (scanf("%d", n) != 1 || *n <= 0) return 0;

    *a = (int*)malloc((*n) * sizeof(int));
    if (*a == NULL) return 0;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", (*a) + i) != 1) {
            return 0;
        }
    }

    char term;
    if (scanf("%c", &term) == 1 && term != '\n' && term != ' ' && term != '\0') {
        return 0;
    }

    return 1;
}

void sort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], (i < n - 1) ? " " : "");
    }
}