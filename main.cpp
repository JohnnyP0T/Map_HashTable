#include <iostream>

#include "Map.h"

/// @brief Печать хеш таблицы
void PrintDataStruct(HashTable* hash);

/// @brief Печать словаря
void PrintDataStruct(Map* map);

/// @brief Получение элемента с консоли
/// @return Значение пользователя
int GetElementConsole();


/// @brief Меню
enum class Menu
{
	Add = 1,
	Remove = 2,
	Find = 3,
	Show = 4,
	Exit = 5
};


int main()
{
	Map* map = new Map;
	InitializePointers(map->HashTableObject);
	
	std::string key;
	std::string value;
	bool isValueForPrint = false;		
	
	for(;;)
	{
		if(isValueForPrint)
		{
			std::cout << " /-----------------Hash_Table-----------------\\\n";
			PrintDataStruct(map->HashTableObject);
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
		
		switch (static_cast< Menu >( valueForMenu ))
		{
			case Menu::Add:
			{
				std::cout << "Key: ";
				std::getline(std::cin, key);
				std::cout << "Value: ";
				std::getline(std::cin, value);
				InsertItem(map, key, value);
				break;
			}
			
			case Menu::Remove:
			{
				std::cout << "Key: ";
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
			
			case Menu::Find:
			{
				std::cout << "Key: ";
				std::getline(std::cin, key);
				try
				{
					std::cout << "Value: " << FindItem(map, key) << std::endl;
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
			
			case Menu::Show:
			{
				isValueForPrint = true;
				break;
			}
			
			case Menu::Exit:
			{
				DeleteMap(map);
				delete map;
				return 0;
			}
			
			default:
			{
				std::cout << "Invalid Value\n";
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


void PrintDataStruct(HashTable* hash)
{
	Node* current;
	for(int i = 0; i < hash->Capacity; i++)
	{
		current = hash->ArrayPointers[i];
		if(current == nullptr)
		{
			std::cout << "NULL\n";
			continue;
		}
		if(current->PointNext == nullptr)
		{
			std::cout << "Key: " << current->Key << "\t Value: " << current->Value << std::endl;
			continue;
		}
		while(current != nullptr)
		{
			std::cout << "Key: " << current->Key << "\t Value: " << current->Value << " -> ";
			current = current->PointNext;
		}
		std::cout << std::endl;
	}
}


void PrintDataStruct(Map* map)
{
	Node* current;
	for (int i = 0; i < map->HashTableObject->Capacity; i++)
	{
		current = map->HashTableObject->ArrayPointers[i];
		if (current == nullptr)
		{
			std::cout << "";
			continue;
		}
		while (current != nullptr)
		{
			std::cout << "Key: " << current->Key << "\t Value: " << current->Value;
			current = current->PointNext;
			std::cout << std::endl;
		}
	}
}


int GetElementConsole()
{
	while (true)
	{
		std::string inputValue;
		size_t length;
		std::cout << "Enter menu Value: ";
		std::getline(std::cin, inputValue);

		try
		{
			int number = stoi(inputValue, &length);
			if (length == inputValue.length())
			{
				return number;
			}
		}
		catch (std::exception& e)
		{
			std::cout << inputValue << " is not a number! " << e.what() << std::endl;
		}
	}
}