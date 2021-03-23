#include "hashtable.h"
#include "linkedlist.h"
#include "parsing.h"

int main()
{
    Hashtable dictionary;
    dictHashing(dictionary);
    
    string sentence;
    cout << "Write word/words to get its definition: "; cin >> sentence;
    cout << endl;
    
    while (!sentence.empty())
    {
        string word = wordFromSentence(sentence);
        
        if (word == "0")
        {
            cout << "No word was given!" << endl;
        }
        else
        {
            dictionary.search(word);
        }
    }
    return 0;
}


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


/* Supporting functions
 
 // Checking Fin_Dictionary (first 10 words)
 for (int i = 0; i < 10; i++) {
    for(int j = 0; j < 2; j++) {
        cout << word_definition[i][j] << endl;
    }
 }
 
 */
