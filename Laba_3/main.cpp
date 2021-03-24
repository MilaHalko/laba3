#include "hashtable.h"
#include "linkedlist.h"
#include "parsing.h"
#include <fstream>

int main()
{
	Hashtable table;

	ifstream fin;
	fin.open("Dictionary.txt");

	int ptr = 0;
	if (!fin.is_open())
	{
		cout << "Unable to open the file!" << endl;
	}
	else
	{
		string str;

		while (!fin.eof())
		{
			str.clear();
			getline(fin, str);
			table.addItem(str);
		}
	}
	fin.close();

	vector<string> prompt = input();

	cout << endl << endl;
	for (int size = prompt.size(), i = 0; i < size; i++)
	{
		cout << "=====================\n";
		table.search(prompt[i]);
		cout << endl;
	}
	cout << "============================================\n";

	table.clear();
	system("pause");
}