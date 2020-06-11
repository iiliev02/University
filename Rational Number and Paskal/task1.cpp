#include <iostream>
using namespace std;

int indexColm = 1;
int countNumberByLine = 1;
int **paskalMatrix;

int** Allocate(int k)
{
    int rowCount = k;
    int** paskalMatrix = new int*[rowCount];
    for(int i = 0; i < rowCount; ++i)
    {
        paskalMatrix[i] = new int[rowCount];
    }

    for (int i = 0; i < k; i++)
    {
        paskalMatrix[i][0] = paskalMatrix[i][i] = 1;
    }

    for (int i = 2; i < k; i++)
    {
        indexColm = 1;
        for (int j = 0; j < countNumberByLine; j++)
        {
            paskalMatrix[i][indexColm] = paskalMatrix[i - 1][indexColm - 1] + paskalMatrix[i - 1][indexColm];
            indexColm++;
        }
        countNumberByLine++;
    }

    return paskalMatrix;
}

void Deallocate(int** twoDimensionArray, int k){
    for(int i = 0; i < k; ++i) {
        delete [] twoDimensionArray[i];
    }
    delete [] twoDimensionArray;
}


void Print(int** array, int k){
    for (int i = 0; i < k; i++)
    {
        cout << "[" << i << "] ";
        for (int j = 0; j <= i; j++)
        {
            if(array[i][j] != 0)
                cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int k;
    cout << "Enter a value for k: ";
    cin >> k;

    paskalMatrix = Allocate(k);
    Print(paskalMatrix,k);
    Deallocate(paskalMatrix,k);
}