#include "hashtable.h"
#include "linkedlist.h"
#include "parsing.h"

int main(){
    
    int w = dictionarySize();                                        // words' quantity
    string wordDefinition [w][2];                                    // array contains words[i] and definition[j]
    finDictionary(wordDefinition, w);                               // filling array "word_definition"
    
    Hashtable dictionary;
    dictHashing(wordDefinition, w, dictionary);
    
    string sentence;
    cout << "Write word/words to get its definition: "; cin >> sentence;
    cout << endl;
    
    while (!sentence.empty()) {
        string word = wordFromSentence(sentence);
        
        dictionary.search(word);
        
        /*List<string> list;

        for (int i = 0; i < 3; i++)
        {
            word.clear();
            cin >> word;
            list.push_back(word);
        }
        cout << "LinkedList: \n";
        for (int i = 0; i < 3; i++)
        {
            cout << list[i] << endl;
        }
        list.clear();*/   // ! не понимаю для чего это нужно
    }
    

    /*
        OutputDefinition(sentence, word_definition, w);
    } while (1);
     */
    return 0;
}



/* Supporting functions
 
 // Checking Fin_Dictionary (first 10 words)
 for (int i = 0; i < 10; i++) {
    for(int j = 0; j < 2; j++) {
        cout << word_definition[i][j] << endl;
    }
 }
 
 */
