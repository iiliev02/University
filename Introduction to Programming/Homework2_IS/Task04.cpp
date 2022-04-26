#include <iostream>
using namespace std;

int main()
{
    int n, sizeOfMatrix;
    cout << "N = ";
    cin >> n;
    int matrix[100][100];
    cout << "Enter size of matrix: ";
    cin >> sizeOfMatrix;
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int z = 0; z < n; z++)
    {
        int leftUpNumber = matrix[0][0];
        int leftDownNumber = matrix[sizeOfMatrix - 1][0];
        int rightUpNumber = matrix[0][sizeOfMatrix - 1];
        int rightDownNumber = matrix[sizeOfMatrix - 1][sizeOfMatrix - 1];
        matrix[0][0] = leftDownNumber;
        matrix[0][sizeOfMatrix - 1] = leftUpNumber;
        matrix[sizeOfMatrix - 1][sizeOfMatrix - 1] = rightUpNumber;
        matrix[sizeOfMatrix - 1][0] = rightDownNumber;
    }
    if (sizeOfMatrix >= 4)
    {
        for (int z = 0; z < n; z++)
        {
            int leftUpNumber = matrix[1][1];
            int leftDownNumber = matrix[sizeOfMatrix - 2][1];
            int rightUpNumber = matrix[1][sizeOfMatrix - 2];
            int rightDownNumber = matrix[sizeOfMatrix - 2][sizeOfMatrix - 2];
            matrix[1][1] = rightUpNumber;
            matrix[1][sizeOfMatrix - 2] = rightDownNumber;
            matrix[sizeOfMatrix - 2][sizeOfMatrix - 2] = leftDownNumber;
            matrix[sizeOfMatrix - 2][1] = leftUpNumber;
        }
    }
    cout << endl;
    cout << "Обработена матрица: " << endl;
    cout << endl;
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}