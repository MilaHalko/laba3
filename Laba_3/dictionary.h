#pragma once
#include "hashtable.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void dictionaryToHashTable(Hashtable);
vector<string> input();
void definition(vector <string>, Hashtable);
void printDict(string* dict, int size);
string toUpper(string str);
