#pragma once
#include <iostream>
#include "Storage.h"
#include "Section.h"
#include "myFunctions.h"
#include "SaveAndGetFileFunction.h"
using namespace std;

bool open(string fileName, Section*& litreSections, Section*& kgSections, vector<Storage>& storageProducts, vector<string>& logs)
{
	bool isOpen = false;
	if (openFile(fileName))
	{
		isOpen = true;
		getSaveStorage(litreSections, kgSections, storageProducts, fileName);
		getLogs(logs);
		getCountSections();
		cout << "Successfully opened " << fileName << endl;
	}
	else
	{
		cout << "Not successfully opened " << fileName << endl;
	}
	return isOpen;
}

void save(string fileName, vector<Storage> storageProducts, vector<string> logs)
{
	bool isYesOrNo = false;
	while (!isYesOrNo)
	{
		string saveOrNo;
		printLine();
		cout << "Do you want to save: [Yes / No] ";
		cin >> saveOrNo;
		printLine();
		saveOrNo = to_lower(saveOrNo);
		cin.ignore();
		if (saveOrNo == "yes")
		{
			isYesOrNo = true;
			bool isSave = false;
			while (!isSave)
			{
				string saveOrSaveAs;
				cout << "\nChoose one of the two options:\n 1) Save\n 2) SaveAs <File Path>\n\nYour choice: ";
				getline(cin, saveOrSaveAs);
				string command = splitBySpace(saveOrSaveAs);
				command = to_lower(command);
				if (command == "save")
				{
					isSave = true;
					saveStorage(storageProducts, fileName);
					saveLog(logs);
					saveCountSections(countLitreSection, countKgSection);
					cout << "Successfully saved " << fileName << endl;
				}
				else if (command == "saveas")
				{
					isSave = true;
					string anotherFileName = receiveFileName(saveOrSaveAs);
					saveStorage(storageProducts, anotherFileName);
					saveLog(logs);
					saveCountSections(countLitreSection, countKgSection);
					cout << "Successfully saved " << anotherFileName << endl;
				}
				else
				{
					cout << "Invalid operation. Only Save or SaveAs..." << endl;
				}
			}
		}
		else if (saveOrNo == "no")
		{
			isYesOrNo = true;
			cout << "The changes will not be saved!" << endl;
		}
		else
		{
			cout << "Invalid operation. Only Yes or No..." << endl;
		}
	}
}

void help()
{
	cout << "\n*************************************************************************\n"
		<< "* The following commands are supported:			                *\n"
		<< "* 1. open <file>		opens <file>                            *\n"
		<< "* 2. close			closes currently opened file            *\n"
		<< "* 3. save			saves the currently open file           *\n"
		<< "* 4. saveas <file>		saves the currently open file in <file> *\n"
		<< "* 5. help			prints this information                 *\n"
		<< "* 6. exit			exists the program                      *\n"
		<< "*************************************************************************" << endl;
}