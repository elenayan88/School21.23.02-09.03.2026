#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int* a, int* n);
double mean(int* a, int n);
double variance(int* a, int n);
int search(int* a, int n, double m, double v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 0) {
        printf("n/a\n");
        return 0;
    }

    double m = mean(data, n);
    double v = variance(data, n);

    printf("%d\n", search(data, n, m, v));

    return 0;
}

int input(int* a, int* n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) return 0;
    for (int* p = a; p < a + *n; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    return 1;
}

double mean(int* a, int n) {
    double sum = 0;
    for (int* p = a; p < a + n; p++) sum += *p;
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

int search(int* a, int n, double m, double v) {
    double sigma = sqrt(v);
    int result = 0;

    for (int* p = a; p < a + n; p++) {
        if (*p % 2 == 0 && *p >= m && *p <= m + 3 * sigma && *p != 0) {
            result = *p;
            break;
        }
    }
    return result;
}