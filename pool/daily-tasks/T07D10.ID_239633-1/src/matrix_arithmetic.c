#include <stdio.h>
#include <stdlib.h>

int input(int*** matrix, int* n, int* m);
void output(int** matrix, int n, int m);
void free_matrix(int** matrix, int n);

int sum(int** matrix_first, int n_first, int m_first, int** matrix_second, int n_second, int m_second,
        int*** matrix_result, int* n_result, int* m_result);
int mul(int** matrix_first, int n_first, int m_first, int** matrix_second, int n_second, int m_second,
        int*** matrix_result, int* n_result, int* m_result);
int transpose(int** matrix, int n, int m, int*** matrix_result, int* n_result, int* m_result);

int main() {
    int op = 0, n1 = 0, m1 = 0, n2 = 0, m2 = 0, n_res = 0, m_res = 0;
    int **mat1 = NULL, **mat2 = NULL, **res = NULL;

    if (scanf("%d", &op) != 1 || op < 1 || op > 3) {
        printf("n/a");
        return 0;
    }

    if (!input(&mat1, &n1, &m1)) {
        printf("n/a");
        free_matrix(mat1, n1);
        return 0;
    }

    int success = 0;
    if (op == 1 || op == 2) {
        if (!input(&mat2, &n2, &m2)) {
            printf("n/a");
            free_matrix(mat1, n1);
            free_matrix(mat2, n2);
            return 0;
        }
        if (op == 1)
            success = sum(mat1, n1, m1, mat2, n2, m2, &res, &n_res, &m_res);
        else
            success = mul(mat1, n1, m1, mat2, n2, m2, &res, &n_res, &m_res);
    } else if (op == 3) {
        success = transpose(mat1, n1, m1, &res, &n_res, &m_res);
    }

    if (success) {
        output(res, n_res, m_res);
    } else {
        printf("n/a");
    }

    free_matrix(mat1, n1);
    free_matrix(mat2, n2);
    free_matrix(res, n_res);

    return 0;
}

int input(int*** matrix, int* n, int* m) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) return 0;

    *matrix = (int**)malloc((*n) * sizeof(int*));
    if (!(*matrix)) return 0;

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int*)malloc((*m) * sizeof(int));
        if (!(*matrix)[i]) return 0;
        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) return 0;
        }
    }
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

void free_matrix(int** matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            if (matrix[i] != NULL) free(matrix[i]);
        }
        free(matrix);
    }
}

int sum(int** matrix_first, int n_first, int m_first, int** matrix_second, int n_second, int m_second,
        int*** matrix_result, int* n_result, int* m_result) {
    if (n_first != n_second || m_first != m_second) return 0;

    *n_result = n_first;
    *m_result = m_first;
    *matrix_result = (int**)malloc((*n_result) * sizeof(int*));

    for (int i = 0; i < *n_result; i++) {
        (*matrix_result)[i] = (int*)malloc((*m_result) * sizeof(int));
        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return 1;
}

int transpose(int** matrix, int n, int m, int*** matrix_result, int* n_result, int* m_result) {
    *n_result = m;
    *m_result = n;
    *matrix_result = (int**)malloc((*n_result) * sizeof(int*));

    for (int i = 0; i < *n_result; i++) {
        (*matrix_result)[i] = (int*)malloc((*m_result) * sizeof(int));
        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = matrix[j][i];
        }
    }
    return 1;
}

int mul(int** matrix_first, int n_first, int m_first, int** matrix_second, int n_second, int m_second,
        int*** matrix_result, int* n_result, int* m_result) {
    if (m_first != n_second) return 0;

    *n_result = n_first;
    *m_result = m_second;
    *matrix_result = (int**)malloc((*n_result) * sizeof(int*));

    for (int i = 0; i < *n_result; i++) {
        (*matrix_result)[i] = (int*)malloc((*m_result) * sizeof(int));
        for (int j = 0; j < *m_result; j++) {
            (*matrix_result)[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                (*matrix_result)[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    return 1;
}