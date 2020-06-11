#include <iostream>
#include <cstring>
#include <string>
#include "rational.cpp"
#include <sstream>
#include <cmath>
using namespace std;


int main() {
    Rational sumFirstLine;
    Rational sumSecondLine;
    Rational realSumFirstLine;
    Rational realSumSecondLine;
    long long int size = 9223372036854775807;
    long long int countOperator = 1;
    string sumToString;
    string numOne;
    string numTwo;
    long long int num = 0;
    long long int den = 0;
    size_t line = 0;
    for(size_t i = 1; i <= size; i++)
    {
        if(num < 0 || den < 0)
        {
            break;
        }
        realSumFirstLine = sumFirstLine;
        if(i % 2 == 0)
        {
            sumFirstLine = sumFirstLine - Rational(1, i);
        }
        else
        {
            sumFirstLine = sumFirstLine + Rational(1, i);
        }
        sumToString = sumFirstLine.toString();
        for(size_t j = 0; j < sumToString.size(); j++)
        {
            if(sumToString[j] == '/')
            {
                line = j;
            }
        }
        numOne = sumToString.substr(0, line);
        numTwo = sumToString.substr(line + 1);
        stringstream geek1(numOne);
        geek1 >> num;
        stringstream geek2(numTwo);
        geek2 >> den;
    }
    sumToString.clear();
    numOne.clear();
    numTwo.clear();
    num = 0;
    den = 0;
    line = 0;
    for(size_t i = 1; i <= size; i += 2)
    {
        if(num > den)
        {
            break;
        }
        realSumSecondLine = sumSecondLine;
        if(countOperator % 2 == 0)
        {
            sumSecondLine = sumSecondLine - Rational(1, i);
        }
        else
        {
            sumSecondLine = sumSecondLine + Rational(1, i);
        }
        countOperator++;
        sumToString = sumSecondLine.toString();
        for(size_t j = 0; j < sumToString.size(); j++)
        {
            if(sumToString[j] == '/')
            {
                line = j;
            }
        }
        numOne = sumToString.substr(0, line);
        numTwo = sumToString.substr(line + 1);
        stringstream geek1(numOne);
        geek1 >> num;
        stringstream geek2(numTwo);
        geek2 >> den;
    }
    double ln = log(2);
    double pi = M_PI / 4;
    cout << realSumFirstLine << endl;
    cout << "Тhe error of the approximations between the two values: " << ln - realSumFirstLine.toDouble() << endl;
    cout << realSumSecondLine << endl;
    cout << "Тhe error of the approximations between the two values: " << pi - realSumSecondLine.toDouble() << endl;
}