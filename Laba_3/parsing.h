#pragma once
#include "hashtable.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int dictionarySize();
void finDictionary(string [][2], int);
string wordFromSentence(string &);
void dictHashing(string [][2], int, Hashtable);
// void OutputDefinition(string sentence, string word_definition[][2], int w);
