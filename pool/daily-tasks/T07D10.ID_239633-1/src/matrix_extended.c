#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int fill(int** matrix, int n, int m);
void output(int** matrix, int n, int m);
void find_max_rows(int** matrix, int n, int m);
void find_min_cols(int** matrix, int n, int m);

int main() {
    int n, m, type;
    if (scanf("%d", &type) != 1 || type < 1 || type > 4 || scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("n/a");
        return 0;
    }

    int** ptr_rows = NULL;
    int* data_block = NULL;

    if (type == 1) {
        if (n > MAX_SIZE || m > MAX_SIZE) {
            printf("n/a");
            return 0;
        }
        static int static_data[MAX_SIZE][MAX_SIZE];
        ptr_rows = malloc(n * sizeof(int*));
        if (!ptr_rows) {
            printf("n/a");
            return 0;
        }
        for (int i = 0; i < n; i++) ptr_rows[i] = static_data[i];
    } else if (type == 2) {
        ptr_rows = malloc(n * sizeof(int*));
        data_block = malloc(n * m * sizeof(int));
        if (!ptr_rows || !data_block) {
            printf("n/a");
            free(ptr_rows);
            free(data_block);
            return 0;
        }
        for (int i = 0; i < n; i++) ptr_rows[i] = data_block + i * m;
    } else if (type == 3) {
        ptr_rows = malloc(n * sizeof(int*));
        if (!ptr_rows) {
            printf("n/a");
            return 0;
        }
        for (int i = 0; i < n; i++) {
            ptr_rows[i] = malloc(m * sizeof(int));
            if (!ptr_rows[i]) {
                printf("n/a");
                return 0;
            }
        }
    } else if (type == 4) {
        ptr_rows = malloc(n * sizeof(int*) + n * m * sizeof(int));
        if (!ptr_rows) {
            printf("n/a");
            return 0;
        }
        int* start = (int*)(ptr_rows + n);
        for (int i = 0; i < n; i++) ptr_rows[i] = start + i * m;
    }

    if (fill(ptr_rows, n, m)) {
        output(ptr_rows, n, m);
        printf("\n");
        find_max_rows(ptr_rows, n, m);
        printf("\n");
        find_min_cols(ptr_rows, n, m);
    } else {
        printf("n/a");
    }

    if (type == 3 && ptr_rows) {
        for (int i = 0; i < n; i++) free(ptr_rows[i]);
    }
    if (type == 2) free(data_block);
    free(ptr_rows);

    return 0;
}

int fill(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &matrix[i][j]) != 1) return 0;
    return 1;
}

void output(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d%s", matrix[i][j], (j < m - 1) ? " " : "");
        }
        if (i < n - 1) printf("\n");
    }
}

void find_max_rows(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] > max) max = matrix[i][j];
        }
        printf("%d%s", max, (i < n - 1) ? " " : "");
    }
}

void find_min_cols(int** matrix, int n, int m) {
    for (int j = 0; j < m; j++) {
        int min = matrix[0][j];
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        printf("%d%s", min, (j < m - 1) ? " " : "");
    }
}