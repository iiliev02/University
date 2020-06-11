#pragma once
#include "vehicle.h"
class Car : public Vehicle {
private:
    char* model;
    int carDoors;
    int horsepowers;
public:
    Car();
    Car(const char*, const char*, int, int, int, const char*, int, int);
    Car(const Car&);
    Car& operator=(const Car&);
    ~Car();

    void setModel(const char* model);
    void setCarDoors(const int carDoors);
    void setHorsepowers(const int horsepowers);

    const char* getModel() const;
    int getCarDoors() const;
    int getHorsepowers() const;

    void information() const {
        cout << "That's the full info on the car, sir. If you want to buy one, we can make a special offer just for you." << endl;
    }

    friend ostream& operator<<(ostream&, const Car&);
};
Car::Car() : Vehicle() {
    this->model = nullptr;
    this->carDoors = 0;
    this->horsepowers = 0;
}

Car::Car(const char* color, const char* brand, int yearOfProduction, int passengers, int topSpeed, const char* model, int carDoors, int horsepowers) : Vehicle(color, brand, yearOfProduction, passengers, topSpeed) {
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    this->carDoors = carDoors;
    this->horsepowers = horsepowers;
}

Car::Car(const Car& other) : Vehicle(other) {
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);
    this->carDoors = other.carDoors;
    this->horsepowers = other.horsepowers;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        delete[] this->model;

        this->model = new char[strlen(other.model) + 1];
        strcpy(this->model, other.model);
        this->carDoors = other.carDoors;
        this->horsepowers = other.horsepowers;
    }
    return *this;
}

Car::~Car() {
    delete[] this->model;
}

const char* Car::getModel() const {
    return this->model;
}

int Car::getCarDoors() const {
    return this->carDoors;
}

int Car::getHorsepowers() const {
    return this->horsepowers;
}

void Car::setModel(const char *model) {
    delete[] this->model;
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}

void Car::setCarDoors(const int carDoors) {
    this->carDoors = carDoors;
}

void Car::setHorsepowers(const int horsepowers) {
    this->horsepowers = horsepowers;
}

ostream& operator<<(ostream& output, const Car& Car)
{
    output << "Color: " << Car.getColor() << endl;
    output << "Brand: " << Car.getBrand() << endl;
    output << "Model: " << Car.model << endl;
    output << "Year of Production: " << Car.getYearOfProduction() << endl;
    output << "Horsepowers: " << Car.horsepowers << endl;
    output << "Top Speed: " << Car.getTopSpeed() << endl;
    output << "Car Doors: " << Car.carDoors << endl;
    output << "Passengers: " << Car.getPassengers() << endl;
    return output;
}