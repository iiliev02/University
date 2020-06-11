#include <iostream>
using namespace std;
int main()
{
  int n, sum = 1;
  cout << "Enter a number: ";
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    sum = sum * i;
  }
  cout << sum;
}
