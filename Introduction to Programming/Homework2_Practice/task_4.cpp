#include <iostream>
using namespace std;

const int maxSize = 100;
int paskalMatrix[maxSize][maxSize];
int indexColm = 1;
int countNumberByLine = 1;

void trianglePaskal()
{
    for (int i = 2; i < maxSize; i++)
    {
        indexColm = 1;
        for (int j = 0; j < countNumberByLine; j++)
        {
            paskalMatrix[i][indexColm] = paskalMatrix[i - 1][indexColm - 1] + paskalMatrix[i - 1][indexColm];
            indexColm++;
        }
        countNumberByLine++;
    }
}

void checkSizeOfK(int k)
{
    if (k > maxSize)
    {
        cout << "You entered an invalid number!!! Please, enter another value for k..." << endl;
        exit(1);
    }
}
int main()
{
    int k;
    cout << "Enter a value for k: ";
    cin >> k;
    checkSizeOfK(k);
    for (int i = 0; i < maxSize; i++)
    {
        paskalMatrix[i][0] = paskalMatrix[i][i] = 1;
    }
    trianglePaskal();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < maxSize; j++)
        {
            if(paskalMatrix[i][j] != 0)
            cout << paskalMatrix[i][j] << " ";
        }
        cout << endl;
    }
}