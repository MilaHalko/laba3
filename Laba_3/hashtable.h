#pragma once
#include "LinkedList.h"

class Hashtable
{
    struct item         // в структуре всего один элемент может стоит в класс уже тогда положить?
    {
        List<string> data;
    };

    int Size;
    item* table;
    
    int hashFunction(string word);

public:
	Hashtable();

	void addItem(string data);
    void search(string word);
	void printHashtable();
};

Hashtable::Hashtable()
{
	Size = 1000;
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

inline void Hashtable::search(string word)
{
	int index = hashFunction(word);

	if (table[index].data.GetSize() == 0)
	{
		cout << "No definition for such word!";
	}
	else
	{
		for (int size = table[index].data.GetSize(), i = 0; i < size; i++)
		{
			if (table[index].data[i] == word)
			{
				cout << table[index].data[i];
				break;
			}
		}
	}
}


