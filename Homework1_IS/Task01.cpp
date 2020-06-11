#include <iostream>
using namespace std;

int main()
{
  int count = 0;
  int number = 2520;
  while(count != 18)
  {
    for(int i = 1; i <= 18; i++)
    {

      if (number % i == 0)
      {
        count++;
      }
      else
      {
        number++;
        count = 0;
        break;
      }
    }
  }

  cout << number << endl;
}
