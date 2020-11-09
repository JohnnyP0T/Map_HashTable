#pragma once

#ifndef _LIST_H_
#define _LIST_H_

#include <string>

/// @brief Узел списка
struct Node
{
	Node* pointNext = nullptr;
	std::string value = "";
	std::string key = "";
};


#endif //_LIST_H_