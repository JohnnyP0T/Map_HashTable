#pragma once


#ifndef _HASHTABLES_H_
#define _HASHTABLES_H_

#include <string>

#include "Node.h"

/// @brief ���-�������
struct HashTable
{
	int Length = 0;
	int Capacity = 8;
	Node** ArrayPointers;
};

/// @brief ������������� ������� ����������
/// @param hashTable ��������� �� ��� �������
void InitializePointers(HashTable* hashTable);

/// @brief ���������� �������� � ��� �������
/// @param hashTable ��������� �� ��� �������
/// @param key ����
/// @param value ��������
void AddElement(HashTable*& hashTable, std::string& key, std::string& value);

/// @brief �������� �������� �� ����� �� ��� �������
/// @param hashTable ��������� �� ��� �������
/// @param key ����
void RemoveElement(HashTable* hashTable, std::string& key);

/// @brief ���������� ������� �� ����� � ��� �������
/// @param hashTable ��������� �� ��� �������
/// @param key ����
/// @return �������� Value
std::string FindElement(HashTable* hashTable, std::string& key);

/// @brief ��� �������
/// @param hashTable ��������� �� ��� �������
/// @param key ����
/// @return ������
int HashFunction(HashTable* hashTable, std::string& key);

/// @brief ��������
/// @param hashTable ��������� �� ��� �������
void Rehashing(HashTable*& hashTable);

/// @brief �������� ��� �������
/// @param hashTable ��������� �� ��� �������
void RemoveHashTable(HashTable* hashTable);


#endif //_HASHTABLES_H_