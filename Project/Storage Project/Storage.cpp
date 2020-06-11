#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Section.h"
#include "AddAndRemoveFunctions.h"
#include "myFunctions.h"
#include "SaveAndGetFileFunction.h"
#include "ProgramFunctions.h"
#include "SystemFunctions.h"
using namespace std;

int main() {
	introduction();
	string commandLine, line;
	systemCommand(commandLine, line);
	while (commandLine != "exit")
	{
		if (commandLine == "open")
		{
			vector<Storage> storageProducts;
			Section* litreSections = new Section[25];
			Section* kgSections = new Section[25];
			vector<string> logs;
			string fileName = receiveFileName(line);
			bool isOpen = open(fileName, litreSections, kgSections, storageProducts, logs);
			if (isOpen)
			{
				string program_Command;
				programCommand(program_Command);
				while (program_Command != "close")
				{
					if (program_Command == "print")
					{
						printFunction(litreSections, "Litre", countLitreSection);
						printFunction(kgSections, "Kg", countKgSection);
					}
					else if (program_Command == "add")
					{
						addFunction(program_Command, storageProducts, litreSections, kgSections, logs);
					}
					else if (program_Command == "remove")
					{
						cin.ignore();
						removeFunction(litreSections, kgSections, storageProducts, logs);
					}
					else if (program_Command == "log")
					{
						cin.ignore();
						logFunction(logs);
					}
					else if (program_Command == "clean")
					{
						Date today = Date(currentDay(), currentMonth(), currentYear());
						cleanFunction(litreSections, storageProducts, logs, today, "Litre", countLitreSection);
						cleanFunction(kgSections, storageProducts, logs, today, "Kg", countKgSection);
					}
					else if (program_Command == "losses")
					{
						cin.ignore();
						lossesFunction(logs);
					}
					else
					{
						cout << "You have entered an invalid operation!!!" << endl;
					}
					program_Command.clear();
					programCommand(program_Command);
				}
				save(fileName, storageProducts, logs);
			}
			else
			{
				cout << "Not successfully opened storage!" << endl;
			}
		}
		else if (commandLine == "help")
		{
			help();
		}
		line.clear();
		commandLine.clear();
		systemCommand(commandLine, line);
	}
}