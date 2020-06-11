#include <iostream>
using namespace std;
int main()
{
  int a, b;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  b = a + b;
a = b - a;
b = b - a;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

}
