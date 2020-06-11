#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Shelf.h"
using namespace std;

const int CAPACITY_SHELF = 6;

class Section {
private:
	Shelf* shelfs;

public:
	Section();
	Section(const Section& other);
	Section& operator=(const Section&);
	~Section();

	Shelf* getShelf() const;
};

Section::Section() {
	this->shelfs = new Shelf[CAPACITY_SHELF];
}

Section::Section(const Section& other) {
	this->shelfs = new Shelf[CAPACITY_SHELF];
	for (size_t i = 0; i < CAPACITY_SHELF; i++)
	{
		this->shelfs[i] = other.shelfs[i];
	}
}

Section& Section::operator=(const Section& other) {
	if (this != &other)
	{
		delete[] this->shelfs;
		this->shelfs = new Shelf[CAPACITY_SHELF];
		for (size_t i = 0; i < CAPACITY_SHELF; i++)
		{
			this->shelfs[i] = other.shelfs[i];
		}
	}
	return *this;
}

Section::~Section() {
	delete[] this->shelfs;
}

Shelf* Section::getShelf() const {
	return this->shelfs;
}