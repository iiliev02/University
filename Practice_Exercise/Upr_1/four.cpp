#include <iostream>
using namespace std;
int main()
{
    int n, reversedNumber = 0, remainder;
    cout << "Enter a number: ";
    cin >> n;
    int num = n;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    if (reversedNumber == num)
    {
      cout << "true";
    }
    else{
      cout << "false";
    }
    return 0;
}
