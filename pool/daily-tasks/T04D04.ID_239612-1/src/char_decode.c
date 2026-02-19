#include <stdio.h>

int get_mode(int argc, char** argv);
void run(int mode);
void encode();
void decode();

int main(int argc, char** argv) {
    int mode = get_mode(argc, argv);

    if (mode == -1) {
        printf("n/a\n");
        return 0;
    }

    run(mode);

    return 0;
}

/**
 * Проверка режима работы
 * Возвращает один из следующих режимов работы:
 * 0 – кодирование (encode)
 * 1 – декодирование (decode)
 *
 * В случае ошибки парсинга вернет -1
 */
int get_mode(int argc, char** argv) {
    // Проверка передан ли ровно один аргумент
    if (argc != 2) {
        return -1;
    }

    int mode;

    if (argv[1][0] == '0' && argv[1][1] == '\0') {
        mode = 0;
    } else if (argv[1][0] == '1' && argv[1][1] == '\0') {
        mode = 1;
    } else {
        mode = -1;
    }

    return mode;
}

void run(int mode) {
    if (mode == 0) {
        encode();
    }
    if (mode == 1) {
        decode();
    }
}

void encode() {
    char c;
    char space;

    while (scanf("%c%c", &c, &space) == 2 && c != '\n') {
        if (space != ' ' && space != '\n') {
            printf("n/a\n");
            break;
        }

        printf("%02X", (unsigned char)c);

        int is_last_char = space == '\n';
        if (!is_last_char) {
            printf(" ");
        }
        if (is_last_char) {
            printf("\n");
            break;
        }
    }
}

void decode() {
    unsigned int c;
    char space;

    while (scanf("%2x%c", &c, &space) == 2 && c != '\n') {
        if (space != ' ' && space != '\n') {
            printf("n/a\n");
            break;
        }

        printf("%c", (char)c);

        int is_last_char = space == '\n';
        if (!is_last_char) {
            printf(" ");
        }
        if (is_last_char) {
            printf("\n");
            break;
        }
    }
}
