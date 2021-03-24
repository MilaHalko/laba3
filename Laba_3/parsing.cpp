#include "parsing.h"

void dictionaryToHashTable(Hashtable table)
{
    ifstream fin;
    fin.open("Dictionary.txt");
    
    if (!fin.is_open())
    {
        cout << "Unable to open the file!" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            string str = "";
            str.clear();
            getline(fin, str);
            table.addItem(str);
        }
    }
    fin.close();
}

vector<string> input()
{
    string str;
    cout << "Type a sentence to get definition: ";
    
    getline(cin, str);
    str = toUpper(str);
    
    vector<string> words;
    string word = "";
    int i = 0;
    
    while (str.size() != 0)
    {
        if (isalpha(str[i]))
        {
            word += str[i];
            i++;
        }
        else
        {
            if (word.size() != 0) {
                words.push_back(str.substr(i - word.size(), i));
                str.erase(0, i);
                word = "";
            }
            else str.erase(0, 1);
            
            i = 0;
        }
    }
    return words;
}

string toUpper(string str)
{
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        temp.push_back(toupper(str[i]));
    }
    return temp;
}

void definition(vector <string> prompt, Hashtable table)
{
    cout << endl;
    for (int i = 0; i < prompt.size(); i++)
    {
        cout << "=====================\n";
        table.search(prompt[i]);
        cout << endl;
    }
    cout << "=====================\n";
}

void printDict(string* dict, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << dict[i] << endl;
    }
    cout << endl;
}
