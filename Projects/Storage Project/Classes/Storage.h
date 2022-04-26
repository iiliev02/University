#pragma once
#include <iostream>
#include <cstring>
#include "Date.h"
#include "Location.h"
using namespace std;

class Storage {
private:
	char* productName;
	Date expirationDate;
	Date entranceDate;
	char* producer;
	char* unit;
	float availableQuantity;
	Location location;
	char* comment;

public:
	Storage();
	Storage(const char*, Date, Date, const char*, const char*, float, Location, const char*);
	Storage(const Storage& other);
	Storage& operator=(const Storage&);
	~Storage();

	void setProductName(const char* productName);
	void setExpirationDate(Date expirationDate);
	void setEntranceDate(Date entranceDate);
	void setProducer(const char* producer);
	void setUnit(const char* unit);
	void setAvailableQuantity(const int availableQuantity);
	void setLocation(Location location);
	void setComment(const char* comment);

	const char* getProductName() const;
	Date getExpirationDate() const;
	Date getEntranceDate() const;
	const char* getProducer() const;
	const char* getUnit() const;
	float getAvailableQuantity() const;
	Location getLocation() const;
	const char* getComment() const;

	friend bool operator==(const Storage&, const Storage&);
	friend ostream& operator<<(std::ostream&, const Storage&);

};

Storage::Storage() {
	this->productName = nullptr;
	this->expirationDate = Date();
	this->entranceDate = Date();
	this->producer = nullptr;
	this->unit = nullptr;
	this->availableQuantity = 0;
	this->location = Location();
	this->comment = nullptr;
}

Storage::Storage(const char* productName, Date expirationDate, Date entranceDate, const char* producer, const char* unit, float availableQuantity, Location location, const char* comment) {
	this->productName = new char[strlen(productName) + 1];
	strcpy_s(this->productName, strlen(productName) + 1, productName);
	this->expirationDate = expirationDate;
	this->entranceDate = entranceDate;
	this->producer = new char[strlen(producer) + 1];
	strcpy_s(this->producer, strlen(producer) + 1, producer);
	this->unit = new char[strlen(unit) + 1];
	strcpy_s(this->unit, strlen(unit) + 1, unit);
	this->availableQuantity = availableQuantity;
	this->location = location;
	this->comment = new char[strlen(comment) + 1];
	strcpy_s(this->comment, strlen(comment) + 1, comment);
}

Storage::Storage(const Storage& other) {
	this->productName = new char[strlen(other.productName) + 1];
	strcpy_s(this->productName, strlen(other.productName) + 1, other.productName);
	this->expirationDate = other.expirationDate;
	this->entranceDate = other.entranceDate;
	this->producer = new char[strlen(other.producer) + 1];
	strcpy_s(this->producer, strlen(other.producer) + 1, other.producer);
	this->unit = new char[strlen(other.unit) + 1];
	strcpy_s(this->unit, strlen(other.unit) + 1, other.unit);
	this->availableQuantity = other.availableQuantity;
	this->location = other.location;
	this->comment = new char[strlen(other.comment) + 1];
	strcpy_s(this->comment, strlen(other.comment) + 1, other.comment);
}

Storage& Storage::operator=(const Storage& other) {
	if (this != &other)
	{
		delete[] this->productName;
		delete[] this->producer;
		delete[] this->unit;
		delete[] this->comment;
		this->productName = new char[strlen(other.productName) + 1];
		strcpy_s(this->productName, strlen(other.productName) + 1, other.productName);
		this->expirationDate = other.expirationDate;
		this->entranceDate = other.entranceDate;
		this->producer = new char[strlen(other.producer) + 1];
		strcpy_s(this->producer, strlen(other.producer) + 1, other.producer);
		this->unit = new char[strlen(other.unit) + 1];
		strcpy_s(this->unit, strlen(other.unit) + 1, other.unit);
		this->availableQuantity = other.availableQuantity;
		this->location = other.location;
		this->comment = new char[strlen(other.comment) + 1];
		strcpy_s(this->comment, strlen(other.comment) + 1, other.comment);
	}
	return *this;
}

Storage::~Storage() {
	delete[] this->productName;
	delete[] this->producer;
	delete[] this->unit;
	delete[] this->comment;
}

void Storage::setProductName(const char* productName) {
	delete[] this->productName;
	this->productName = new char[strlen(productName) + 1];
	strcpy_s(this->productName, strlen(productName) + 1, productName);
}

void Storage::setExpirationDate(Date expirationDate) {
	this->expirationDate = expirationDate;
}

void Storage::setEntranceDate(Date entranceDate) {
	this->entranceDate = entranceDate;
}

void Storage::setProducer(const char* producer) {
	delete[] this->producer;
	this->producer = new char[strlen(producer) + 1];
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}

void Storage::setUnit(const char* unit) {
	delete[] this->unit;
	this->unit = new char[strlen(unit) + 1];
	strcpy_s(this->unit, strlen(unit) + 1, unit);
}

void Storage::setAvailableQuantity(const int availableQuantity) {
	this->availableQuantity = availableQuantity;
}

void Storage::setLocation(Location location) {
	this->location = location;
}

void Storage::setComment(const char* comment) {
	delete[] this->comment;
	this->comment = new char[strlen(comment) + 1];
	strcpy_s(this->comment, strlen(comment) + 1, comment);
}

const char* Storage::getProductName() const {
	return this->productName;
}

Date Storage::getExpirationDate() const {
	return this->expirationDate;
}

Date Storage::getEntranceDate() const {
	return this->entranceDate;
}

const char* Storage::getProducer() const {
	return this->producer;
}

const char* Storage::getUnit() const {
	return this->unit;
}

float Storage::getAvailableQuantity() const {
	return this->availableQuantity;
}

Location Storage::getLocation() const {
	return this->location;
}

const char* Storage::getComment() const {
	return this->comment;
}

bool operator==(const Storage& lhs, const Storage& rhs)
{
	bool isSame = false;
	if (strcmp(lhs.getProductName(), rhs.getProductName()) == 0)
	{
		isSame = true;
	}
	return isSame;
}

ostream& operator<<(std::ostream& output, const Storage& Storage) {
	output << "Product Name: " << Storage.productName << endl;
	output << "Expiration Date: " << Storage.expirationDate << endl;
	output << "Entrance Date: " << Storage.entranceDate << endl;
	output << "Producer: " << Storage.producer << endl;
	output << "Unit: " << Storage.unit << endl;
	output << "Available Quantity: " << Storage.availableQuantity << endl;
	output << "Location: " << Storage.location << endl;
	output << "Comment: " << Storage.comment << endl;
	return output;
}