#pragma once
#include<iostream>
#include<cstring>

using namespace std;
class Ship {
private:
    char* nameOfShip;
    int yearOfExploitation;
    string classOfShip;
    int numberOfGuns;

public:
    Ship();
    Ship(const char*, int, string, int);
    Ship(const Ship& other);
    Ship& operator=(const Ship&);
    ~Ship();


    void setNameOfShip(const char* nameOfShip);
    void setYearOfExploitation(const int yearOfExploitation);
    void setClassOfShip(const string classOfShip);
    void setNumberOfGuns(const int numberOfGuns);


    const char* getNameOfShip()const;
    int getYearOfExploitation() const;
    string getClassOfShip() const;
    int getNumberOfGuns() const;
    friend ostream& operator<<(std::ostream&, const Ship&);
};

Ship::Ship() {
    this->nameOfShip = nullptr;
    this->yearOfExploitation = 0;
    this->classOfShip = "";
    this->numberOfGuns = 0;
}

Ship::Ship(const char* nameOfShip, int yearOfExploitation, string classOfShip, int numberOfGuns) {
    this->nameOfShip = new char[strlen(nameOfShip) + 1];
    strcpy(this->nameOfShip, nameOfShip);
    if(yearOfExploitation > 1940 || yearOfExploitation == 0)
    {
        this->yearOfExploitation = yearOfExploitation;
    }
    else
    {
        cout << "The year must be greater than 1940..." << endl;
        exit(1);
    }
    if(classOfShip == "bb" || classOfShip == "bc" || classOfShip == "")
    {
        this->classOfShip = classOfShip;
    }
    else
    {
        cout << "Valid values are only 'bb' (battleship) and 'bc' (battlecruiser)..." << endl;
        exit(1);
    }
    this->numberOfGuns = numberOfGuns;
}

Ship::Ship(const Ship& other) {
    this->nameOfShip = new char[strlen(other.nameOfShip) + 1];
    strcpy(this->nameOfShip, other.nameOfShip);
    if(yearOfExploitation > 1940 || yearOfExploitation == 0)
    {
        this->yearOfExploitation = other.yearOfExploitation;
    }
    else
    {
        cout << "The year must be greater than 1940..." << endl;
        exit(1);
    }
    if(classOfShip == "bb" || classOfShip == "bc" || classOfShip == "")
    {
        this->classOfShip = other.classOfShip;
    }
    else
    {
        cout <<"Valid values are only 'bb' (battleship) and 'bc' (battlecruiser)..." << endl;
        exit(1);
    }
    this->numberOfGuns = other.numberOfGuns;
}

Ship& Ship::operator=(const Ship& other) {
    if (this != &other) {
        delete[] this->nameOfShip;
        this->nameOfShip = new char[strlen(other.nameOfShip) + 1];
        strcpy(this->nameOfShip, other.nameOfShip);
        if(yearOfExploitation > 1940 || yearOfExploitation == 0)
        {
            this->yearOfExploitation = other.yearOfExploitation;
        }
        else
        {
            cout << "The year must be greater than 1940..." << endl;
            exit(1);
        }
        if(classOfShip == "bb" || classOfShip == "bc" || classOfShip == "")
        {
            this->classOfShip = other.classOfShip;
        }
        else
        {
            cout <<"Valid values are only 'bb' (battleship) and 'bc' (battlecruiser)..." << endl;
            exit(1);
        }
        this->numberOfGuns = other.numberOfGuns;
    }
    return *this;
}

Ship::~Ship() {
    delete[] this->nameOfShip;
}

const char* Ship::getNameOfShip() const {
    return this->nameOfShip;
}

int Ship::getYearOfExploitation() const {
    return this->yearOfExploitation;
}

string Ship::getClassOfShip() const {
    return this->classOfShip;
}

int Ship::getNumberOfGuns() const {
    return this->numberOfGuns;
}

void Ship::setNameOfShip(const char *nameOfShip) {
    delete[] this->nameOfShip;
    this->nameOfShip = new char[strlen(nameOfShip) + 1];
    strcpy(this->nameOfShip, nameOfShip);
}

void Ship::setYearOfExploitation(const int yearOfExploitation) {
    if(yearOfExploitation > 1940 || yearOfExploitation == 0)
    {
        this->yearOfExploitation = yearOfExploitation;
    }
    else
    {
        cout << "The year must be greater than 1940..." << endl;
        exit(1);
    }
}

void Ship::setClassOfShip(const string classOfShip) {
    if(classOfShip == "bb" || classOfShip == "bc" || classOfShip == " ")
    {
        this->classOfShip = classOfShip;
    }
    else
    {
        cout <<"Valid values are only 'bb' (battleship) and 'bc' (battlecruiser)..." << endl;
        exit(1);
    }
}

void Ship::setNumberOfGuns(const int numberOfGuns) {
    this->numberOfGuns = numberOfGuns;
}

ostream& operator<<(std::ostream& output, const Ship& Ship)
{
    output << "Name of Ship: " << Ship.nameOfShip << endl;
    output << "Year of Exploitation: " << Ship.yearOfExploitation << endl;
    output << "Class of Ship: " << Ship.classOfShip << endl;
    output << "Number of Guns: " << Ship.numberOfGuns << endl;
    return output;
}
