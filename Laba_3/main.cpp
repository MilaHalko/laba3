#include "hashtable.h"
#include "LinkedList.h"

int main(){
    //string sentence;
    
    //int w = Dictionary_Size();                                        // words' quantity
    //string word_definition [w][2];                                    // array contains words[i] and definition[j]
    //Fin_Dictionary(word_definition, w);                               // filling array "word_definition"
    
    
    
    //..............
    
    
    /*
        
    */

    List<string> list;

    string word;
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
    list.clear();












    
    // user's input
    /*
    do {
        cout << "Type a sentence to get definition: "; cin >> sentence;
        
        if (sentence == "0") {                                         // If user want to finish
            break;
        }
        OutputDefinition(sentence, word_definition, w);
    } while (1);
     */
    system("pause");
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
