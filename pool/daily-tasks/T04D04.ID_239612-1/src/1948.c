#include <stdio.h>

int find_max_prime_divisor(int a);
int get_remainder(int a, int b);
int is_prime(int a);

int main(void) {
  int divident;
  if (scanf("%d", &divident) != 1) {
    printf("n/a\n");
    return 1;
  }

  int abs_divident = divident < 0 ? -divident : divident;
  if (abs_divident < 2) {
    printf("n/a\n");
    return 1;
  }

  int divisor = find_max_prime_divisor(abs_divident);
  printf("%d\n", divisor);

  return 0;
}

int find_max_prime_divisor(int a) {
  for (int divider = a; divider >= 2; divider--) {
    int remainder = get_remainder(a, divider);
    if (remainder == 0 && is_prime(divider)) {
      return divider;
    }
  }

  return a;
}

int get_remainder(int a, int b) {
  if (b == 0) {
    return -1;
  }

  int abs_a = a < 0 ? -a : a;
  int abs_b = b < 0 ? -b : b;

  int result = abs_a;

  while (result >= abs_b) {
    result = result - abs_b;
  }

  return result;
}
int is_prime(int a) {
  if (a < 2) {
    return 0;
  }

  for (int i = 2; i < a; i++) {
    int remainder = get_remainder(a, i);
    if (remainder == 0) {
      return 0;
    }
  }

  return 1;
}