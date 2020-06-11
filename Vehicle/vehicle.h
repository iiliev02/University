#pragma once
#include<iostream>
#include<cstring>

using namespace std;
class Vehicle {
private:
    char* color;
    char* brand;
    int yearOfProduction;
    int passengers;
    int topSpeed;

public:
    Vehicle();
    Vehicle(const char*, const char*, int, int, int);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle&);
    ~Vehicle();

    virtual void information() const {
        cout << "Please enter more information about the car..." << endl;
    }

    void setColor(const char* color);
    void setBrand(const char* brand);
    void setYearOfProduction(const int yearOfProduction);
    void setPassengers(const int passengers);
    void setTopSpeed(const int topSpeed);


    const char* getColor()const;
    const char* getBrand()const;
    int getYearOfProduction() const;
    int getPassengers() const;
    int getTopSpeed() const;

    friend ostream& operator<<(std::ostream&, const Vehicle&);
};

Vehicle::Vehicle() {
    this->color = nullptr;
    this->brand = nullptr;
    this->yearOfProduction = 0;
    this->passengers = 0;
    this->topSpeed = 0;
}

Vehicle::Vehicle(const char* color, const char* brand, int yearOfProduction, int passengers, int topSpeed) {
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->yearOfProduction = yearOfProduction;
    this->passengers = passengers;
    this->topSpeed = topSpeed;
}

Vehicle::Vehicle(const Vehicle& other) {
    this->color = new char[strlen(other.color) + 1];
    strcpy(this->color, other.color);
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);
    this->yearOfProduction = other.yearOfProduction;
    this->passengers = other.passengers;
    this->topSpeed = other.topSpeed;
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        delete[] this->color;
        delete[] this->brand;
        this->color = new char[strlen(other.color) + 1];
        strcpy(this->color, other.color);
        this->brand = new char[strlen(other.brand) + 1];
        strcpy(this->brand, other.brand);
        this->yearOfProduction = other.yearOfProduction;
        this->passengers = other.passengers;
        this->topSpeed = other.topSpeed;
    }
    return *this;
}

Vehicle::~Vehicle() {
    delete[] this->color;
    delete[] this->brand;
}

const char* Vehicle::getColor() const {
    return this->color;
}

const char* Vehicle::getBrand() const {
    return this->brand;
}

int Vehicle::getYearOfProduction() const {
    return this->yearOfProduction;
}

int Vehicle::getPassengers() const {
    return this->passengers;
}

int Vehicle::getTopSpeed() const {
    return this->topSpeed;
}

void Vehicle::setColor(const char *color) {
    delete[] this->color;
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

void Vehicle::setBrand(const char *brand) {
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

void Vehicle::setYearOfProduction(const int yearOfProduction) {
    this->yearOfProduction = yearOfProduction;
}

void Vehicle::setPassengers(const int passengers) {
    this->passengers = passengers;
}

void Vehicle::setTopSpeed(const int topSpeed) {
    this->topSpeed = topSpeed;
}

ostream& operator<<(std::ostream& output, const Vehicle& Vehicle)
{
    output << "Color: " << Vehicle.color << endl;
    output << "Brand: " << Vehicle.brand << endl;
    output << "Year of Production: " << Vehicle.yearOfProduction << endl;
    output << "Passengers: " << Vehicle.passengers << endl;
    output << "Top Speed: " << Vehicle.topSpeed << endl;
    return output;
}



