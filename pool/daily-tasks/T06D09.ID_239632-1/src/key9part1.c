#include <stdio.h>

#define NMAX 10

int input(int* buffer, int* length);
void output(int* buffer, int length);
int sum_numbers(int* buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

int main() {
    int length, buffer[NMAX], result_buffer[NMAX];

    if (input(buffer, &length) == 0) {
        printf("n/a\n");
        return 0;
    }

    int sum = sum_numbers(buffer, length);

    // Если четных элементов не было, сумма будет 0.
    // По условию при ошибке/отсутствии четных выводим n/a.
    if (sum == 0) {
        printf("n/a\n");
        return 0;
    }

    int result_length = find_numbers(buffer, length, sum, result_buffer);

    printf("%d\n", sum);
    output(result_buffer, result_length);

    return 0;
}

int input(int* buffer, int* length) {
    if (scanf("%d", length) != 1 || *length <= 0 || *length > NMAX) return 0;
    for (int* p = buffer; p < buffer + *length; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    return 1;
}

void output(int* buffer, int length) {
    for (int* p = buffer; p < buffer + length; p++) {
        printf("%d%s", *p, (p < buffer + length - 1) ? " " : "");
    }
    printf("\n");
}

/* Находим сумму четных ЧИСЕЛ (делится на 2 без остатка) */
int sum_numbers(int* buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

/* Формируем массив из элементов, на которые сумма делится нацело */
int find_numbers(int* buffer, int length, int number, int* numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        // Проверка на деление на 0 на всякий случай, хотя в Си это важно
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    return count;
}