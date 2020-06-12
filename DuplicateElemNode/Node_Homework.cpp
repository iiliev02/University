#include <iostream>
#include <vector>
#include <algorithm>
#include "linked_list.h"
using namespace std;



void doubleElem(LinkedList<int>& list, int value)
{
    vector<int> position;
    for (size_t i = 0; i < list.getSize(); i++)
    {
        if (list.get(i) == value)
        {
            position.push_back(i);
        }
    }
    for (size_t i = 0; i < position.size(); i++)
    {
        if (i == 0)
        {
            list.push(value, position[i] + 1);
        }
        else
        {
            list.push(value, position[i] + 2);
        }
    }
}

int main() {
	int value;
    cout << "Enter a value you want to duplicate: ";
	cin >> value;
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(3);
    list.push_back(4);
    doubleElem(list, value);
    list.print();
}
