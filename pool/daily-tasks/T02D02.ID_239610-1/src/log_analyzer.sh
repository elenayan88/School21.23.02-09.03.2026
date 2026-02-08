#!/bin/bash

FILE_PATH="$1"

if [ ! -f $FILE_PATH ]; then
    echo "Error: file '$FILE_PATH' not found!"
    exit 1
fi

# 2. Общее количество записей
# Считаем количество строк в файле
TOTAL_RECORDS=$(wc -l < "$FILE_PATH" | tr -d ' ')

# 3. Количество уникальных файлов
# Предположим, что путь к файлу — это 2-я колонка в логе
# awk берет 2-ю колонку, sort группирует, uniq считает уникальные
UNIQUE_FILES=$(awk '{print $2}' "$FILE_PATH" | sort | uniq | wc -l | tr -d ' ')

# 4. Количество изменений, приведших к смене хеша
# Предположим, что хеш — это 4-я колонка в логе.
# Если мы хотим найти именно СМЕНЫ хеша (уникальные пары файл+хеш)
# Мы берем колонку с именами файлов и их хешами
HASH_CHANGES=$(awk '{print $2, $4}' "$FILE_PATH" | sort | uniq | wc -l | tr -d ' ')

# 5. Вывод в stdout (только 3 числа)
echo "$TOTAL_RECORDS $UNIQUE_FILES $HASH_CHANGES"