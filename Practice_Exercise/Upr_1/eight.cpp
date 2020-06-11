#include <iostream>
using namespace std;
int main()
{
  int a, b;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  if (a ^ b)
  {
    cout << "Not same";
  }
  else {
    cout << "Same";
  }
}
