#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
  int num, k, rnum;
  cout << "Number = ";
  cin >> num;
  cout << "K = ";
  cin >> k;
  /*
  while(k != 0)
  {
  rnum =  num % 10;
  num /= 10;
  k -= 1;
  }
  cout << rnum;
  */
  cout << (num % ( (int) pow (10, k))) / (int) pow(10, k - 1);
}
