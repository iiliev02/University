#pragma once
#include "Ship.h"
#include <cassert>
class Navy {
private:
    char* country;
    Ship* ship;
    int capacity;
    int count;
public:
    Navy(const char* = "New country");
    Navy(const char*, int capacity);
    Navy(const Navy&);
    Navy& operator=(const Navy&);
    ~Navy();

    Navy& operator+(const Ship&);
    Navy& operator+=(const Ship&);
    int operator-(const Ship&);
    int operator-=(const Ship&);
    Ship& operator[](int index);
    bool operator<(Navy);

    void setCountry(const char* country);

    const char* getCountry() const;
    int getCount() const;
    int getCapacity() const;
    friend ostream& operator<<(ostream&, const Navy&);


};
Navy::Navy(const char* country): count(0), capacity(0) {
    this->country = new char[strlen(country) + 1];
    strcpy(this->country, country);
    this->ship = nullptr;
}

Navy::Navy(const char* country, int newCapacity): count(0), capacity(newCapacity) {
    this->country = new char[strlen(country) + 1];
    strcpy(this->country, country);
    this->ship = new Ship[this->capacity];
}

Navy::Navy(const Navy& other): count(other.count), capacity(other.capacity) {
    this->country = new char[strlen(other.country) + 1];
    strcpy(this->country, other.country);
    this->ship = new Ship[this->capacity];
    for(size_t i = 0; i < this->count; i++)
    {
        this-> ship[i] = other.ship[i];
    }
}

Navy& Navy::operator=(const Navy& other) {
    if (this != &other) {
        delete[] this->country;
        this->country = new char[strlen(other.country) + 1];
        strcpy(this->country, other.country);

        delete[] this->ship;

        this->capacity = other.capacity;
        this->count = other.count;
        this->ship = new Ship[this->capacity];
        for(size_t i = 0; i< this->count; i++)
        {
            this->ship[i] = other.ship[i];
        }
    }
    return *this;
}

Navy::~Navy() {
    delete[] this->country;
    delete[] this->ship;

    this->country = nullptr;
    this->ship = nullptr;
}

Navy& Navy::operator+(const Ship& ship) {
    if(this->count >= this->capacity)
    {
        int newCapacity = this->capacity == 0? 2 : this->capacity * 2;

        Ship* ships = new Ship[newCapacity];
        for (size_t i = 0; i < this->count; ++i) {
            ships[i] = this->ship[i];
        }

        delete[] this->ship;
        this->ship = ships;
        this->capacity = newCapacity;
    }
    this->ship[this->count] = ship;
    ++this->count;
    return *this;
}

Navy &Navy::operator+=(const Ship &ship) {
    if(this->count >= this->capacity)
    {
        int newCapacity = this->capacity == 0? 2 : this->capacity * 2;

        Ship* ships = new Ship[newCapacity];
        for (size_t i = 0; i < this->count; ++i) {
            ships[i] = this->ship[i];
        }

        delete[] this->ship;
        this->ship = ships;
        this->capacity = newCapacity;
    }
    this->ship[this->count] = ship;
    ++this->count;
    return *this;;
}


int Navy::operator-(const Ship &ship) {
    return this->count--;
}

int Navy::operator-=(const Ship &ship) {
    return this->count--;
}

Ship& Navy::operator[](int index) {
    if(index < this->count)
    {
        assert(index < this->count);
        return this->ship[index];
    }
    else
    {
        cout << "The value of index is greater than numbers of ships in this country..." << endl;
    }
}

bool Navy::operator<(Navy secondNavy){
    int firstNavyGuns = 0;
    int secondNavyGuns = 0;
    for(size_t i = 0; i < this->count; i++)
    {
        firstNavyGuns += this->ship[i].getNumberOfGuns();
    }
    for(size_t i = 0; i < secondNavy.count; i++)
    {
        secondNavyGuns += secondNavy.ship[i].getNumberOfGuns();
    }
    if(firstNavyGuns < secondNavyGuns)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const char* Navy::getCountry() const {
    return this->country;
}

int Navy::getCount() const {
    return this->count;
}

int Navy::getCapacity() const {
    return this->capacity;
}


void Navy::setCountry(const char *country) {
    delete[] this->country;
    this->country = new char[strlen(country) + 1];
    strcpy(this->country, country);
}

ostream& operator<<(ostream& output, const Navy& Navy)
{
    output << "Country: " << Navy.country << endl;
    for(size_t i = 0; i < 20; i++) output << "-";
    output << endl;
    for(size_t i = 0; i < Navy.count; ++i)
    {
        output << "Ship " << i + 1 << endl;
        output << "Name of Ship: " << Navy.ship[i].getNameOfShip() << endl;
        output << "Year of Exploitation: " << Navy.ship[i].getYearOfExploitation() << endl;
        output << "Class of Ship: " << Navy.ship[i].getClassOfShip()<< endl;
        output << "Number of Guns: " << Navy.ship[i].getNumberOfGuns() << endl;
        output << endl;
    }
    for(size_t i = 0; i < 20; i++) output << "-";
    output << endl;
    return output;
}
