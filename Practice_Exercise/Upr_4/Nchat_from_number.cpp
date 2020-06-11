#include <iostream>
using namespace std;
int main()
{
  int num, Nnum = 0;
  cout << "Number: ";
  cin >> num;
  while (num != 0) {
    num /= 10;
    Nnum += 1;
  }
  cout << Nnum;
}
