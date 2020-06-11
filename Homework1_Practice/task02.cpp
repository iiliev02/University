#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "N = ";
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    if (i % 2 == 0)
    {
      cout << "|";
      for(int j = 1; j <= n / 2; j++) cout << " #";
      if (n % 2 != 0) cout << " ";
      cout << "|" << endl;
    }
    else
    {
      cout << "|";
      for(int j = 1; j <= n / 2; j++) cout << "# ";
      if (n % 2 != 0) cout << "#";
      cout << "|" << endl;
    }
  }
}
