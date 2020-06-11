#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Cell {
private:
	float busyCapacity;
	float freeCapacity;

public:
	Cell();
	Cell(float, float);
	Cell(const Cell& other);
	Cell& operator=(const Cell&);
	~Cell();

	void setCellCapacity(float, float);

	float getBusyCapacity() const;
	float getFreeCapacity() const;
};

Cell::Cell() {
	this->busyCapacity = 0.0;
	this->freeCapacity = 0.0;
}

Cell::Cell(float busyCapacity, float freeCapacity) {
	this->busyCapacity = busyCapacity;
	this->freeCapacity = freeCapacity;
}

Cell::Cell(const Cell& other) {
	this->busyCapacity = other.busyCapacity;
	this->freeCapacity = other.freeCapacity;
}

Cell& Cell::operator=(const Cell& other) {
	if (this != &other)
	{
		this->busyCapacity = other.busyCapacity;
		this->freeCapacity = other.freeCapacity;
	}
	return *this;
}

Cell::~Cell() {

}

void Cell::setCellCapacity(float busyCapacity, float freeCapacity) {
	this->busyCapacity = busyCapacity;
	this->freeCapacity = freeCapacity;
}

float Cell::getBusyCapacity() const {
	return this->busyCapacity;
}

float Cell::getFreeCapacity() const {
	return this->freeCapacity;
}