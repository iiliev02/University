#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    cout << "Enter the first word: ";
    cin >> str1;
    cout << "Enter the second word: ";
    cin >> str2;

    cout << str1.append(str2) << endl;
}