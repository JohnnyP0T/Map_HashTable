#include "HashTable.h"

//#define LIMIT_LOAD_FACTOR 0.8

constexpr double LIMIT_LOAD_FACTOR = 0.8;


void InitializePointers(HashTable* hashTable)
{
	hashTable->ArrayPointers = new Node * [hashTable->Capacity];
	for(int i = 0; i < hashTable->Capacity; i++)
	{
		hashTable->ArrayPointers[i] = nullptr;
	}
}


void AddElement(HashTable*& hashTable, std::string& key, std::string& value)
{
	const int index = HashFunction(hashTable, key);

	if(hashTable->ArrayPointers[index] == nullptr)
	{
		hashTable->ArrayPointers[index] = new Node;
		hashTable->ArrayPointers[index]->Key = key;
		hashTable->ArrayPointers[index]->Value = value;
		++hashTable->Length;
		return;
	}

	Node* current = hashTable->ArrayPointers[index];
	while(current->PointNext != nullptr && current->Key != key)
	{
		current = current->PointNext;
	}
	if (current->Key == key)
	{
		current->Value = value;
		return;
	}
	current->PointNext = new Node;
	current->PointNext->Key = key;
	current->PointNext->Value = value;
	++hashTable->Length;
	
	const double loadFactor = (double)hashTable->Length / (double)hashTable->Capacity;
	
	if (loadFactor > LIMIT_LOAD_FACTOR)
	{
		Rehashing(hashTable);
	}
}


void RemoveElement(HashTable* hashTable, std::string& key)
{
	const int index = HashFunction(hashTable, key);
	Node* current = hashTable->ArrayPointers[index];

	if(current == nullptr)
	{
		throw std::exception("Does not exist\n");
	}
	
	if(current->PointNext == nullptr)
	{
		delete current;
		hashTable->ArrayPointers[index] = nullptr;
		--hashTable->Length;
		return;
	}

	if(current->Key == key)
	{
		Node* nodeNext = current->PointNext;
		delete current;
		hashTable->ArrayPointers[index] = nodeNext;
		--hashTable->Length;
		return;
	}
	
	while(current->PointNext->Key != key)
	{
		current = current->PointNext;
	}
	if (current->PointNext->PointNext != nullptr)
	{
		Node* nodeNext = current->PointNext->PointNext;
		delete current->PointNext;
		hashTable->ArrayPointers[index]->PointNext = nodeNext;
		--hashTable->Length;
		return;
	}

	delete current->PointNext;
	hashTable->ArrayPointers[index]->PointNext = nullptr;
	--hashTable->Length;
}


std::string FindElement(HashTable* hashTable, std::string& key)
{
	Node* current = hashTable->ArrayPointers[HashFunction(hashTable, key)];
	
	if(current == nullptr)
	{
		throw std::exception("Does not exist\n");
	}
	
	if(current->PointNext == nullptr)
	{
		return current->Value;
	}
	
	while(current->Key != key)
	{
		current = current->PointNext;
	}
	return current->Value;
}


int HashFunction(HashTable* hashTable, std::string& key)
{
	int hash = 0;
	//Два соседних натуральных числа всегда будут взаимно просты
	const int a = hashTable->Capacity - 2;	/// @todo a
	int power = 1;
	
	for (char i : key)
	{
		hash += i * power;
		power *= a;
	}
	
	return abs(hash % (hashTable->Capacity - 1));
}


void Rehashing(HashTable*& hashTable)
{
	const int growthFactor = 2;
	HashTable* newHashTable = new HashTable;
	newHashTable->Capacity = hashTable->Capacity * growthFactor;
	InitializePointers(newHashTable);

	Node* current;
	
	for(int i = 0; i < hashTable->Capacity; i++)
	{
		current = hashTable->ArrayPointers[i];
		if(current != nullptr)
		{
			while(current != nullptr)
			{
				AddElement(newHashTable, current->Key, current->Value);
				current = current->PointNext;
			}
		}
	}

	delete[] hashTable->ArrayPointers;
	delete hashTable;
	hashTable = newHashTable;
}


void RemoveHashTable(HashTable* hashTable)
{
	delete[] hashTable->ArrayPointers;
}
