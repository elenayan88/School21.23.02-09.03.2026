#include <stdio.h>
#include <stdlib.h>

int input(int*** matrix, int* n, int* m, int** data_block);
void output(int** matrix, int n, int m);
void sort_matrix(int** matrix, int n, int m);
long long get_sum(int* row, int m);
void free_mem(int** matrix, int* data_block);

int main() {
    int n, m;
    int** matrix = NULL;
    int* data_block = NULL;

    int type;
    if (scanf("%d", &type) != 1) {
        printf("n/a");
        return 0;
    }

    if (input(&matrix, &n, &m, &data_block) == 0) {
        printf("n/a");
        free_mem(matrix, data_block);
        return 0;
    }

    sort_matrix(matrix, n, m);
    output(matrix, n, m);

    free_mem(matrix, data_block);
    return 0;
}

int input(int*** matrix, int* n, int* m, int** data_block) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) return 0;

    *matrix = (int**)malloc((*n) * sizeof(int*));
    *data_block = (int*)malloc((*n) * (*m) * sizeof(int));

    if (*matrix == NULL || *data_block == NULL) return 0;

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (*data_block) + i * (*m);
        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &((*matrix)[i][j])) != 1) return 0;
        }
    }
    return 1;
}

long long get_sum(int* row, int m) {
    long long sum = 0;
    for (int j = 0; j < m; j++) {
        sum += row[j];
    }
    return sum;
}

void sort_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (get_sum(matrix[j], m) > get_sum(matrix[j + 1], m)) {
                int* temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
    }
}

void output(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d%s", matrix[i][j], (j < m - 1) ? " " : "");
        }
        if (i < n - 1) printf("\n");
    }
}

void free_mem(int** matrix, int* data_block) {
    if (data_block != NULL) free(data_block);
    if (matrix != NULL) free(matrix);
}