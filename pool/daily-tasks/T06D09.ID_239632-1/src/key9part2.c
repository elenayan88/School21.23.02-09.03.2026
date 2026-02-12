#include <stdio.h>

#define LEN 100

int input(int* buffer, int* length);
void output(int* buffer, int length);
void sum(int* buff1, int len1, int* buff2, int len2, int* result, int* result_length);
void sub(int* buff1, int len1, int* buff2, int len2, int* result, int* result_length);
int compare(int* buff1, int len1, int* buff2, int len2);

int main() {
    int n1[LEN], n2[LEN], len1, len2;
    int res_sum[LEN + 1], res_sub[LEN];
    int sum_len, sub_len;

    if (!input(n1, &len1) || !input(n2, &len2)) {
        printf("n/a\n");
        return 0;
    }

    sum(n1, len1, n2, len2, res_sum, &sum_len);
    output(res_sum, sum_len);

    if (compare(n1, len1, n2, len2) < 0) {
        printf("n/a\n");
    } else {
        sub(n1, len1, n2, len2, res_sub, &sub_len);
        output(res_sub, sub_len);
    }

    return 0;
}

int input(int* buffer, int* length) {
    int count = 0;
    char c;
    while (scanf("%d%c", &buffer[count], &c) == 2) {
        if (buffer[count] < 0 || buffer[count] > 9) return 0;
        count++;
        if (c == '\n' || count >= LEN) break;
    }
    *length = count;
    return (count > 0);
}

void output(int* buffer, int length) {
    int start = 0;
    // Убираем ведущие нули, если это не единственная цифра
    while (start < length - 1 && buffer[start] == 0) start++;
    for (int i = start; i < length; i++) {
        printf("%d%s", buffer[i], (i < length - 1) ? " " : "");
    }
    printf("\n");
}

int compare(int* buff1, int len1, int* buff2, int len2) {
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    for (int i = 0; i < len1; i++) {
        if (buff1[i] > buff2[i]) return 1;
        if (buff1[i] < buff2[i]) return -1;
    }
    return 0;
}

void sum(int* buff1, int len1, int* buff2, int len2, int* result, int* result_length) {
    int i = len1 - 1, j = len2 - 1, k = 0, carry = 0;
    int temp[LEN + 1];

    while (i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? buff1[i--] : 0;
        int d2 = (j >= 0) ? buff2[j--] : 0;
        int s = d1 + d2 + carry;
        temp[k++] = s % 10;
        carry = s / 10;
    }
    *result_length = k;
    for (int m = 0; m < k; m++) result[m] = temp[k - 1 - m];
}

void sub(int* buff1, int len1, int* buff2, int len2, int* result, int* result_length) {
    int i = len1 - 1, j = len2 - 1, k = 0, borrow = 0;
    int temp[LEN];

    while (i >= 0) {
        int d1 = buff1[i--];
        int d2 = (j >= 0) ? buff2[j--] : 0;
        int s = d1 - d2 - borrow;
        if (s < 0) {
            s += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp[k++] = s;
    }
    *result_length = k;
    for (int m = 0; m < k; m++) result[m] = temp[k - 1 - m];
}