#include <iostream>
#include <string>
using namespace std;

int index = 0;
bool haveAllLetter = true;
int isTrue(string str1, string str2)
{
	index++;
	int notSameLetter = 0;
	for (int i = 0; i < str2.size(); i++)
	{
		if (str1[index] == str2[i] && index < str1.size())
		{
			isTrue(str1, str2);
			return haveAllLetter;
		}
		else if (index == str1.size())
		{
			return haveAllLetter;
		}
		else
		{
			notSameLetter++;
			if (notSameLetter == str2.size())
			{
				haveAllLetter = false;
				return haveAllLetter;
			}
		}
	}
}

int main()
{
    string str1, str2;
    cout << "Word 1:";
    cin >> str1;
    cout << "Word 2:";
    cin >> str2;
    if (isTrue(str1, str2) == true) cout << "Yes" << endl;
    else cout << "No" << endl;

}