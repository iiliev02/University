#include <iostream>
using namespace std;

int main()
{
	string str1, str2;
	cout << "Word 1: ";
	cin >> str1;
	cout << "Word 2: ";
	cin >> str2;
	char letter;
	for (int i = 0; i < str1.size(); i++)
	{
		letter = str1[i];
		for (int j = 0; j < str2.size(); j++)
		{
			if (tolower(letter) == tolower(str2[j])) str1[i] = toupper(str1[i]);
		}
	}
	cout << str1 << endl;
}
