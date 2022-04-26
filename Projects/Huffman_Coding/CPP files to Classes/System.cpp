#include "System.h"

void System::compress()
{
	FrequencyTable frequencyTable;
	frequencyTable.compressing();
}

void System::decompress()
{
	FrequencyTable frequencyTable;
	frequencyTable.decompressing();
}

void System::system()
{
	string option;
	cout << mainMenu;
	getline(cin, option);
	transform(option.begin(), option.end(), option.begin(), ::tolower);
	cout << endl;
	while (option != "exit")
	{
		if (option == "compress")
		{
			compress();
		}
		else if (option == "decompress")
		{
			decompress();
		}
		else
		{
			cout << invalidOptionMainMenu << endl;
		}
		cout << mainMenu;
		getline(cin, option);
		transform(option.begin(), option.end(), option.begin(), ::tolower);
		cout << endl;
	}
}

System::System()
{
	system();
}
