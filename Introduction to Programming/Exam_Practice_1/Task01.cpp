#include <iostream>
using namespace std;

int main()
{
	int num1, num2, count5 = 0;
	cout << "Number_1 = ";
	cin >> num1;
	cout << "Number_2 = ";
	cin >> num2;
	if (num1 < 10 || num2 > 1000)
	{
		cout << "Invalid number!!!" << endl;
		exit(0);
	}
	for (int i = num1; i <= num2; i++)
	{
		int copyOfI = i;
		while (copyOfI != 0)
		{
			if (copyOfI % 10 == 5) count5++;
			copyOfI /= 10;
		}
	}
	cout << count5 << endl;
}

