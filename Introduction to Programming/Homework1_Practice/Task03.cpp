#include <iostream>
using namespace std;

int main()
{
  long long cardNumber, countDigit = 0, copyOfCardNumber, sum = 0;
  cout << "Enter a card number: ";
  cin >> cardNumber;
  copyOfCardNumber = cardNumber;
  while(copyOfCardNumber != 0)
  {
    copyOfCardNumber /= 10;
    countDigit++;
  }
  int array[countDigit];
  for(int i = 0; i < countDigit; i++)
  {
    array[i] = cardNumber % 10;
    cardNumber /= 10;
  }

  if(countDigit % 2 == 0)
  {
    for(int z = 0; z < countDigit; z++)
    {
      if(z % 2 == 0)
      {
        sum += (array[z] * array[z]);
      }
      else
      {
        sum += array[z];
      }
    }
    if (sum % 3 != 0) cout << "Fake credit card!" << endl;
    else cout << "Valid credit card!" << endl;
  }
  else cout << "Fake credit card!" << endl;
}
