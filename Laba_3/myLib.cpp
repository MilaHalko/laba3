#include "myLib.h"

int Dictionary_Size() {
    
    fstream fin;
    fin.open("dictionary.txt");
    int w = 0;                          // words' quantity
    
    if (!fin.is_open()) {
        cout << "Unable to open the dictionary file!" << endl;
    }
    
    else {
        
        while (!fin.eof()) {
            string str;
            getline(fin, str);
            w++;
            str = "";
        }
    }
    fin.close();
    return w;
}


void Fin_Dictionary(vector<vector<string>> &word_definition, int w) {
    
    fstream fin;
    fin.open("dictionary.txt");
    
    if (!fin.is_open()) {
        cout << "Unable to open the dictionary file!" << endl;
    }
    
    else {
        string str;              // string from file
        int ch;              // index of ";" in string
        
        for (int i = 0; i < w; i++) {
            getline(fin, str);
            ch = str.find(";", 0);
            word_definition[i][0] = str.substr(0, ch);
            ch +=2;
            word_definition[i][1] = str.substr(ch);
            str = "";
        }
    }
    fin.close();
}
    
/*
class Hash_Table {
 public:
    int key;
    string definition;
};

string* word (int key; string definition)
{
    string* word =
}
*/
