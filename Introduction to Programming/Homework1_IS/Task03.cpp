#include <iostream>
using namespace std;

int main()
{
  int number, copyOfNumber, countDigit = 0, sum = 0, middleElement;
  cout << "Enter a number: ";
  cin >> number;
  copyOfNumber = number;
  while (number != 0)
  {
    number /= 10;
    countDigit++;
  }
  int array[countDigit];
  for (int i = 0; i < countDigit; i++)
  {
    array[i] = copyOfNumber % 10;
    copyOfNumber /= 10;
  }
  if (countDigit % 2 == 0)
  {
    for(int z = 0; z < countDigit / 2; z++)
    {
      sum += array[z] * array[countDigit - z - 1];
    }
  }
  else
  {
    for(int z = 0; z < countDigit / 2; z++)
    {
      sum += array[z] * array[countDigit - z - 1];
    }
    middleElement = array[countDigit / 2] * array[countDigit / 2];
    sum += middleElement;
  }
  cout << "Sum = " << sum;
}
