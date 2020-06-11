#include <iostream>
using namespace std;

int main()
{
    int m;
    cout << "Enter a value for m: ";
    cin >> m;
    int firstLine = 123456789;
    while (m != 0)
    {
        cout << firstLine << endl;
        firstLine = (firstLine % 100000000) * 10 + firstLine / 100000000;
        m--;
    }
    
}