#include "Map.h"


void InsertItem(Map* map, std::string& key, std::string& value)
{
	AddElement(map->HashTableObject, key, value);
}


void RemoveItem(Map* map, std::string& key)
{
	RemoveElement(map->HashTableObject, key);
}


std::string FindItem(Map* map, std::string& key)
{
	return FindElement(map->HashTableObject, key);
}


void DeleteMap(Map* map)
{
	RemoveHashTable(map->HashTableObject);
	delete map->HashTableObject;
}
