#include <iostream>
using namespace std;
int main()
{
  int number, sum = 0, count, ave;
  for(int i = 0; i <= 200; i++)
  {
    cin >> number;
    if (number < 1)
    {
      break;
    }
    sum = sum + number;
    count += 1;
  }
  cout << "count = " << count;
  cout << "sum = " << sum;
}
