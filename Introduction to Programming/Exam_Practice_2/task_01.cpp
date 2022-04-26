#include <iostream>
using namespace std;


int multiTwoNumber(int firstNumber, int secondNumber)
{
    int copyOfFirstNumber = firstNumber;
    for (int i = 1; i < secondNumber; i++)
    {
        firstNumber += copyOfFirstNumber;
    }
    return firstNumber;
}

int main()
{
    int firstNumber, secondNumber; 
    cout << "Enter a value for first number: ";
    cin >> firstNumber;
    cout << "Enter a value for second number: ";
    cin >> secondNumber;
    int multiply = multiTwoNumber(firstNumber, secondNumber);
    cout << multiply << endl;
}