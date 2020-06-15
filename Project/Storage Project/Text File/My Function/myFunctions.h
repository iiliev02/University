#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "TextAlign.h"
using namespace std;

int countLitreSection = 1;
int countKgSection = 1;

void printInputMessasges(int value);

void printLine()
{
	for (size_t i = 0; i < 25; i++) cout << "-";
	cout << endl;
}

void prtProduct(const char* productName, const char* unit, float quantity, Location loc, int& countProduct)
{
	cout << "\n ------- Product " << countProduct++ << " -------" << endl;
	cout << "Product Name: " << productName << endl;
	cout << "Unit: " << unit << endl;
	cout << "Available Quantity: " << quantity << endl;
	cout << "Location: " << loc << endl;
}

void introduction()
{
	string text =
		"Before	you	start working with the warehouse, "
		"you need to open the file that contains "
		"information about the availability of products in the warehouse. "
		"If one does not already exist, it will be created automatically. "
		"For your convenience, if you need help with operations, "
		"everything is described in detail, "
		"you are only required to write help.";

	printText(text, Alignment::Justify); 
}

string splitBySpace(string& line)
{
	int len = 0;
	len = line.find(" ");
	string temp = "";
	if (len < 0)
	{
		temp = line.substr(0, line.size());
		line.clear();
	}
	else
	{
		temp = line.substr(0, len);
		line.erase(0, len + 1);
	}
	return temp;
}

string splitByDash(string& line) {
	int len = 0;
	len = line.find("-");
	string temp = "";
	if (len < 0)
	{
		temp = line.substr(0, line.size());
		line.clear();
	}
	else
	{
		temp = line.substr(0, len);
		line.erase(0, len + 1);
	}
	return temp;
}

string splitByArrow(string& line)
{
	int len = 0;
	len = line.find("->");
	string temp = "";
	if (len < 0)
	{
		temp = line.substr(0, line.size());
		line.clear();
	}
	else
	{
		temp = line.substr(0, len);
		line.erase(0, len + 2);
	}
	return temp;
}

int splitDate(string& date) {
	int len = 0;
	len = date.find("-");
	string temp = "";
	if (len < 0)
	{
		temp = date.substr(0, date.size());
		date.clear();
	}
	else
	{
		temp = date.substr(0, len);
		date.erase(0, len + 1);
	}
	int dateInt = stoi(temp);
	return dateInt;
}

int currentDay() {

	struct tm current;
	time_t t = time(NULL);
	localtime_s(&current, &t);
	int day = current.tm_mday;

	return day;
}

int currentMonth() {
	struct tm current;
	time_t t = time(NULL);
	localtime_s(&current, &t);
	int month = current.tm_mon + 1;

	return month;
}

int currentYear() {
	struct tm current;
	time_t t = time(NULL);
	localtime_s(&current, &t);
	int year = current.tm_year + 1900;

	return year;
}

string to_lower(string input)
{
	string returnWord;
	char output;
	int i = 0;
	while (input[i])
	{
		output = input[i];
		returnWord += tolower(output);
		i++;
	}
	return returnWord;
}

float roundNum(float var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}

string receiveFileName(string line)
{
	string fileName;
	int len = line.find_last_of("\\");
	if (len < 0)
	{
		fileName = " ";
	}
	else
	{
		fileName = line.substr(len + 1);
	}
	return fileName;
}

void programCommand(string& systemCommand)
{
	const string option = "\nChoose one of the seven options:\n 1) Print\n 2) Add\n 3) Remove\n 4) Log\n 5) Clean\n 6) Losses\n 7) Close\n\nYour choice: ";
	cout << option;
	cin >> systemCommand;
	systemCommand = to_lower(systemCommand);
}

void systemCommand(string& commandLine, string& line)
{
	const string menu = "\n ----- Menu ▼ -----\n • Open <File Path>\n • Help\n • Exit\n\nYour choice: ";
	cout << menu;
	getline(cin, line);
	commandLine = splitBySpace(line);
	commandLine = to_lower(commandLine);
}

void saveOrNoCommand(string& saveOrNo)
{
	const string yesOrNo = "Do you want to save: [Yes / No] ";
	printLine();
	cout << yesOrNo;
	cin >> saveOrNo;
	printLine();
	saveOrNo = to_lower(saveOrNo);
}

void saveOrSaveAsCommand(string& saveOrSaveAs, string& command)
{
	const string saveMenu = "\nChoose one of the two options:\n 1) Save\n 2) SaveAs <File Path>\n\nYour choice: ";
	cout << saveMenu;
	getline(cin, saveOrSaveAs);
	command = splitBySpace(saveOrSaveAs);
	command = to_lower(command);
}

Date receiveToday()
{
	int day = currentDay();
	int month = currentMonth();
	int year = currentYear();
	Date today = Date(day, month, year);
	return today;
}

Date receiveDate(string expirDate)
{
	int expirDay, expirMonth, expirYear;
	expirYear = splitDate(expirDate);
	expirMonth = splitDate(expirDate);
	expirDay = splitDate(expirDate);
	Date expirationDate = Date(expirDay, expirMonth, expirYear);
	return expirationDate;
}

Storage addInfoProduct()
{
	string productName, expirDate, producer, unit, comment;
	int availableQuantity;
	Date expirationDate, entranceDate;
	Location loc = Location(0, "0", "0");
	entranceDate = Date(currentDay(), currentMonth(), currentYear());
	cout << endl;
	printInputMessasges(1);
	cin.ignore();
	getline(cin, productName);
	printInputMessasges(2);
	cin >> expirDate;
	printInputMessasges(3);
	cin.ignore();
	getline(cin, producer);
	printInputMessasges(4);
	cin >> unit;
	printInputMessasges(5);
	cin >> availableQuantity;
	printInputMessasges(6);
	cin.ignore();
	getline(cin, comment);
	expirationDate = receiveDate(expirDate);
	productName = to_lower(productName);
	producer = to_lower(producer);
	unit = to_lower(unit);
	comment = to_lower(comment);
	Storage newProduct = Storage(productName.c_str(), expirationDate, entranceDate, producer.c_str(), unit.c_str(), availableQuantity, loc, comment.c_str());
	return newProduct;
}

void newLocation(vector<Storage>& storageProducts, Storage product)
{
	for (size_t i = 0; i < storageProducts.size(); i++)
	{
		if (product.getExpirationDate() == storageProducts[i].getExpirationDate()
			&& strcmp(product.getProducer(), storageProducts[i].getProducer()) == 0
			&& strcmp(product.getComment(), storageProducts[i].getComment()) == 0
			&& strcmp(product.getProductName(), storageProducts[i].getProductName()) == 0)
		{
			storageProducts[i].setAvailableQuantity(product.getAvailableQuantity());
			storageProducts[i].setLocation(product.getLocation());
		}
	}
}

bool isValidDate(Date expirDate)
{
	bool isValid = false;
	if (expirDate.getMonth() >= 1 && expirDate.getMonth() <= 12)
	{
		int daysInCurrentMonth = dayInMonth[expirDate.getMonth()];
		if (expirDate.getMonth() == 2 && leapYear(expirDate.getYear()))
		{
			daysInCurrentMonth++;
		}
		if (expirDate.getDate() <= daysInCurrentMonth && expirDate.getDate() >= 1)
		{
			isValid = true;
		}
	}
	Date validDate = Date(currentDay(), currentMonth(), currentYear());
	return expirDate >= validDate && isValid;
}

string existProductForRemove(vector<Storage> storageProducts, string name)
{
	bool isExist = false;
	int positionProduct;
	for (size_t i = 0; i < storageProducts.size(); i++)
	{
		if (storageProducts[i].getProductName() == name)
		{
			positionProduct = i;
			isExist = true;
		}
	}
	if (isExist)
	{
		string unit = storageProducts[positionProduct].getUnit();
		return unit;
	}
	else
	{
		return "";
	}
}

bool existProduct(Section* sections, Storage product, int count)
{
	bool isExist = false;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
		{
			for (size_t z = 0; z < sections[i].getShelf()[j].getProducts().size(); z++)
			{
				if (strcmp(sections[i].getShelf()[j].getProducts()[z].getProductName(), product.getProductName()) == 0)
				{
					isExist = true;
					break;
				}
			}
			if (isExist)
			{
				break;
			}
		}
	}
	return isExist;
}

bool sameProduct(Section* sections, Storage product, int posSection, int posShelf)
{
	bool isSame = false;
	for (size_t i = 0; i < sections[posSection].getShelf()[posShelf].getProducts().size(); i++)
	{
		if (product.getExpirationDate() == sections[posSection].getShelf()[posShelf].getProducts()[i].getExpirationDate()
			&& strcmp(product.getProducer(), sections[posSection].getShelf()[posShelf].getProducts()[i].getProducer()) == 0
			&& strcmp(product.getComment(), sections[posSection].getShelf()[posShelf].getProducts()[i].getComment()) == 0)
		{
			isSame = true;
			break;
		}
	}
	if (!isSame)
	{
		for (size_t i = 0; i < sections[posSection].getShelf()[posShelf + 1].getProducts().size(); i++)
		{
			if (product.getExpirationDate() == sections[posSection].getShelf()[posShelf + 1].getProducts()[i].getExpirationDate()
				&& strcmp(product.getProducer(), sections[posSection].getShelf()[posShelf + 1].getProducts()[i].getProducer()) == 0
				&& strcmp(product.getComment(), sections[posSection].getShelf()[posShelf + 1].getProducts()[i].getComment()) == 0)
			{
				isSame = true;
				break;
			}
		}
	}
	return isSame;
}

void clearShelfs(Section*& sections, int posSection, int posShelf)
{
	sections[posSection].getShelf()[posShelf].setShelfSpace(0.0, 0.0);
	sections[posSection].getShelf()[posShelf + 1].setShelfSpace(0.0, 0.0);
	sections[posSection].getShelf()[posShelf].getCells().clear();
	sections[posSection].getShelf()[posShelf + 1].getCells().clear();
	sections[posSection].getShelf()[posShelf].getProducts().clear();
	sections[posSection].getShelf()[posShelf + 1].getProducts().clear();
}

void rearrange(Section* sections, int posSection, int posShelf, vector<Storage>& rearrangeProducts)
{
	for (size_t i = 0; i < sections[posSection].getShelf()[posShelf].getProducts().size(); i++)
	{
		rearrangeProducts.push_back(sections[posSection].getShelf()[posShelf].getProducts()[i]);
	}
	for (size_t i = 0; i < sections[posSection].getShelf()[posShelf + 1].getProducts().size(); i++)
	{
		rearrangeProducts.push_back(sections[posSection].getShelf()[posShelf + 1].getProducts()[i]);
	}
	for (size_t i = 0; i < rearrangeProducts.size(); i++)
	{
		if (i + 1 < rearrangeProducts.size())
		{
			if (rearrangeProducts[i].getExpirationDate() == rearrangeProducts[i + 1].getExpirationDate()
				&& strcmp(rearrangeProducts[i].getProducer(), rearrangeProducts[i + 1].getProducer()) == 0
				&& strcmp(rearrangeProducts[i].getComment(), rearrangeProducts[i + 1].getComment()) == 0)
			{
				rearrangeProducts[i].setAvailableQuantity(rearrangeProducts[i].getAvailableQuantity() + rearrangeProducts[i + 1].getAvailableQuantity());
				Storage removeProduct = rearrangeProducts[i + 1];
				rearrangeProducts.erase(rearrangeProducts.begin() + i + 1);
				i--;
			}
		}
	}
}

bool openFile(string fileName)
{
	bool isOpen = false;
	ifstream isOpenFile;
	isOpenFile.open(fileName, ios::in);
	if (isOpenFile.is_open())
	{
		isOpen = true;
		isOpenFile.close();
	}
	if (isOpen)
	{
		return isOpen;
	}
	else
	{
		ofstream createFile;
		createFile.open(fileName, ios::out);
		if (createFile.is_open())
		{
			isOpen = true;
			createFile.close();
		}
		return isOpen;
	}
}

void printErrorMessagesProduct(const char* unit, float quantity, Date validDate)
{
	const string invalidUnit = "\nYou entered invalid unit...";
	const string invalidQuantity = "\nQuantity of the product is more than maximum allowed for one product...";
	const string invalidExpirDate = "\nExpiration date of the product is invalid or has expired...";
	bool unitCorrect = strcmp(unit, "litre") == 0 || strcmp(unit, "kg") == 0;
	bool quantityCorrect = quantity <= 400.0;
	bool validExpirDate = isValidDate(validDate);
	if (!unitCorrect && quantityCorrect && validExpirDate)
	{
		cout << invalidUnit << endl;
	}
	else if (unitCorrect && !quantityCorrect && validExpirDate)
	{
		cout << invalidQuantity << endl;
	}
	else if (unitCorrect && quantityCorrect && !validExpirDate)
	{
		cout << invalidExpirDate << endl;
	}
}

void printMessages(int value)
{
	const string sucAddProd = "\nSuccessful added product";
	const string doesntExistProd = "\nThis product does not exist...";
	const string noLosses = "\nThere are no losses for this product";
	const string noSpace = "\nSorry!!! We don't have enough space for the product...";
	const string canContinue = "\nOkay. Now, you can to continue with another option.";
	const string emptyPath = "You must enter a file path!";
	const string wrongSave = "Invalid operation. Only Save or SaveAs...";
	const string noChange = "\nThe changes will not be saved!";
	const string wrongYesOrNo = "Invalid operation. Only Yes or No...";
	const string invalidOperation = "\nYou have entered an invalid operation!!!";
	const string notSucOpen = "Not successfully opened storage!";
	switch (value)
	{
	case 1:
		cout << sucAddProd << endl;
		break;

	case 2:
		cout << doesntExistProd << endl;
		break;

	case 3:
		cout << noLosses << endl;
		break;

	case 4:
		cout << noSpace << endl;
		break;

	case 5:
		cout << canContinue << endl;
		break;

	case 6:
		cout << emptyPath << endl;
		break;

	case 7:
		cout << wrongSave << endl;
		break;

	case 8:
		cout << noChange << endl;
		break;

	case 9:
		cout << wrongYesOrNo << endl;
		break;

	case 10:
		cout << invalidOperation << endl;
		break;

	case 11:
		cout << notSucOpen << endl;
		break;

	default:
		break;
	}
}

void printInputMessasges(int value)
{
	const string productName = "Еnter the product name: ";
	const string expirDate = "Enter the expiration date: ";
	const string producer = "Enter the producer: ";
	const string unit = "Enter the unit: (kg, litre) ";
	const string availableQuantity = "Enter the available quantity: ";
	const string comment = "Enter the comment of product: ";
	const string quantityRemove = "Enter the quantity you want to remove: ";
	const string from = "From: ";
	const string to = "To: ";
	const string pricePerUnit = "Enter price per unit of measure: ";
	const string lossesForProduct = "\nEnter a period for calculate losses for the product: ";
	const string youWantToRemove = "Do you want to continue and remove all available quantity for the product...[Yes/No]: ";
	switch (value)
	{
	case 1:
		cout << productName;
		break;
		
	case 2:
		cout << expirDate;
		break;

	case 3:
		cout << producer;
		break;

	case 4:
		cout << unit;
		break;

	case 5:
		cout << availableQuantity;
		break;

	case 6:
		cout << comment;
		break;

	case 7:
		cout << quantityRemove;
		break;

	case 8:
		cout << from;
		break;

	case 9:
		cout << to;
		break;

	case 10:
		cout << pricePerUnit;
		break;

	case 11:
		cout << lossesForProduct << endl;
		break;

	case 12:
		cout << youWantToRemove;
		break;

	default:
		break;
	}
}