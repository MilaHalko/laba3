#pragma once
#include "LinkedList.h"

class Hashtable
{
    struct item
    {
        List<string> definition;
    };
    
    int Size;
    int count;
    item* table;
    
    string separateWord(string str);
    int hashFunction(string word);
    
public:
    Hashtable();
    
    void addItem(string definition);
    void search(string word);
    void resize();
    void clear();
    //void printHashtable();
};

