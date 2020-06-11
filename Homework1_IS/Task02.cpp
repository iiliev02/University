#include <iostream>
using namespace std;

int main()
{
  int hour, day;
  double price;
  cout << "Day: ";
  cin >> day;
  cout << "Hours: ";
  cin >> hour;
  switch (day) {
    case 1: price = hour * 4.50; break;
    case 2: price = hour * 6; break;
    case 3: price = hour * 4.50; break;
    case 4: price = hour * 6; break;
    case 5: price = hour * 6; break;
    case 6: price = hour * 8.25; break;
    case 7: price = hour * 8.25; break;
    default: cout << "Invalid day!!!"<< endl; break;
  }
  cout << "Traicho has to pay: " << price << "lv." << endl;
}
