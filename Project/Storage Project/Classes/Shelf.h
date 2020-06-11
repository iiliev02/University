#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Storage.h"
#include "Cell.h"
using namespace std;

const float CAPACITY_QUANTITY = 200.0;
const float CAPACITY_CELLS = 50.0;

class Shelf {
private:
	vector<Storage> products;
	vector<Cell> cells;
	float busySpace;
	float freeSpace;
	int busyCells;

public:
	Shelf();
	Shelf(const Shelf& other);
	Shelf& operator=(const Shelf&);

	void pushProduct(Storage);
	void setBusyCells(Storage);
	vector<Storage>& getProducts();
	vector<Cell>& getCells();
	void setShelfSpace(float, float);

	float getBusySpace() const;
	float getFreeSpace() const;
	int getBusyCells() const;
};

Shelf::Shelf() {
	this->products;
	this->cells;
	this->busySpace = 0.0;
	this->freeSpace = 0.0;
	this->busyCells = 0;
}

Shelf::Shelf(const Shelf& other) {
	this->products = other.products;
	this->cells = other.cells;
	this->busySpace = other.busySpace;
	this->freeSpace = other.freeSpace;
	this->busyCells = other.busyCells;
}

Shelf& Shelf::operator=(const Shelf& other) {
	if (this != &other)
	{
		this->products = other.products;
		this->cells = other.cells;
		this->busySpace = other.busySpace;
		this->freeSpace = other.freeSpace;
		this->busyCells = other.busyCells;
	}
	return *this;
}

void Shelf::pushProduct(Storage product) {
	this->products.push_back(product);
	this->busySpace += product.getAvailableQuantity();
	this->freeSpace = CAPACITY_QUANTITY - this->busySpace;
	
}

void Shelf::setBusyCells(Storage product) {
	int cellFull = floor(product.getAvailableQuantity() / CAPACITY_CELLS);
	for (size_t i = 0; i < cellFull; i++)
	{
		Cell fullCells = Cell(50, 0);
		this->cells.push_back(fullCells);
	}
	if (product.getAvailableQuantity() - (cellFull * CAPACITY_CELLS) != 0)
	{
		if (cellFull != 0)
		{
			Cell notFullCell = Cell(product.getAvailableQuantity() - (cellFull * CAPACITY_CELLS), CAPACITY_CELLS - (product.getAvailableQuantity() - (cellFull * CAPACITY_CELLS)));
			this->cells.push_back(notFullCell);
		}
		else
		{
			Cell notFullCell = Cell(product.getAvailableQuantity(), CAPACITY_CELLS - product.getAvailableQuantity());
			this->cells.push_back(notFullCell);
		}
	}
}

void Shelf::setShelfSpace(float busySpace, float freeSpace) {
	this->busySpace = busySpace;
	this->freeSpace = freeSpace;
}

vector<Storage>& Shelf::getProducts() {
	return this->products;
}

vector<Cell>& Shelf::getCells() {
	return this->cells;
}

float Shelf::getBusySpace() const {
	return this->busySpace;
}

float Shelf::getFreeSpace() const {
	return this->freeSpace;
}

int Shelf::getBusyCells() const {
	return this->busyCells;
}