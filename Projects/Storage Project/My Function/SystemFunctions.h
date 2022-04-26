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
		printMessages(6);
	}
	return isOpen;
}

void save(string fileName, vector<Storage> storageProducts, vector<string> logs)
{
	bool isYesOrNo = false;
	while (!isYesOrNo)
	{
		string saveOrNo;
		saveOrNoCommand(saveOrNo);
		cin.ignore();
		if (saveOrNo == "yes")
		{
			isYesOrNo = true;
			bool isSave = false;
			while (!isSave)
			{
				string saveOrSaveAs, command;
				saveOrSaveAsCommand(saveOrSaveAs, command);
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
					string anotherFileName = receiveFileName(saveOrSaveAs);
					if (anotherFileName != " ")
					{
						isSave = true;
						saveStorage(storageProducts, anotherFileName);
						saveLog(logs);
						saveCountSections(countLitreSection, countKgSection);
						cout << "Successfully saved " << anotherFileName << endl;
					}
					else
					{
						printMessages(6);
					}
				}
				else
				{
					printMessages(7);
				}
			}
		}
		else if (saveOrNo == "no")
		{
			isYesOrNo = true;
			printMessages(8);
		}
		else
		{
			printMessages(9);
		}
	}
}

void help()
{
	const string help = "\n*************************************************************************\n"
						"* The following commands are supported:			                *\n"
						"* 1. open <file>		opens <file>                            *\n"
						"* 2. close			closes currently opened file            *\n"
						"* 3. save			saves the currently open file           *\n"
						"* 4. saveas <file>		saves the currently open file in <file> *\n"
						"* 5. help			prints this information                 *\n"
						"* 6. exit			exists the program                      *\n"
						"*************************************************************************";
	cout << help << endl;
}