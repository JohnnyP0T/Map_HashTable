#pragma once

#ifndef _NODE_H_	
#define _NODE_H_

#include <string>
/// @brief Узел
struct Node
{
	Node* PointNext = nullptr;
	std::string Value = "";
	std::string Key = "";
};


#endif // _NODE_H_	