#pragma once

#include "linkedlist.h"

class Hashtable
{
public:
	Hashtable();

	void addItem(string data);
	void printHashtable();

private:
	struct item
	{
		List<string> data;
	};

	int hashFunction(string word);

	int Size;
	item* table;
};

Hashtable::Hashtable()
{
	Size = 10;
	table = new item[Size];
}

inline int Hashtable::hashFunction(string word)
{
	int hash = 0;
	for (int length = word.size(), i = 0; i < length; i++)
	{
		hash += word[i];
	}

	int key = hash % Size;
	return key;
}

inline void Hashtable::addItem(string data)
{
	int index = hashFunction(data);
	table[index].data.push_back(data);
}

inline void Hashtable::printHashtable()
{
	for (int i = 0; i < Size; i++)
	{
		table[i].data.print();
		cout << endl;
	}
}



