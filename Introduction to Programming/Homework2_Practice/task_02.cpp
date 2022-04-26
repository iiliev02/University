#include <iostream>
using namespace std;



void checkSize(string str1, string str2)
{
    if (str1.size() > 15 || str2.size() > 15)
    {
        cout << "Many characters!!!" << endl;
        exit(1);
    }
}

void noDuplicateLetter(string str1, string str2)
{
    cout << str1 << endl;
    for (int i = 0; i < str2.size(); i++)
    {
        int str1Lenght = str1.size();
        while (str1Lenght != 0)
        {
            cout << " ";
            str1Lenght--;
        }
        cout << str2[i];
        cout << endl;
    }
}

void duplicateLetter(string str1, string str2, int positionOne, int positionTwo)
{
    for (int i = 0; i < str2.size(); i++)
    {
        if (i != positionTwo)
        {
            for (int j = 0; j < positionOne; j++)
            {
                cout << " ";
            }
            cout << str2[i];
            cout << endl;
        }
        else
        {

            cout << str1 << endl;
        }
    }
}
int main()
{
    string str1, str2;
    int countLetter = 0, positionOne = 0, positionTwo = 0;
    cout << "Enter the first word: ";
    cin >> str1;
    cout << "Enter the second word: ";
    cin >> str2;
    checkSize(str1, str2);
    for (int i = 0; i < str1.size(); i++) 
    {
        if (islower(str1[i]))
        {
            cout << "All letters must be uppercase!!!" << endl;
            exit(1);
        }
        for (int j = 0; j < str2.size(); j++) 
        {
            if (islower(str2[j]))
            {
                cout << "All letters must be uppercase!!!" << endl;
                exit(1);
            }
            if (str1[i] == str2[j]) 
            {
                countLetter++;
                if (countLetter == 1)
                {
                    positionOne = i;
                    positionTwo = j;
                    break;
                }
            }
        }
    }
    if (countLetter == 0)
    {
        noDuplicateLetter(str1, str2);
    }
    else
    {
        duplicateLetter(str1, str2, positionOne, positionTwo);
    }
}