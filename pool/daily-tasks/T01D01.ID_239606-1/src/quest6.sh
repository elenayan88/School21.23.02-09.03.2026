# У файлов .sh нет прав на запуск, поэтому их нужно дать им
chmod +x ai_help/unifier.sh
chmod +x ai_help/keygen.sh
  

# вначале создаем директорию с ключами
ai_help/keygen.sh

# Создаем директорию для уже нормальных ключей
mkdir ai_help/key

# далее мы пишем фильтр который переносит 
# все нормальные ключи в созданную ранее папку 
mv key/*.key ai_help/key/

# Удаляем ненужную директорию
rm -r key/

# Запускаем unifier.sh
ai_help/unifier.sh
