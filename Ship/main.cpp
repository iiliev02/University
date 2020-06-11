#include <iostream>
#include "Ship.h"
#include "Navy.h"
#include <algorithm>

using namespace std;

bool compareNaviesWeapons(Navy first, Navy second){
    return first < second;
}

void compare(Navy firstNavy, Navy secondNavy)
{
    if(firstNavy < secondNavy == true)
    {
        cout << "This is true. The country " << firstNavy.getCountry() << " have fewer guns than the country " << secondNavy.getCountry() << endl;
        cout << endl;
    }
    else
    {
        cout << "This is false. The country " << firstNavy.getCountry() << " have greater guns than the country " << secondNavy.getCountry() << endl;
        cout << endl;
    }
}

int main() {
    Ship usaShip("USS Bunker Hill", 1986, "bc", 52); // Създавене на кораб
    Ship rusShip1("Vice-Admiral Kulakov", 1982, "bb", 57);
    Ship chiShip2("ROCS Su Ao", 1978, "bb", 60);
    Ship bulShip3("Smeli", 1989, "bc", 32);
    Ship rusShip4("Admiral Levchenko", 1988, "bb", 24);
    Navy USA("USA"); // Създаване на военоморски флот
    USA += usaShip; // Добавяне на кораб във военоморския флот
    Navy Russia("Russia");
    Russia + rusShip1;
    Russia += rusShip4;
    Navy China("China");
    China += chiShip2;
    Navy Bulgaria("Bulgaria");
    Bulgaria += bulShip3;

    cout << Russia << endl;
    cout << usaShip << endl;
    cout << USA << endl;
    compare(USA, Russia); // Сравняване на два военоморски флота по общия брой оръдия, като във функцията се използва оператора <.
    compare(China, Bulgaria); // Сравняване на два военоморски флота по общия брой оръдия, като във функцията се използва оператора <.

    Navy* navies = new Navy[4];
    navies[0] = USA;
    navies[1] = Russia;
    navies[2] = China;
    navies[3] = Bulgaria;
    sort(navies, navies + 4, compareNaviesWeapons); // Сортира на масива с военоморски флотове по общия брой оръдия на флота.
    for (int i = 0; i < sizeof(navies); ++i) {
        cout << navies[i] << endl;
    }
}
