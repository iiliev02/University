#include <iostream>
using namespace std;

const int sizeOfMatrix = 4;

int main()
{
    int matrix[sizeOfMatrix][sizeOfMatrix];
    int sumOfColm = 0, sumOfSecondDiagonal = 0;
    bool isMagicMatrix = true;
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] < 1 || matrix[i][j] > 20)
            {
                cout << "Invalid number for matrix!!! Please, enter number less than 20 and more than 1..." << endl;
                exit(1);
            }
        }
    }


    for (int i = sizeOfMatrix - 1; i >= 0; i--)
    {
        sumOfSecondDiagonal += matrix[sizeOfMatrix - i - 1][i];
    }


    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            sumOfColm += matrix[j][i];
        }
        if (sumOfColm != sumOfSecondDiagonal)
        {
            isMagicMatrix = false;
            break;
        }
        else
        {
            sumOfColm = 0;
        }
    }

    if (isMagicMatrix == true)
    {
        cout << "The matrix is magic!!!" << endl;
    }
    else
    {
        cout << "The matrix is not magic!!!" << endl;
    }

}