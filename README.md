# Map_HashTable
Словарь на базе хеш-таблицы
## Введение
### Словари (ассоциативные массивы, map)
Ассоциативный массив — абстрактный тип данных
(интерфейс к хранилищу данных), позволяющий хранить
пары вида «(ключ, значение)» и поддерживающий
операции добавления пары, а также поиска и удаления
пары по ключу:
* INSERT(ключ, значение)
* FIND(ключ)
* REMOVE(ключ)

```
Предполагается, что ассоциативный массив не может
хранить две пары с одинаковыми ключами.
```

### Хеш-таблица
*Хэширование* – процесс преобразования ключей к числам.

*Хэш-таблица* – массив ключей с особой логикой:
* Вычисление хэш-функции, которая преобразует ключ
поиска в индекс
* Разрешения конфликтов, т.к. два и более различных
ключа могут преобразовываться в один и тот же индекс
массива

Сложность всех операций O(1).

### Хеш-функция
*Хеш-функция* (функция свёртки) – преобразование по
детерминированному алгоритму входного массива данных
произвольной длинны в выходную битовую строку
фиксированной длины.

Коллизией хеш-функции H называется два различных
входных блока данных X и Y, таких, что
H(X) = H(Y)

## Основная чать
В данной работе в качестве хеш-функции я использовал метод Пирсона

![Хеш-функция строки](https://imgur.com/VHZg0PZ)
