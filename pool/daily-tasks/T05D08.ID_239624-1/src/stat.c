#include <stdio.h>

#define NMAX 10

int input(int* a, int* n);
void output(int* a, int n);
int max(int* a, int n);
int min(int* a, int n);
double mean(int* a, int n);
double variance(int* a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 0) {
        printf("n/a\n");
        return 0;
    }

    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int* a, int* n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) return 0;
    for (int* p = a; p < a + *n; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    return 1;
}

void output(int* a, int n) {
    for (int* p = a; p < a + n; p++) {
        printf("%d%s", *p, (p < a + n - 1) ? " " : "");
    }
    printf("\n");
}

int max(int* a, int n) {
    int res = *a;
    for (int* p = a + 1; p < a + n; p++) {
        if (*p > res) res = *p;
    }
    return res;
}

int min(int* a, int n) {
    int res = *a;
    for (int* p = a + 1; p < a + n; p++) {
        if (*p < res) res = *p;
    }
    return res;
}

double mean(int* a, int n) {
    double sum = 0;
    for (int* p = a; p < a + n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(int* a, int n) {
    double m = mean(a, n);
    double v_sum = 0;
    for (int* p = a; p < a + n; p++) {
        v_sum += (*p - m) * (*p - m);
    }
    return v_sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f\n", max_v, min_v, mean_v, variance_v);
}