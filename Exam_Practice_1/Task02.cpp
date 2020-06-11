#include <iostream>
using namespace std;

int main()
{
	int n, m, indexThirdArray = 0;
	cout << "N = ";
	cin >> n;
	if (n < 5 || n > 105)
	{
		cout << "Invalid number!!!" << endl;
		exit(0);
	}
	cout << "Enter first array: ";
	int *firstArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> firstArray[i];
	}
	cout << "M = ";
	cin >> m;
	if (m < 5 || m > 105)
	{
		cout << "Invalid number!!!" << endl;
		exit(0);
	}
	cout << "Enter second array: ";
	int *secondArray = new int[m];
	for (int j = 0; j < m; j++)
	{
		cin >> secondArray[j];
	}
	int* thirdArray = new int[n + m];
	for (int z = 0; z < n; z++)
	{
		if (firstArray[z] % 2 == 0)
		{
			thirdArray[indexThirdArray] = firstArray[z];
			indexThirdArray++;
		}
	}
	for (int a = 0; a < m; a++)
	{
		if (secondArray[a] % 2 == 0)
		{
			thirdArray[indexThirdArray] = secondArray[a];
			indexThirdArray++;
		}
	}
	for (int z = 0; z < n; z++)
	{
		if (firstArray[z] % 2 != 0)
		{
			thirdArray[indexThirdArray] = firstArray[z];
			indexThirdArray++;
		}
	}
	for (int a = 0; a < m; a++)
	{
		if (secondArray[a] % 2 != 0)
		{
			thirdArray[indexThirdArray] = secondArray[a];
			indexThirdArray++;
		}
	}
	cout << "Third Array: ";
	for (int q = 0; q < indexThirdArray; q++)
	{
		cout << thirdArray[q] << " ";
	}
	cout << endl;
}
