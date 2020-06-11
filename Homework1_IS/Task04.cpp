#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string r;
	int n, minNumber, maxNumber, remainder, reversedNumber = 0, sum = 0, num;
	cin >> minNumber >> maxNumber;
	for (int i = minNumber; i <= maxNumber; i++)
	{
		n = i;
		while (n != 0)
		{
			r = (n % 2 == 0 ? "0" : "1") + r;
			n /= 2;
		}
		num = i;
		while (num != 0)
		{
			remainder = num % 10;
			reversedNumber = (reversedNumber * 10) + remainder;
			num /= 10;
		}
		string reversedR = r;
    reverse(reversedR.begin(), reversedR.end());

		if(i == reversedNumber && r == reversedR)
		{
		  sum += i;
		}
		reversedNumber = 0;
		r.clear();
	}
	cout << "Sum = " << sum << endl;
}
