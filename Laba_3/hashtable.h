#pragma once

#include "linkedlist.h"

class Hashtable
{
public:
	Hashtable();

	void addItem(string data); 
	void printHashtable();
	void search(string word);
	void clear();
	void resize();
private:
	struct item
	{
		List<string> data;
	};

	int hashFunction(string word);
	string separateWord(string str);

	int Size;
	int count;
	item* table;
};

Hashtable::Hashtable()
{ 
	Size = 10000;
	count = 0;
	table = new item[Size];
}

inline int Hashtable::hashFunction(string word)
{
	long unsigned int hash = 0;
	for (int lenght = word.size(), i = 0; i < lenght; i++)
	{
		hash = hash * 31 + word[i];
	}

	int key = hash % Size;
	return key;
}

inline string Hashtable::separateWord(string str)
{
	return str.substr(0, str.find(';'));
}

inline void Hashtable::addItem(string data)
{
	int index = hashFunction(separateWord(data)); // index == key

	if (table[index].data.is_empty()) count++; // if use new index count++
	if (count / Size > 0.8) resize();

	table[index].data.push_back(data);   // push data
}

inline void Hashtable::printHashtable()
{
	for (int i = 0; i < Size; i++)
	{
		table[i].data.print();
		cout << endl;
	}
}

inline void Hashtable::search(string word)
{
	int index = hashFunction(word);
	bool flag = false;

	for (int  size = table[index].data.getSize(), i = 0; i < size; i++)
	{
		if (separateWord(table[index].data[i]) == word)
		{
			flag = true;
			cout << table[index].data[i];
			break;
		}
	}
	if (!flag)
	{
		cout << "=====================\n";
		cout << "There is no definition of such a word!\n";
	}
}

inline void Hashtable::clear()
{
	for (int i = 0; i < Size; i++)
	{
		table->data.clear();
	}
	delete[] table;
}

inline void Hashtable::resize()
{
	int pastSize = Size;
	Size *= 2;
	item* newTable = new item[Size];
	
	count = 0;
	swap(table, newTable);

	for (int i = 0; i < pastSize; i++)
	{
		for (int length = newTable[i].data.getSize(), j = 0; j < length; j++)
		{
			addItem(newTable[i].data[j]);
		}
	}
	
	for (int i = 0; i < pastSize; i++)
	{
		newTable->data.clear();
	}
	delete[] newTable;
}