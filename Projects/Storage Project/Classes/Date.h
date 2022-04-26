#pragma once
#include <iostream>
#include <cstring>
using namespace std;

const int dayInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
private:
	int date;
	int month;
	int year;

public:
	Date();
	Date(int, int, int);
	Date(const Date& other);
	Date& operator=(const Date&);
	~Date();

	void setDate(const int date);
	void setMonth(const int month);
	void setYear(const int year);

	int getDate() const;
	int getMonth() const;
	int getYear() const;


	Date operator+(int days) const;
	friend bool leapYear(int year);
	friend bool operator==(const Date&, const Date&);
	friend bool operator<=(const Date&, const Date&);
	friend bool operator>=(const Date&, const Date&);
	friend ostream& operator<<(std::ostream&, const Date&);

};



Date::Date() {
	this->date = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(int date, int month, int year) {
	this->date = date;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& other) {
	this->date = other.date;
	this->month = other.month;
	this->year = other.year;
}

Date& Date::operator=(const Date& other) {
	if (this != &other)
	{
		this->date = other.date;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}

Date::~Date() {

}

void Date::setDate(const int date) {
	this->date = date;
}

void Date::setMonth(const int month) {
	this->month = month;
}

void Date::setYear(const int year) {
	this->year = year;
}

int Date::getDate() const {
	return this->date;
}

int Date::getMonth() const {
	return this->month;
}

int Date::getYear() const {
	return this->year;
}

bool leapYear(int year) {
	bool isLeap = false;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		isLeap = true;
	}
	return isLeap;
}

Date Date::operator+(int days) const {
	int daysInCurrentMonth = dayInMonth[this->month];
	if (this->month == 2 && leapYear(this->year))
	{
		daysInCurrentMonth++;
	}
	int newDays = this->date + days;
	int newMonth = this->month;
	int newYear = this->year;
	while (newDays > daysInCurrentMonth) {
		newDays -= daysInCurrentMonth;
		++newMonth;
		if (newMonth > 12) {
			newMonth = 1;
			++newYear;
		}
		daysInCurrentMonth = dayInMonth[newMonth];
		if (newMonth == 2 && leapYear(newYear))
		{
			daysInCurrentMonth++;
		}
	}
	return Date(newDays, newMonth, newYear);
}

bool operator<=(const Date& lhs, const Date& rhs) {
	bool isTrue = false;
	if (lhs.getYear() < rhs.getYear())
	{
		isTrue = true;
	}
	else if (lhs.getYear() == rhs.getYear())
	{
		if (lhs.getMonth() < rhs.getMonth())
		{
			isTrue = true;
		}
		else if (lhs.getMonth() == rhs.getMonth())
		{
			if (lhs.getDate() <= rhs.getDate())
			{
				isTrue = true;
			}
		}
	}
	return isTrue;
}

bool operator>=(const Date& lhs, const Date& rhs) {
	bool isTrue = false;
	if (lhs.getYear() > rhs.getYear())
	{
		isTrue = true;
	}
	else if (lhs.getYear() == rhs.getYear())
	{
		if (lhs.getMonth() > rhs.getMonth())
		{
			isTrue = true;
		}
		else if (lhs.getMonth() == rhs.getMonth())
		{
			if (lhs.getDate() >= rhs.getDate())
			{
				isTrue = true;
			}
		}
	}
	return isTrue;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.getDate() == rhs.getDate() && lhs.getMonth() == rhs.getMonth() && lhs.getYear() == rhs.getYear();
}

ostream& operator<<(std::ostream& output, const Date& Date) {
	output << Date.year << "-" << Date.month << "-" << Date.date;
	return output;
}