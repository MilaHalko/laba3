#include "myLib.h"

int main(){
    
    int w = Dictionary_Size();                                        // words' quantity
    vector<vector<string>> word_definition(w, vector<string> (2));    // vector contains words[i] and definition[j]
    Fin_Dictionary(word_definition, w);                               // filling vector "word_definition"
    
    // Checking Fin_Dictionary (first 10 words)
    for (int i = 0; i < 10; i++) {
       for(int j = 0; j < 2; j++) {
           cout << word_definition[i][j] << endl;
       }
    }
    
    return 0;
}
