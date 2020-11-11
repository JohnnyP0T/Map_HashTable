#pragma once


#ifndef _HASHTABLES_H_
#define _HASHTABLES_H_

#include <string>

#include "Node.h"

/// @brief Хеш-таблица
struct HashTable
{
	int Length = 0;
	int Capacity = 8;
	Node** ArrayPointers;
};

/// @brief Инициализация массива указателей
/// @param hashTable Указатель на хеш таблицу
void InitializePointers(HashTable* hashTable);

/// @brief Добавление элемента в хеш таблицу
/// @param hashTable Указатель на хеш таблицу
/// @param key Ключ
/// @param value Значение
void AddElement(HashTable*& hashTable, std::string& key, std::string& value);

/// @brief Удаление элемента по ключу из хеш таблицы
/// @param hashTable Указатель на хеш таблицу
/// @param key Ключ
void RemoveElement(HashTable* hashTable, std::string& key);

/// @brief Нахождение элмента по ключу в хеш таблице
/// @param hashTable Указатель на хеш таблицу
/// @param key Ключ
/// @return Значение Value
std::string FindElement(HashTable* hashTable, std::string& key);

/// @brief Хеш функция
/// @param hashTable Указатель на хеш таблицу
/// @param key Ключ
/// @return Индекс
int HashFunction(HashTable* hashTable, std::string& key);

/// @brief Рехешинг
/// @param hashTable Указатель на хеш таблицу
void Rehashing(HashTable*& hashTable);

/// @brief Удаление хеш таблицы
/// @param hashTable Указатель на хеш таблицу
void RemoveHashTable(HashTable* hashTable);


#endif //_HASHTABLES_H_