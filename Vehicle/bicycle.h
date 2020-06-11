#pragma once
#include "vehicle.h"


class Bicycle : public Vehicle {
private:
    int gears;
    bool lights;
    bool reflectors;
    bool bell;
public:
    Bicycle();
    Bicycle(const char*, const char*, int, int, int, int, bool, bool, bool);
    Bicycle(const Bicycle&);
    Bicycle& operator=(const Bicycle&);
    ~Bicycle();

    void setGears(const int gears);
    void setLights(const bool light);
    void setReflectors(const bool reflectors);
    void setBell(const bool bell);

    int getGears() const;
    bool getLights() const;
    bool getReflectors() const;
    bool getBell() const;

    void information() const {
        cout << "This is one of the best bicycle we have. You will be very pleased with it." << endl;
    }

    friend ostream& operator<<(ostream&, const Bicycle&);
};
Bicycle::Bicycle() : Vehicle() {
    this->gears = 0;
    this->lights = false;
    this->reflectors = false;
    this->bell = false;
}

Bicycle::Bicycle(const char* color, const char* brand, int yearOfProduction, int passengers, int topSpeed, int gears, bool lights, bool reflectors, bool bell) : Vehicle(color, brand, yearOfProduction, passengers, topSpeed) {
    this->gears = gears;
    this->lights = lights;
    this->reflectors = reflectors;
    this->bell = bell;
}

Bicycle::Bicycle(const Bicycle& other) : Vehicle(other) {
    this->gears = other.gears;
    this->lights = other.lights;
    this->reflectors = other.reflectors;
    this->bell = other.bell;
}

Bicycle& Bicycle::operator=(const Bicycle& other) {
    if (this != &other) {
        Vehicle::operator=(other);

        this->gears = other.gears;
        this->lights = other.lights;
        this->reflectors = other.reflectors;
        this->bell = other.bell;
    }
    return *this;
}

Bicycle::~Bicycle() {
}

int Bicycle::getGears() const {
    return this->gears;
}

bool Bicycle::getLights() const {
    return this->lights;
}

bool Bicycle::getReflectors() const {
    return this->reflectors;
}

bool Bicycle::getBell() const {
    return this->bell;
}

void Bicycle::setGears(const int gears) {
    this->gears = gears;
}

void Bicycle::setLights(const bool light) {
    this->lights = light;
}

void Bicycle::setReflectors(const bool reflectors) {
    this->reflectors = reflectors;
}

void Bicycle::setBell(const bool bell) {
    this->bell = bell;
}

ostream& operator<<(ostream& output, const Bicycle& Bicycle)
{
    output << "Color: " << Bicycle.getColor() << endl;
    output << "Brand: " << Bicycle.getBrand() << endl;
    output << "Year of Production: " << Bicycle.getYearOfProduction() << endl;
    output << "Gears: " << Bicycle.gears << endl;
    output << "Top Speed: " << Bicycle.getTopSpeed() << endl;
    output << "Lights: " << boolalpha <<Bicycle.lights << endl;
    output << "Reflectors: " << boolalpha << Bicycle.reflectors << endl;
    output << "Bell: " << boolalpha << Bicycle.bell << endl;
    return output;
}
