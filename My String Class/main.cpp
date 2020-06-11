#include <iostream>
using namespace std;
const size_t MAX_WORD = 256;

size_t lenWord(const char* word)
{
    int i = -1;
    while (word[++i]);
    return i;
}

class MyStringClass
{
private:
    char myWord[MAX_WORD];
public:
    MyStringClass() : myWord("") {}

    MyStringClass(const char* myWordCopy)
    {
        if(lenWord(myWordCopy) > MAX_WORD)
        {
            cout << "The length of the word is greater than max word length" << endl;
            exit(1);
        }

        for (int i = 0; i < lenWord(myWordCopy) + 1; i++)
        {
            this->myWord[i] = myWordCopy[i];
        }
    }

    char& operator[](const size_t i){
        size_t sizeMyWord = lenWord(this->myWord);
        if(i > sizeMyWord)
        {
            cout << "Value of the i is greater than the length of the word" << endl;
            exit(1);
        }
        return myWord[i];
    }

    MyStringClass operator+(const char letter){
        size_t wordLenght = lenWord(myWord);
        if(wordLenght >= MAX_WORD)
        {
            cout << "You exceed the maximum word length" << endl;
            exit(1);
        }
        MyStringClass examWord(myWord);
        examWord[wordLenght] = letter;
        examWord[wordLenght + 1] = '\0';
        return examWord;
    }

    MyStringClass operator+(const MyStringClass wordOne){
        size_t sizeFirstWord = lenWord(myWord);
        const char* secondWordToApply = wordOne.myWord;
        size_t sizeSecondWord = lenWord(secondWordToApply);
        if(sizeFirstWord + sizeSecondWord > MAX_WORD){
            cout << "You exceed the maximum word length" << endl;
            exit(1);
        }
        MyStringClass tempWord(myWord);
        size_t countLetter = 0;
        for(size_t i = sizeFirstWord; i < sizeFirstWord + sizeSecondWord + 1; i++)
        {
            tempWord[i] = secondWordToApply[countLetter++];
        }
        return tempWord;
    }

    MyStringClass& operator=(const MyStringClass& word1){
        const char* word = word1.myWord;
        size_t sizeWord = lenWord(word);
        if(sizeWord > MAX_WORD)
        {
            cout << "You exceed the maximum word length" << endl;
            exit(1);
        }
        if (this->myWord != word)
        {
            for(size_t i = 0; i < lenWord(word) + 1; i++) {
                this->myWord[i] = word[i];
            }
        }
        return *this;
    }

    void printMethod() const{
        cout << this->myWord << endl;
    }
};
int main() {

    MyStringClass wordOne = MyStringClass("abc");
    MyStringClass wordTwo = MyStringClass("qwerty");
    //wordOne[1] = 'f';  //--Замяна на символ
    //MyStringClass wordThree = wordOne + 'V'; //--Добавяне на символ към дума
    //MyStringClass wordFour = wordOne + wordTwo + wordThree;  //--Сливане на две думи
    //wordOne = wordTwo; //--Замяна на една дума с друга
    //wordOne.printMethod();
    //wordThree.printMethod();
    //wordFour.printMethod();
}