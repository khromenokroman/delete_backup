# Удаляем файлы в каталоге

## Задача: удалить лишние фалы резервных копий

В данном репозитории реализована программа которая принимает 2 параметра:
    1 параметр это путь до папки (полный),
    2 парамет это то сколько нужно оставить фалов

## Инструкция по сборке

Требуется компиялтор с поддержкой C++17

Для сборки проекта необходимо выполнить следующую команду
```
g++ -o delete_backup ./delete_backup.cpp -std=c++17
```

Примеры работы:
```bash
./delete_backup "/root/backup-postgres/backup-unix-os/" 10

Delete file -- /root/backup-postgres/backup-unix-os/backup-srv-1c-db-1-2023-05-01-03:00:01.tar.gz
Delete file -- /root/backup-postgres/backup-unix-os/backup-srv-1c-db-1-2023-04-28-03:00:01.tar.gz
Delete file -- /root/backup-postgres/backup-unix-os/backup-srv-1c-db-1-2023-04-25-03:00:01.tar.gz
Delete file -- /root/backup-postgres/backup-unix-os/backup-srv-1c-db-1-2023-04-22-03:00:01.tar.gz