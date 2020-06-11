#include <iostream>
using namespace std;
int main ()
{
  int number;
  cout << "Enter a number: ";
  cin >> number;
  if (number < 10 || number > 200)
  {
    cout << "The number is not valid";
    exit(0);
  }
  for (int i = number; i >= 0; i -= 1)
  {
    if (i % 7 == 0)
    {
      cout << i << " ";
    }
    else if (i < 10)
    {
      break;
    }
    else continue;
  }
}
