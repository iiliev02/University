#include <iostream>
#include "car.h"
#include "bicycle.h"
using namespace std;

int main() {
    Vehicle car("Grey", "Ford", 2019, 4, 320);
    Vehicle car1 = car;
    car1.setColor("Red");
    car1.setYearOfProduction(1967);
    cout << car1 << endl;
    car1.information();
    cout << endl;
    Car one("Black", "Mercedes", 2018, 4, 290, "SLS AMG", 2, 500);
    Car two = one;
    two.setPassengers(2);
    two.setModel("C 63 S");
    two.setHorsepowers(510);
    cout << two << endl;
    two.information();
    cout << endl;
    Bicycle bicycle("Red", "Balkan", 1990, 1, 20, 1, false, false, true);
    Bicycle bicycle1 = bicycle;
    bicycle1.setColor("Blue");
    bicycle1.setLights(true);
    bicycle1.setBell(false);
    cout << bicycle1 << endl;
    bicycle1.information();
    return 0;
}
