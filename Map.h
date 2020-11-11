#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include "HashTable.h"

/// @brief Словарь на базе хеш таблицы
struct Map
{
	HashTable* HashTableObject = new HashTable;
};

/// @brief Добавление элемента в словарь
/// @param map Указатель на словарь
/// @param key Ключ
/// @param value Значение
void InsertItem(Map* map, std::string& key, std::string& value);

/// @brief Удаление элемента по ключу из словаря
/// @param map Указатель на словарь
/// @param key Ключ
void RemoveItem(Map* map, std::string& key);

/// @brief Поиск элемента по ключу в словаре
/// @param map Указатель на словарь
/// @param key Ключ
/// @return Значение Value
std::string FindItem(Map* map, std::string& key);

/// @brief Удаление словаря
/// @param map Указатель на словарь
void DeleteMap(Map* map);

#endif //_MAP_H_
