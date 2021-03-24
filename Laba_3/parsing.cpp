#include "parsing.h"

string toUpper(string str)
{
	string temp;
	for (int i = 0; i < str.size(); i++)
	{
		temp.push_back(toupper(str[i]));
	}
	return temp;
}

vector<string> input()
{
	string str;
	cout << "Prompt: ";

	getline(cin, str);
	str = toUpper(str);

	vector<string> words;

	int ptr = 0;
	while (str.find(' ') != string::npos)
	{
		ptr = str.find(' ');
		words.push_back(str.substr(0, ptr));
		str.erase(0, ptr + 1);
	} 
	words.push_back(str);

	return words;
}

void printDict(string* dict, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << dict[i] << endl;
	}
	cout << endl;
}