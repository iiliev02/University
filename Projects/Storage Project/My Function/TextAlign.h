#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <iterator>
using namespace std;

const int pageWidth = 78;
typedef list<string> WordList;
typedef void (*PrintLineFunction)(const string);

enum class Alignment {
    Justify
};

WordList splitTextIntoWords(const string& text)
{
    WordList words;
    istringstream in(text);
    copy(istream_iterator<string>(in),
        istream_iterator<string>(),
        back_inserter(words));
    return words;
}

void justifyLine(string line)
{
    size_t pos = line.find_first_of(' ');
    if (pos != string::npos) {
        while (line.size() < pageWidth) {
            pos = line.find_first_not_of(' ', pos);
            line.insert(pos, " ");
            pos = line.find_first_of(' ', pos + 1);
            if (pos == string::npos) {
                pos = line.find_first_of(' ');
            }
        }
    }
    cout << line << endl;
}

void _printText(const string& text, PrintLineFunction printLineFunc)
{
    WordList words = splitTextIntoWords(text);

    string line;
    for (const string& word : words) 
    {
        if (line.size() + word.size() + 1 > pageWidth) 
        {
            printLineFunc(line);
            line.clear();
            line = word;
        }
        else 
        {
            if (!line.empty()) 
            {
                line.append(" ");
            }
            line.append(word);
        }
    }
    if (printLineFunc != justifyLine)
    {
        printLineFunc(line);
    }
    else
    {
        cout << line << endl;
    }
}

void printText(const std::string& text, Alignment align)
{
    PrintLineFunction array[] = { justifyLine };
    _printText(text, array[static_cast<size_t>(align)]);
}