#pragma once
#include <iostream>
using namespace std;

class Record {
private:
	char symbol;
	int count;
	string bitsCodesSymbol;

public:
	Record();
	Record(const char, int, string);
	Record(const Record& other);
	Record& operator=(const Record&);

	/*Приема символ като аргумент и го задава като нова стойност на текущия запис*/
	void setSymbol(char);
	/*Приема число като аргумент и го задава като нова стойност на текущия запис*/
	void setCount(int);
	/*Приема стринг като аргумент и го задава като нова стойност на текущия запис*/
	void setBitsCodesSymbol(string);

	/*Връща стойността на текущия запис*/
	const char getSymbol() const;
	/*Връща стойността на текущия запис*/
	int getCount() const;
	/*Връща стойността на подадения запис*/
	string getBitsCodesSymbol() const;
};