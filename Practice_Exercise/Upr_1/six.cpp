#include <iostream>
using namespace std;
int main()
{
  int x, y;
  cout << "X = ";
  cin >> x;
  cout << "Y = ";
  cin >> y;
 int r = 6;
 if (x > 6 || y > 6)
 {
   cout << "false";
 }
 else if(x == 6 && y == 0)
 {
   cout << "true";
 }
 else if (x == 0 && y == 6)
 {
   cout << "true";
 }
 else {
   cout << "true";
 }
}
