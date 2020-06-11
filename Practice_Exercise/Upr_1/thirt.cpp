#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int x, y;
  cout << "X = ";
  cin >> x;
  cout << "Y = ";
  cin >> y;
  int ord = 2 * x + 5;
  if (y == ord)
  {
    cout << "true";
  }
  else{
    cout << "false";
  }

}
