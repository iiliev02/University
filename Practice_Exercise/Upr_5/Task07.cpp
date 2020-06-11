#include <iostream>
using namespace std;

int main()
{
  int column, row;
  cin >> row >> column;
  int array[row][column];
  int powArray[row][column];
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < column; j++)
    {
      cin >> array[i][j];
    }
  }
  for(int z = 0; z < row; z++)
  {
    for(int q = 0; q < column; q++)
    {
      powArray[z][q] = array[z][q] * array[z][q];
    }
  }
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
      cout << powArray[i][j] << " ";
      if(j == column - 1) cout << endl;

    }
  }
}
