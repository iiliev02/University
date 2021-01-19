#include "Record.h"

Record::Record()
{
    this->symbol = '/0';
    this->count = 0;
    this->bitsCodesSymbol = " ";
}

Record::Record(const char symbol, int count, string bitsCodesSymbol)
{
    this->symbol = symbol;
    this->count = count;
    this->bitsCodesSymbol = bitsCodesSymbol;
}

Record::Record(const Record& other)
{
    this->symbol = other.symbol;
    this->count = other.count;
    this->bitsCodesSymbol = other.bitsCodesSymbol;
}

Record& Record::operator=(const Record& other)
{
    if (this != &other)
    {
        this->symbol = other.symbol;
        this->count = other.count;
        this->bitsCodesSymbol = other.bitsCodesSymbol;
    }
    return *this;
}

void Record::setSymbol(char symbol)
{
    this->symbol = symbol;
}

void Record::setCount(int count)
{
    this->count = count;
}

void Record::setBitsCodesSymbol(string bitsCodesSymbol)
{
    this->bitsCodesSymbol = bitsCodesSymbol;
}

const char Record::getSymbol() const
{
    return this->symbol;
}

int Record::getCount() const
{
    return this->count;
}

string Record::getBitsCodesSymbol() const
{
    return this->bitsCodesSymbol;
}
