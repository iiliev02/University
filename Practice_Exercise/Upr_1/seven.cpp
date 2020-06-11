#include "iostream"
using namespace std;
int main()
{
  int a, b;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
    int c = a;
    a = a + b - a;
    b = c;

 cout << "a = " << a << endl;
 cout << "b = " << b;
}
