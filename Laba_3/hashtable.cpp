#include "hashtable.h"

Hashtable::Hashtable()
{
    Size = 10000;
    count = 0;
    table = new item[Size];
}

void Hashtable::addItem(string definition)
{
    int key = hashFunction(separateWord(definition));
    
    if (table[key].definition.is_empty()) count++;
    if (count / Size > 0.8) resize();
    
    table[key].definition.push_back(definition);
}

string Hashtable::separateWord(string str)
{
    return str.substr(0, str.find(';'));
}

int Hashtable::hashFunction(string word)
{
    long unsigned int hash = 0;
    
    for (int i = 0; i < word.size(); i++)
    {
        hash = hash * 31 + word[i];
    }
    
    int key = hash % Size;
    return key;
}

void Hashtable::search(string word)
{
    int key = hashFunction(word);
    bool wordExists = false;
    
    for (int i = 0; i < table[key].definition.getSize(); i++)
    {
        if (separateWord(table[key].definition[i]) == word)
        {
            wordExists = true;
            cout << table[key].definition[i];
            break;
        }
    }
    if (!wordExists)
    {
        cout << "There is no definition of such a word!\n";
    }
}

void Hashtable::resize()
{
    int pastSize = Size;
    Size *= 2;
    item* newTable = new item[Size];
    
    count = 0;
    swap(table, newTable);
    
    for (int i = 0; i < pastSize; i++)
    {
        for (int  j = 0; j < newTable[i].definition.getSize(); j++)
        {
            addItem(newTable[i].definition[j]);
        }
    }
    
    for (int i = 0; i < pastSize; i++)
    {
        newTable->definition.clear();
    }
    delete[] newTable;
}

void Hashtable::clear()
{
    for (int i = 0; i < Size; i++)
    {
        table->definition.clear();
    }
    delete[] table;
}

/*
void Hashtable::printHashtable()
{
    for (int i = 0; i < Size; i++)
    {
        table[i].definition.print();
        cout << endl;
    }
}
*/
