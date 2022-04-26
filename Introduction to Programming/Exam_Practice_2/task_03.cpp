#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string nickname;
    cin >> nickname;
    for (int i = 0; i < nickname.size(); i++)
    {
        if (i + 1 >= nickname.size()) break;
        else if (nickname[i] == nickname[i + 1])
        {
            nickname.erase(nickname[i]);
        }
    }
    cout << nickname << endl;
}