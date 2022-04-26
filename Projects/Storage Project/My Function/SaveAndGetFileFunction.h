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
using namespace std;


void sortStorage(vector<Storage>& storageProducts)
{
	vector<Storage> litreProducts;
	vector<Storage> kgProducts;
	for (size_t i = 0; i < storageProducts.size(); i++)
	{
		if (strcmp(storageProducts[i].getUnit(), "litre") == 0)
		{
			litreProducts.push_back(storageProducts[i]);
		}
		else
		{
			kgProducts.push_back(storageProducts[i]);
		}
	}
	storageProducts.clear();
	for (size_t i = 0; i < litreProducts.size(); i++)
	{
		for (size_t j = 0; j < litreProducts.size() - i - 1; j++)
		{
			string firstShelf = litreProducts[j].getLocation().getShelf();
			string secondShelf = litreProducts[j + 1].getLocation().getShelf();
			int firstShelfInt = stoi(splitByDash(firstShelf));
			int secondShelfInt = stoi(splitByDash(secondShelf));
			if (litreProducts[j].getLocation().getSection() > litreProducts[j + 1].getLocation().getSection())
			{
				swap(litreProducts[j], litreProducts[j + 1]);
			}
			else if (litreProducts[j].getLocation().getSection() == litreProducts[j + 1].getLocation().getSection())
			{
				if (firstShelfInt > secondShelfInt)
				{
					swap(litreProducts[j], litreProducts[j + 1]);
				}
			}
		}
	}
	for (size_t i = 0; i < kgProducts.size(); i++)
	{
		for (size_t j = 0; j < kgProducts.size() - i - 1; j++)
		{
			string firstShelf = kgProducts[j].getLocation().getShelf();
			string secondShelf = kgProducts[j + 1].getLocation().getShelf();
			int firstShelfInt = stoi(splitByDash(firstShelf));
			int secondShelfInt = stoi(splitByDash(secondShelf));
			if (kgProducts[j].getLocation().getSection() > kgProducts[j + 1].getLocation().getSection())
			{
				swap(kgProducts[j], kgProducts[j + 1]);
			}
			else if (kgProducts[j].getLocation().getSection() == kgProducts[j + 1].getLocation().getSection())
			{
				if (firstShelfInt > secondShelfInt)
				{
					swap(kgProducts[j], kgProducts[j + 1]);
				}
			}
		}
	}
	for (size_t i = 0; i < litreProducts.size(); i++)
	{
		storageProducts.push_back(litreProducts[i]);
	}
	for (size_t i = 0; i < kgProducts.size(); i++)
	{
		storageProducts.push_back(kgProducts[i]);
	}
}

void saveLog(vector<string> logs) {
	ofstream saveLog;
	saveLog.open("Log.txt", ios::trunc);
	if (saveLog.is_open())
	{

		for (size_t i = 0; i < logs.size(); i++)
		{
			saveLog << logs[i] << endl;
		}
		saveLog.close();
	}
}

void saveStorage(vector<Storage>& storageProducts, string fileName)
{
	sortStorage(storageProducts);
	ofstream saveStorage;
	saveStorage.open(fileName, ios::trunc);
	if (saveStorage.is_open())
	{
		for (size_t i = 0; i < storageProducts.size(); i++)
		{
			saveStorage << storageProducts[i];
		}
		saveStorage.close();
	}
}

void saveCountSections(int litreCount, int kgCount)
{
	ofstream saveCount;
	saveCount.open("Count_Section.txt", ios::trunc);
	if (saveCount.is_open())
	{
		saveCount << "Litre Sections: " << litreCount << endl;
		saveCount << "Kg Sections: " << kgCount << endl;
		saveCount.close();
	}
}

void getSaveStorage(Section*& litreSections, Section*& kgSections, vector<Storage>& storageProducts, string fileName)
{
	vector<Storage> getProducts;
	Storage getProduct = Storage();
	int count = 0;
	ifstream getSaveStorage;
	getSaveStorage.open(fileName, ios::in);
	if (getSaveStorage.is_open())
	{
		string getLine;
		while (!getSaveStorage.eof())
		{
			getline(getSaveStorage, getLine);
			int len = getLine.find(": ");
			string typical = getLine.substr(0, len + 2);
			getLine = getLine.erase(0, len + 2);
			if (typical == "Product Name: ")
			{
				getProduct.setProductName(getLine.c_str());
				count++;
			}
			else if (typical == "Expiration Date: ")
			{
				Date getDate = receiveDate(getLine);
				getProduct.setExpirationDate(getDate);
				count++;
			}
			else if (typical == "Entrance Date: ")
			{
				Date getDate = receiveDate(getLine);
				getProduct.setEntranceDate(getDate);
				count++;
			}
			else if (typical == "Producer: ")
			{
				getProduct.setProducer(getLine.c_str());
				count++;
			}
			else if (typical == "Unit: ")
			{
				getProduct.setUnit(getLine.c_str());
				count++;
			}
			else if (typical == "Available Quantity: ")
			{
				float quantity = stof(getLine);
				getProduct.setAvailableQuantity(quantity);
				count++;
			}
			else if (typical == "Location: ")
			{
				getLine.erase(remove(getLine.begin(), getLine.end(), '['), getLine.end());
				getLine.erase(remove(getLine.begin(), getLine.end(), ']'), getLine.end());
				getLine.erase(remove(getLine.begin(), getLine.end(), ' '), getLine.end());
				int section = stoi(splitByDash(getLine));
				string firstShelf = splitByDash(getLine);
				Location loc = Location(section, firstShelf, "0");
				getProduct.setLocation(loc);
				count++;
			}
			else if (typical == "Comment: ")
			{
				getProduct.setComment(getLine.c_str());
				count++;
			}
			if (count == 8)
			{
				getProducts.push_back(getProduct);
				count = 0;
			}
		}
		getSaveStorage.close();
	}
	for (size_t i = 0; i < getProducts.size(); i++)
	{
		int posSection = getProducts[i].getLocation().getSection() - 1;
		int posShelf = stoi(getProducts[i].getLocation().getShelf()) - 1;
		if (posShelf % 2 != 0)
		{
			posShelf--;
		}
		if (strcmp(getProducts[i].getUnit(), "litre") == 0)
		{
			addGetProduct(litreSections, storageProducts, getProducts[i], posSection, posShelf);
		}
		else if (strcmp(getProducts[i].getUnit(), "kg") == 0)
		{
			addGetProduct(kgSections, storageProducts, getProducts[i], posSection, posShelf);
		}
	}
}

void getLogs(vector<string>& logs)
{
	ifstream getLogs;
	getLogs.open("Log.txt", ios::in);
	if (getLogs.is_open())
	{
		while (!getLogs.eof())
		{
			string line;
			getline(getLogs, line);
			if (line != "")
			{
				logs.push_back(line);
			}
		}
		getLogs.close();
	}
}

void getCountSections()
{
	ifstream getCount;
	getCount.open("Count_Section.txt", ios::in);
	if (getCount.is_open())
	{
		while (!getCount.eof())
		{
			string getLine;
			getline(getCount, getLine);
			int len = getLine.find(": ");
			if (len > 0)
			{
				string temp = getLine.substr(0, len + 2);
				getLine = getLine.erase(0, len + 2);
				if (temp == "Litre Sections: ")
				{
					countLitreSection = stoi(getLine);
				}
				else
				{
					countKgSection = stoi(getLine);
				}
			}
		}
		getCount.close();
	}
}