#include "HashTable.h"

#define LIMIT_LOAD_FACTOR 0.8

void InitializePointers(HashTable* hashTable)
{
	hashTable->arrayPointers = new Node * [hashTable->capacity];
	for(int i = 0; i < hashTable->capacity; i++)
	{
		hashTable->arrayPointers[i] = nullptr;
	}
}


void AddElement(HashTable*& hashTable, std::string& key, std::string& value)
{
	const int index = HashFunction(hashTable, key);

	if(hashTable->arrayPointers[index] == nullptr)
	{
		hashTable->arrayPointers[index] = new Node;
		hashTable->arrayPointers[index]->key = key;
		hashTable->arrayPointers[index]->value = value;
		++hashTable->length;
		return;
	}

	Node* current = hashTable->arrayPointers[index];
	while(current->pointNext != nullptr)
	{
		current = current->pointNext;
	}
	current->pointNext = new Node;
	current->pointNext->key = key;
	current->pointNext->value = value;

	const double loadFactor = (double)hashTable->length / (double)hashTable->capacity;
	
	if (loadFactor > LIMIT_LOAD_FACTOR)
	{
		Rehashing(hashTable);
	}
}


void RemoveElement(HashTable* hashTable, std::string& key)
{
	const int index = HashFunction(hashTable, key);
	Node* current = hashTable->arrayPointers[index];

	if(current == nullptr)
	{
		throw std::exception("Does not exist\n");
	}
	
	if(current->pointNext == nullptr)
	{
		delete current;
		hashTable->arrayPointers[index] = nullptr;
		--hashTable->length;
		return;
	}

	if(current->key == key)
	{
		Node* nodeNext = current->pointNext;
		delete current;
		hashTable->arrayPointers[index] = nodeNext;
		return;
	}
	
	while(current->pointNext->key != key)
	{
		current = current->pointNext;
	}
	if (current->pointNext->pointNext != nullptr)
	{
		Node* nodeNext = current->pointNext->pointNext;
		delete current->pointNext;
		hashTable->arrayPointers[index]->pointNext = nodeNext;
		return;
	}

	delete current->pointNext;
	hashTable->arrayPointers[index]->pointNext = nullptr;
}


std::string FindElement(HashTable* hashTable, std::string& key)
{
	Node* current = hashTable->arrayPointers[HashFunction(hashTable, key)];
	
	if(current == nullptr)
	{
		throw std::exception("Does not exist\n");
	}
	
	if(current->pointNext == nullptr)
	{
		return current->value;
	}
	
	while(current->key != key)
	{
		current = current->pointNext;
	}
	return current->value;
}


int HashFunction(HashTable* hashTable, std::string& key)
{
	int hash = 0;
	//Два соседних натуральных числа всегда будут взаимно просты
	const int a = hashTable->capacity - 2;
	int power = 1;
	
	for (char i : key)
	{
		hash += i * power;
		power *= a;
	}
	
	return abs(hash % (hashTable->capacity - 1));
}


void Rehashing(HashTable*& hashTable)
{
	const int growthFactor = 2;
	HashTable* newHashTable = new HashTable;
	newHashTable->capacity = hashTable->capacity * growthFactor;
	InitializePointers(newHashTable);

	Node* current;
	
	for(int i = 0; i < hashTable->capacity; i++)
	{
		current = hashTable->arrayPointers[i];
		if(current != nullptr)
		{
			while(current != nullptr)
			{
				AddElement(newHashTable, current->key, current->value);
				current = current->pointNext;
			}
		}
	}

	delete[] hashTable->arrayPointers;
	delete hashTable;
	hashTable = newHashTable;
}


void RemoveHashTable(HashTable* hashTable)
{
	delete[] hashTable->arrayPointers;
}
