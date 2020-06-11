#include <iostream>
#include <string>
using namespace std;

const int MAXWORDS = 100;

int main() 
{
	string line;
	getline(cin, line);
	line += " ";

	string arr[MAXWORDS];
	string search = " ";

	int spacePos;
	int currPos = 0;
	int arrSize = 0;
	int prevPos = 0;

	do
	{
		spacePos = line.find(search, currPos);

		if (spacePos >= 0)
		{
			currPos = spacePos;
			arr[arrSize] = line.substr(prevPos, currPos - prevPos);
			currPos++;
			prevPos = currPos;
			arrSize++;
		}

	} while (spacePos >= 0);

	arr[arrSize] = line.substr(prevPos, line.length());

	string wordWithMaxLength;

	int maxSize = -1;
	int wordSize = -1;

	for (int i = 0; i < arrSize; i++)
	{
		wordSize = arr[i].size();
		if (maxSize < wordSize) 
		{
			maxSize = wordSize;
			wordWithMaxLength = arr[i];
		}
	}

	string* pointer = &wordWithMaxLength;
	cout << *pointer << endl;
}

