#pragma once
#include "LinkedList.h"

class Hashtable
{
    struct item         // в структуре всего один элемент может стоит в класс уже тогда положить?
    {
        List<string> data;
    };

    int size;
    item* table;
    
    int hashFunction(string word);

public:
	Hashtable();
	void addItem(string word, string definition);
    void search(string word);
	void printHashtable();
    int getSize() {return size;}
    void setSize(int s) {size = s;}
};

Hashtable::Hashtable()
{
	size = 1000;
	table = new item[size];
}

inline int Hashtable::hashFunction(string word)
{
	int hash = 0;
	for (int i = 0; i < word.size(); i++)
	{
		hash += word[i];
	}

	int key = hash % size;
	return key;
}

inline void Hashtable::addItem(string word, string definition)  // изменила
{
	int key = hashFunction(word);
	table[key].data.pushBack(definition);
}

inline void Hashtable::printHashtable() // ! нужно сделать условие так как под индексом может ничего не быть, мы же заполняем рандомно
{
	for (int i = 0; i < size; i++)
	{
		table[i].data.print();
		cout << endl;
	}
}

inline void Hashtable::search(string word)
{
	int index = hashFunction(word);

	if (table[index].data.getSize() == 0) // ! у нас не может быть такого случая
	{
		cout << "No definition for such word!";
	}
	else
	{
		for (int i = 0; i < table[index].data.getSize(); i++)  // !нам же нужно найти ключ + вывести слово и определение / проверить на колизии, а то так выходит O = n
		{
			if (table[index].data[i] == word)
			{
                cout << word << endl << table[index].data[i] << endl;
				break;
			}
		}
	}
}


