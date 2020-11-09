#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include "HashTable.h"

/// @brief ������� �� ���� ��� �������
struct Map
{
	HashTable* hashTable = new HashTable;
};

/// @brief ���������� �������� � �������
/// @param map ��������� �� �������
/// @param key ����
/// @param value ��������
void InsertItem(Map* map, std::string& key, std::string& value);

/// @brief �������� �������� �� ����� �� �������
/// @param map ��������� �� �������
/// @param key ����
void RemoveItem(Map* map, std::string& key);

/// @brief ����� �������� �� ����� � �������
/// @param map ��������� �� �������
/// @param key ����
/// @return �������� value
std::string FindItem(Map* map, std::string& key);

/// @brief �������� �������
/// @param map ��������� �� �������
void DeleteMap(Map* map);

#endif //_MAP_H_
