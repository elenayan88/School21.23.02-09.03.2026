#include <math.h>
#include <stdio.h>

int main() {
    double start = -M_PI;
    double end = M_PI;
    double step = (end - start) / 41.0;

    for (int i = 0; i < 42; i++) {
        double x = start + (double)i * step;

        double agnesi = 1.0 / (1.0 + x * x);

        double lemn_inner = sqrt(1.0 + 4.0 * x * x) - x * x - 1.0;

        double hyperbola = 1.0 / (x * x);

        printf("%.7f | %.7f | ", x, agnesi);

        if (lemn_inner >= 0) {
            printf("%.7f | ", sqrt(lemn_inner));
        } else {
            printf("- | ");
        }

        if (x != 0) {
            printf("%.7f\n", hyperbola);
        } else {
            printf("-\n");
        }
    }

    return 0;
}