#pragma once

#include "linkedlist.h"

class Hashtable
{
public:
	Hashtable();

private:
	struct item
	{
		List<string> data;
	};

	int Size;
	item* table;
};

Hashtable::Hashtable()
{
	Size = 10;
	table = new item[Size];
}


