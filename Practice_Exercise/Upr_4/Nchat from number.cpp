#include <iostream>
using namespace std;
int main()
{
  int num, Nnum;
  cout << "Number: ";
  cin >> num;
  while (num != 0) {
    num = num / 10;
    Nnum++;
  }
}
