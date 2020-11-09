#include "Map.h"


void InsertItem(Map* map, std::string& key, std::string& value)
{
	AddElement(map->hashTable, key, value);
}


void RemoveItem(Map* map, std::string& key)
{
	RemoveElement(map->hashTable, key);
}


std::string FindItem(Map* map, std::string& key)
{
	return FindElement(map->hashTable, key);
}


void DeleteMap(Map* map)
{
	RemoveHashTable(map->hashTable);
	delete map->hashTable;
}
