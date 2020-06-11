#include <iostream>

using namespace std;

int main()
{
  int first, second;
  cin >> first;
  cin >> second;
  if (second % first == 0) {
    cout << "true";
  }
  else{
    cout << "false";
  }
}
