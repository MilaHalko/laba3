#pragma once
#include "LinkedList.h"

class Hashtable
{
    struct item                                                             // в структуре всего один элемент может стоит в класс уже тогда положить?
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
    int getSize() {return size;}
    void setSize(int s) {size = s;}
    void printHashtable();
};


Hashtable::Hashtable()
{
	size = 100000;
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


inline void Hashtable::addItem(string word, string definition)
{
	int key = hashFunction(word);
    definition = word + "; " + definition;
	table[key].data.pushBack(definition);
}


inline void Hashtable::search(string word)
{
	int key = hashFunction(word);

	if (table[key].data.getSize() == 0)
	{
		cout << "No definition for such word!";
	}
	else
	{
		for (int i = 0; i < table[key].data.getSize(); i++)
		{
            string wordFromList = table[key].data[i].substr(0, table[key].data[i].find(";"));
            
			if (wordFromList == word)
			{
                cout << word << endl << table[key].data[i] << endl;
				break;
			}
		}
	}
}


inline void Hashtable::printHashtable()
{
    for (int i = 0; i < size; i++)
    {
        table[i].data.print();
        cout << endl;
    }
}
