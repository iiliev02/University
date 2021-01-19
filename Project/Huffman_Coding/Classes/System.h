#pragma once
#include <iostream>
#include "FrequencyTable.h"
using namespace std;

class System {
private:
	/*Извършва се компресацията на съобщението*/
	void compress();
	/*Извършва се декомпресацията на съобщението*/
	void decompress();
	/*Целостта на програмата*/
	void system();

public:
	System();
};


