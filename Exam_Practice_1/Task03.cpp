#include <iostream>
using namespace std;

int main()
{
	int sizeMatrix, sumOfNegative = 0, sumOfPositive = 0, sumOfNegative2 = 0, sumOfPositive2 = 0;
	cout << "Enter matrix size: ";
	cin >> sizeMatrix;
	int matrix[100][100];
	if (sizeMatrix > 100)
	{
		cout << "Invalid solution" << endl;
		exit(0);
	}
	cout << "Enter matrix: " << endl;
	for (int i = 0; i < sizeMatrix; i++)
	{
		for (int j = 0; j < sizeMatrix; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] < -999 || matrix[i][j] > 999)
			{
				cout << "Invalid number!!!" << endl;
				exit(20);
			}
		}
	}
	for (int i = 0; i < sizeMatrix - 1; i++)
	{
		for (int j = i + 1; j < sizeMatrix; j++)
		{
			if (matrix[i][j] > 0)
			{
				sumOfPositive += matrix[i][j];
			}
		}
	}
	for(int z = sizeMatrix - 1; z > 0; z--)
	{
		for (int a = 0; a < z; a++)
		{
			if (matrix[z][a] < 0)
			{
				sumOfNegative += matrix[z][a];
			}
		}
	}
	for (int z = sizeMatrix - 1; z > 0; z--)
	{
		for (int a = sizeMatrix - 1; a >= sizeMatrix - z; a--)
		{
			if (matrix[z][a] > 0)
			{
				sumOfPositive2 += matrix[z][a];
			}
		}
	}
	for (int i = 0; i < sizeMatrix - 1; i++)
	{
		for (int j = 0; j < sizeMatrix - 1 - i; j++)
		{
			if (matrix[i][j] < 0)
			{
				sumOfNegative2 += matrix[i][j];
			}
		}
	}
	cout << sumOfPositive2 << endl;
	cout << sumOfNegative2 << endl;
	cout << "Sum of negagtive elements: " << sumOfNegative << endl;
	cout << "Sum of positive elements: " << sumOfPositive << endl;
}
