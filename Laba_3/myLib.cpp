#include "myLib.h"

void Fin_Dictionary(vector<string> &dict) {
    
    fstream fin;
    fin.open("Dictionary.txt");
    int i = 0;                 // variable let us know quantity of words' definition in the end
    
    if (!fin.is_open()) {
        cout << "Unable to open the dictionary file!" << endl;
    }
    
    else {
        
        while (!fin.eof())
        {
            string str;
            getline(fin, str, '\n');
            dict.insert(dict.begin() + i, str);
            i++;
        }
    }
}
