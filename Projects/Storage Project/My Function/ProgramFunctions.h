#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
#include "Storage.h"
#include "Section.h"
#include "myFunctions.h"
#include "AddAndRemoveFunctions.h"
using namespace std;

void printFunction(Section* sections, string unit, int count)
{
	int countProduct = 1;
	cout << "\n\n****** " << unit << " products ******" << endl;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
		{
			if (sections[i].getShelf()[j].getProducts().size() != 0)
			{
				Storage printProduct = Storage();
				float availableQuantityPrintProduct = 0.0;
				string shelfs, numeric;
				for (size_t z = 0; z < sections[i].getShelf()[j].getProducts().size(); z++)
				{
					printProduct.setProductName(sections[i].getShelf()[j].getProducts()[z].getProductName());
					printProduct.setUnit(sections[i].getShelf()[j].getProducts()[z].getUnit());
					availableQuantityPrintProduct += sections[i].getShelf()[j].getProducts()[z].getAvailableQuantity();
				}
				for (size_t a = 0; a < sections[i].getShelf()[j + 1].getProducts().size(); a++)
				{
					availableQuantityPrintProduct += sections[i].getShelf()[j + 1].getProducts()[a].getAvailableQuantity();
				}
				printProduct.setAvailableQuantity(availableQuantityPrintProduct);
				if (availableQuantityPrintProduct <= 200)
				{
					shelfs = to_string(j + 1);
					numeric = "1-" + to_string(sections[i].getShelf()[j].getCells().size());
				}
				else
				{
					shelfs = to_string(j + 1) + "-" + to_string(j + 2);
					numeric = "1-" + to_string(sections[i].getShelf()[j].getCells().size() + sections[i].getShelf()[j + 1].getCells().size());
				}
				Location loc = Location(i + 1, shelfs, numeric);
				printProduct.setLocation(loc);
				prtProduct(printProduct.getProductName(), printProduct.getUnit(), printProduct.getAvailableQuantity(), printProduct.getLocation(), countProduct);
			}
		}
	}
}

void addFunction(string systemCommand, vector<Storage>& storageProducts, Section*& litreSections, Section*& kgSections, vector<string>& logs)
{
	bool isAdd = true;
	Storage product = addInfoProduct();
	if (strcmp(product.getUnit(), "litre") == 0 && product.getAvailableQuantity() <= 400.0 && isValidDate(product.getExpirationDate()))
	{
		addProduct(litreSections, storageProducts, product, countLitreSection, isAdd);
		addLog(logs, systemCommand, product.getProductName(), product.getUnit(), product.getAvailableQuantity());
		if (isAdd)
		{
			printMessages(1);
		}
	}
	else if (strcmp(product.getUnit(), "kg") == 0 && product.getAvailableQuantity() <= 400.0 && isValidDate(product.getExpirationDate()))
	{
		addProduct(kgSections, storageProducts, product, countKgSection, isAdd);
		addLog(logs, systemCommand, product.getProductName(), product.getUnit(), product.getAvailableQuantity());
		if (isAdd)
		{
			printMessages(1);
		}
	}
	else
	{
		printErrorMessagesProduct(product.getUnit(), product.getAvailableQuantity(), product.getExpirationDate());
	}
}

void removeFunction(Section*& litreSections, Section*& kgSections, vector<Storage>& storageProducts, vector<string>& logs)
{
	string productName;
	float quantity;
	printLine();
	printInputMessasges(1);
	getline(cin, productName);
	printInputMessasges(7);
	cin >> quantity;
	printLine();
	productName = to_lower(productName);
	string unit = existProductForRemove(storageProducts, productName);
	if (unit == "litre")
	{
		removeProduct(litreSections, storageProducts, logs, productName.c_str(), quantity, countLitreSection);
	}
	else if (unit == "kg")
	{
		removeProduct(kgSections, storageProducts, logs, productName.c_str(), quantity, countKgSection);
	}
	else
	{
		printMessages(2);
	}
}

void logFunction(vector<string> logs) {
	string fDate, tDate;
	Date fromDate, toDate;
	printLine();
	printInputMessasges(8);
	cin >> fDate;
	printInputMessasges(9);
	cin >> tDate;
	printLine();
	fromDate = receiveDate(fDate);
	toDate = receiveDate(tDate);
	cout << endl;
	for (size_t i = 0; i < logs.size(); i++)
	{
		string logLine = logs[i];
		string tempDate;
		int len = logLine.find("->");
		if (len > 0)
		{
			tempDate = logLine.substr(0, len);
			Date cmpDate = receiveDate(tempDate);
			if (cmpDate >= fromDate && cmpDate <= toDate)
			{
				cout << logLine << endl;
			}
			logLine.clear();
		}
	}
}

void cleanFunction(Section*& sections, vector<Storage>& storageProducts, vector<string>& logs, Date today, string unit, int count)
{
	vector<Storage> rearrangeProducts;
	vector<Storage> cleanProducts;
	Date recentExpirationDate = today + 7;
	int countProduct = 1;
	cout << "\n\n****** " << unit << " products ******" << endl;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < CAPACITY_SHELF; j += 2)
		{
			if (sections[i].getShelf()[j].getProducts().size() != 0)
			{
				rearrange(sections, i, j, rearrangeProducts);
				clearShelfs(sections, i, j);
				removeProductFromListProducts(storageProducts, rearrangeProducts);
				for (size_t z = 0; z < rearrangeProducts.size(); z++)
				{
					if (rearrangeProducts[z].getExpirationDate() <= recentExpirationDate && rearrangeProducts[z].getExpirationDate() >= today)
					{
						cleanProducts.push_back(rearrangeProducts[z]);
						rearrangeProducts.erase(rearrangeProducts.begin() + z);
					}
				}
			}
		}
	}
	for (size_t i = 0; i < rearrangeProducts.size(); i++)
	{
		bool isAdd = true;
		addProduct(sections, storageProducts, rearrangeProducts[i], count, isAdd);
	}
	if (cleanProducts.size() != 0)
	{
		for (size_t i = 0; i < cleanProducts.size(); i++)
		{
			prtProduct(cleanProducts[i].getProductName(), cleanProducts[i].getUnit(), cleanProducts[i].getAvailableQuantity(), cleanProducts[i].getLocation(), countProduct);
			addLog(logs, "clean", cleanProducts[i].getProductName(), cleanProducts[i].getUnit(), cleanProducts[i].getAvailableQuantity());
		}
	}
	else
	{
		cout << "\nThere are no products with measure " << unit << " for cleaning!" << endl;
	}
}

void lossesFunction(vector<string> logs)
{
	float totalPrice = 0.0, priceForProduct;
	string log, operation, productNameLogs, productName, fromDate, toDate, dateLogs;
	Date fDate, tDate, dLogs;
	printLine();
	printInputMessasges(1);
	getline(cin, productName);
	productName = to_lower(productName);
	printInputMessasges(10);
	cin >> priceForProduct;
	printInputMessasges(11);
	printInputMessasges(8);
	cin >> fromDate;
	printInputMessasges(9);
	cin >> toDate;
	printLine();
	fDate = receiveDate(fromDate);
	tDate = receiveDate(toDate);
	for (size_t i = 0; i < logs.size(); i++)
	{
		log = logs[i];
		for (size_t i = 0; i < 3; i++)
		{
			if (i == 1)
			{
				operation = splitByArrow(log);
			}
			else if (i == 2)
			{
				productNameLogs = splitByArrow(log);
			}
			else
			{
				dateLogs = splitByArrow(log);
				dLogs = receiveDate(dateLogs);
			}
		}
		if (operation == "clean" && productNameLogs == productName && dLogs >= fDate && dLogs <= tDate)
		{
			int len = log.find("->");
			float quantityProduct = stof(log.substr(len + 2));
			totalPrice += quantityProduct * priceForProduct;
		}
	}
	if (totalPrice != 0)
	{
		totalPrice = roundNum(totalPrice);
		cout << "\nThe losses for the product " << productName << " are worth it " << totalPrice << " lv." << endl;
	}
	else
	{
		printMessages(3);
	}
}