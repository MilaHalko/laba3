#include "parsing.h"

bool dictHashing(Hashtable dictionary)                                   // доделать resize
{
    bool resize = false;
    fstream fin;
    fin.open("dictionary.txt");
    
    if (!fin.is_open())
    {
        cout << "Unable to open the dictionary file!" << endl;
    }
    
    else
    {
        dictionary.setSize(dictionary.getSize() * 2);
        
        while (!fin.eof())
        {
            string str = "";
            getline(fin, str);
            int pos = str.find(";", 0);
            
            dictionary.addItem(str.substr(0, pos), str.substr(pos + 2));
            
            if ( dictionary.getCount() / dictionary.getSize() >= 0.8)
            {
                dictionary.clearTable();
                resize = true;
                break;
            }
        }
    }
    fin.close();
    return resize;
}




int Dictionary_Size()
{
    fstream fin;
    fin.open("dictionary.txt");
    int w = 0;                          // words' quantity
    
    if (!fin.is_open())
    {
        cout << "Unable to open the dictionary file!" << endl;
    }
    
    else
    {
        while (!fin.eof())
        {
            string str;
            getline(fin, str);
            w++;
            str = "";
        }
    }
    fin.close();
    return w;
}


void Fin_Dictionary(string word_definition[][2], int w)
{
    fstream fin;
    fin.open("dictionary.txt");
    
    if (!fin.is_open())
    {
        cout << "Unable to open the dictionary file!" << endl;
    }
    
    else
    {
        string str;              // string from file
        int ch;                  // index of ";" in string
        
        for (int i = 0; i < w; i++)
        {
            getline(fin, str);
            ch = str.find(";", 0);
            word_definition[i][0] = str.substr(0, ch);
            word_definition[i][1] = str.substr(ch+2);
            str = "";
        }
    }
    fin.close();
}
    

string wordFromSentence(string &sentence)
{
    string word = "";

    for (int i = 0; i < sentence.size(); i++)
    {
        if (isalpha(sentence[i]))
        {
            word += sentence[i];
            i++;
        }
        else
        {
            if (!word.size())
            {
                i++;
            }
            else
            {
                sentence.erase(0, i);
                return word;
            }
        }
    }
    return "0";
}

