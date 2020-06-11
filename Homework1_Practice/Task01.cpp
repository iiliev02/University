#include <iostream>
using namespace std;

int main()
{
  int n, leftRotation;
  cin >> n >> leftRotation;
  int array[n];
  for(int i = 0; i < n; i++)
  {
    cin >> array[i];
  }
  for(int z = 0; z < n; z++)
  {
    cout << array[(z + leftRotation) % n] << " ";
  }
}
