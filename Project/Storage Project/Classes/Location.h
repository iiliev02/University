#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Location {
private:
	int section;
	string shelf;
	string number;

public:
	Location();
	Location(int, string, string);
	Location(const Location& other);
	Location& operator=(const Location&);
	~Location();

	void setSection(const int section);
	void setShelf(string shelf);
	void setNumber(string number);

	int getSection() const;
	string getShelf() const;
	string getNumber() const;

	friend bool operator==(const Date&, const Date&);
	friend ostream& operator<<(std::ostream&, const Location&);
};

Location::Location() {
	this->section = 0;
	this->shelf;
	this->number;
}

Location::Location(int section, string shelf, string number) {
	this->section = section;
	this->shelf = shelf;
	this->number = number;
}

Location::Location(const Location& other) {
	this->section = other.section;
	this->shelf = other.shelf;
	this->number = other.number;
}

Location& Location::operator=(const Location& other) {
	if (this != &other)
	{
		this->section = other.section;
		this->shelf = other.shelf;
		this->number = other.number;
	}
	return *this;
}

Location::~Location() {

}

void Location::setSection(const int section) {
	this->section = section;
}

void Location::setShelf(string shelf) {
	this->shelf = shelf;
}

void Location::setNumber(string number) {
	this->number = number;
}

int Location::getSection() const {
	return this->section;
}

string Location::getShelf() const {
	return this->shelf;
}

string Location::getNumber() const {
	return this->number;
}

bool operator==(const Location& lhs, const Location& rhs)
{
	return lhs.getSection() == rhs.getSection() && lhs.getShelf() == rhs.getShelf() && lhs.getNumber() == rhs.getNumber();
}

ostream& operator<<(std::ostream& output, const Location& Location) {
	output << Location.section << " - [" << Location.shelf << "] - [" << Location.number << "]";
	return output;
}