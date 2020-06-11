#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int a, b, c;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;
  int p = (a + b + c) / 2;
  int area = sqrt(p * (p - a) * (p - b) * (p - c));
  cout << "Area is: " << area;
}
