#include <iostream>

#include "Map.h"


void PrintDataStruct(HashTable* hash)
{
	Node* current;
	for(int i = 0; i < hash->capacity; i++)
	{
		current = hash->arrayPointers[i];
		if(current == nullptr)
		{
			std::cout << "NULL\n";
		}
		else if(current->pointNext == nullptr)
		{
			std::cout << "key: " << current->key << "\t value: " << current->value << std::endl;
		}
		else
		{
			while(current != nullptr)
			{
				std::cout << "key: " << current->key << "\t value: " << current->value << " -> ";
				current = current->pointNext;
			}
			std::cout << std::endl;
		}
	}
}


void PrintDataStruct(Map* map)
{
	Node* current;
	for (int i = 0; i < map->hashTable->capacity; i++)
	{
		current = map->hashTable->arrayPointers[i];
		if (current == nullptr)
		{
			std::cout << "";
		}
		else
		{
			while (current != nullptr)
			{
				std::cout << "key: " << current->key << "\t value: " << current->value;
				current = current->pointNext;
				std::cout << std::endl;
			}
		}
	}
}


int GetElementConsole()
{
	while (true)
	{
		std::string inputValue;
		size_t length;
		std::cout << "Enter menu value: ";
		std::getline(std::cin, inputValue);

		try
		{
			const int number = stoi(inputValue, &length);

			if (length == inputValue.length())
			{
				return number;
			}
		}
		catch (std::exception&)
		{
			std::cout << "Error exception\n";
		}

		std::cout << inputValue << " is not a number" << std::endl;
	}
}


int main()
{
	enum MyChoice
	{
		Add = 1,
		Remove = 2,
		Find = 3,
		Show = 4,
		Exit = 5
	};
	
	Map* map = new Map;
	InitializePointers(map->hashTable);
	
	std::string key;
	std::string value;
	bool valueForPrint = false;
	
	for(;;)
	{
		if(valueForPrint)
		{
			std::cout << "/-----------------Hash_Table-----------------\\\n";
			PrintDataStruct(map->hashTable);
			std::cout << "\n/-------------------Map-------------------\\\n";
			PrintDataStruct(map);
		}

		std::cout << "+=========================Menu=========================+\n"
			<< "1 - Add\n"
			<< "2 - Remove\n"
			<< "3 - Find\n"
			<< "4 - Show\n"
			<< "5 - Exit\n";
		const int valueForMenu = GetElementConsole();
		
		switch (valueForMenu)
		{
			case Add:
			{
				std::cout << "key: ";
				std::getline(std::cin, key);
				std::cout << "value: ";
				std::getline(std::cin, value);
				InsertItem(map, key, value);
				break;
			}
			
			case Remove:
			{
				std::cout << "key: ";
				std::getline(std::cin, key);
				try
				{
					RemoveItem(map, key);
				}
				catch (std::exception& exceptionRemove)
				{
					std::cout << exceptionRemove.what();
					system("pause");
					break;
				}
				break;
			}
			
			case Find:
			{
				std::cout << "key: ";
				std::getline(std::cin, key);
				try
				{
					std::cout << "value: " << FindItem(map, key) << std::endl;
				}
				catch (std::exception& exceptionFind)
				{
					std::cout << exceptionFind.what();
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			
			case Show:
			{
				valueForPrint = true;
				break;
			}
			
			case Exit:
			{
				DeleteMap(map);
				delete map;
				return 0;
			}
			
			default:
			{
				std::cout << "Invalid value\n";
				system("pause");
				break;
			}
		}
		system("cls");
	}
}