#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void output(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d%s", matrix[i][j], (j < m - 1) ? " " : "");
        }
        if (i < n - 1) printf("\n");
    }
}

int fill(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &matrix[i][j]) != 1) return 0;
    return 1;
}

int main() {
    int n, m, type;
    if (scanf("%d", &type) != 1 || type < 1 || type > 4 || scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("n/a");
        return 0;
    }

    if (type == 1) {
        if (n > MAX_SIZE || m > MAX_SIZE) {
            printf("n/a");
            return 0;
        }
        int data[MAX_SIZE][MAX_SIZE];
        int* ptr_rows[MAX_SIZE];
        for (int i = 0; i < n; i++) ptr_rows[i] = data[i];
        if (fill(ptr_rows, n, m))
            output(ptr_rows, n, m);
        else
            printf("n/a");

    } else if (type == 2) {
        int** ptr_rows = malloc(n * sizeof(int*));
        int* data = malloc(n * m * sizeof(int));
        if (!ptr_rows || !data) {
            printf("n/a");
            free(ptr_rows);
            free(data);
            return 0;
        }
        for (int i = 0; i < n; i++) ptr_rows[i] = data + i * m;
        if (fill(ptr_rows, n, m))
            output(ptr_rows, n, m);
        else
            printf("n/a");
        free(data);
        free(ptr_rows);

    } else if (type == 3) {
        int** ptr_rows = malloc(n * sizeof(int*));
        if (!ptr_rows) {
            printf("n/a");
            return 0;
        }
        for (int i = 0; i < n; i++) ptr_rows[i] = malloc(m * sizeof(int));
        if (fill(ptr_rows, n, m))
            output(ptr_rows, n, m);
        else
            printf("n/a");
        for (int i = 0; i < n; i++) free(ptr_rows[i]);
        free(ptr_rows);

    } else if (type == 4) {
        int** ptr_rows = malloc(n * sizeof(int*) + n * m * sizeof(int));
        if (!ptr_rows) {
            printf("n/a");
            return 0;
        }
        int* data = (int*)(ptr_rows + n);
        for (int i = 0; i < n; i++) ptr_rows[i] = data + i * m;
        if (fill(ptr_rows, n, m))
            output(ptr_rows, n, m);
        else
            printf("n/a");
        free(ptr_rows);
    }
    return 0;
}