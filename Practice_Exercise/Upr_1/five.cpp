#include <iostream>
using namespace std;
int main()
{
  int n, reNumber = 0, rn;
  cin >> n;
  while (n != 0) {
    rn = n % 10;
    reNumber = reNumber * 10 + rn;
    n /= 10;
  }
  cout << reNumber;
}
