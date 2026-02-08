#!/bin/bash

FILE_PATH="$1"
OLD_TEXT="$2"
NEW_TEXT="$3"

if [ ! -f $FILE_PATH ]; then
    echo "Error: file '$FILE_PATH' not found!"
    exit 1
fi

if [ ! -w "$FILE_PATH" ]; then
    echo "Error: file '$FILE_PATH' is readonly!"
    exit 1
fi

if [ -z "$NEW_TEXT" ]; then
    echo "Failed to parse arguments"
    echo "Correct usage: edit.sh <file_path> <old_text> <new_text>"
    exit 1
fi

sed -i '' "s|$OLD_TEXT|$NEW_TEXT|g" "$FILE_PATH"

FILE_SIZE=$(wc -c < "$FILE_PATH" | tr -d ' ')
LAST_MOD=$(stat -f "%Sm" -t "%Y-%m-%d %H:%M" "$FILE_PATH")
CHECKSUM=$(shasum -a 256 "$FILE_PATH" | awk '{print $1}')

echo "$FILE_PATH - $FILE_SIZE - $LAST_MOD - $CHECKSUM - sha256" >> src/files.log
