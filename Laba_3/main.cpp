#include "dictionary.h"

int main()
{
    Hashtable table;
    dictionaryToHashTable(table);
    
    vector<string> prompt = input();
    definition(prompt, table);
    
    table.clear();
    
    return 0;
}
