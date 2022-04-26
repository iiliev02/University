#include "FrequencyTable.h"

void FrequencyTable::funcEncoding(const Node* root, pair<char, string> charWithCode, vector<pair<char, string>>&vect)
{
    if (root == nullptr)
    {
        return;
    }

    charWithCode.first = root->letter;

    if (root->left == nullptr && root->right == nullptr)
    {
        vect.push_back(charWithCode);
    }

    if (root->left != nullptr)
    {
        charWithCode.second += '0';
        funcEncoding(root->left, charWithCode, vect);
        charWithCode.second = charWithCode.second.substr(0, charWithCode.second.length() - 1);
    }

    if (root->right != nullptr)
    {
        charWithCode.second += '1';
        funcEncoding(root->right, charWithCode, vect);
        charWithCode.second = charWithCode.second.substr(0, charWithCode.second.length() - 1);
    }
}

void FrequencyTable::funcDecoding(const Node* root, const Node* startRoot, string messageForDecoding, string& decodedMessage, int& indexLettre)
{
    if (indexLettre > messageForDecoding.size())
    {
        return;
    }
    if (messageForDecoding[indexLettre] == '0')
    {
        if (root->left->letter != '\0')
        {
            decodedMessage += root->left->letter;
            funcDecoding(startRoot, startRoot, messageForDecoding, decodedMessage, ++indexLettre);
        }
        else
        {
            funcDecoding(root->left, startRoot, messageForDecoding, decodedMessage, ++indexLettre);
        }
    }
    if (messageForDecoding[indexLettre] == '1')
    {
        if (root->right->letter != '\0')
        {
            decodedMessage += root->right->letter;
            funcDecoding(startRoot, startRoot, messageForDecoding, decodedMessage, ++indexLettre);
        }
        else
        {
            funcDecoding(root->right, startRoot, messageForDecoding, decodedMessage, ++indexLettre);
        }
    }
}

FrequencyTable::FrequencyTable()
{
    this->frequencyTable;
}

FrequencyTable::FrequencyTable(const FrequencyTable& other)
{
    this->frequencyTable = other.frequencyTable;
}

FrequencyTable& FrequencyTable::operator=(const FrequencyTable& other)
{
    if (this != &other)
    {
        this->frequencyTable = other.frequencyTable;
    }
    return *this;
}

void FrequencyTable::pushRecord(char symbol)
{
    if (this->frequencyTable.size() == 0)
    {
        Record record = Record(symbol, 1, " ");
        this->frequencyTable.push_back(record);
    }
    else
    {
        int positionOfSymbol = isExistSymbolReturnPosition(symbol);
        if (positionOfSymbol == -1)
        {
            Record record = Record(symbol, 1, " ");
            this->frequencyTable.push_back(record);
        }
        else
        {
            this->frequencyTable[positionOfSymbol].setCount(this->frequencyTable[positionOfSymbol].getCount() + 1);
        }
    }
}

int FrequencyTable::isExistSymbolReturnPosition(char symbol)
{
    int positionSymbol = -1;
    for (int i = 0; i < this->frequencyTable.size(); i++)
    {
        if (this->frequencyTable[i].getSymbol() == symbol)
        {
            positionSymbol = i;
        }
    }
    return positionSymbol;
}

vector<Node*> FrequencyTable::createNodes()
{
    vector<Node*> nodes;
    for (int i = 0; i < getSize(); i++)
    {
        Node* node = new Node{ getRecord(i).getCount(), getRecord(i).getSymbol(), nullptr, nullptr };
        nodes.push_back(node);
    }
    return nodes;
}

Record FrequencyTable::getRecord(int index) const
{
    return this->frequencyTable[index];
}

void FrequencyTable::addRecord(const char symbol, int count)
{
    Record newRecord = Record(symbol, count, " ");
    this->frequencyTable.push_back(newRecord);
}

void FrequencyTable::addCodes(const Node* root)
{
    pair<char, string> charWithCode;
    vector<pair<char, string>> vect;
    funcEncoding(root, charWithCode, vect);
    for (int i = 0; i < this->frequencyTable.size(); i++)
    {
        for (int j = 0; j < vect.size(); j++)
        {
            if (this->frequencyTable[i].getSymbol() == vect[j].first)
            {
                this->frequencyTable[i].setBitsCodesSymbol(vect[j].second);
            }
        }
    }
}

int FrequencyTable::binaryToDecimal(string binaryNumber)
{
    int resultDecimalNumber = 0;
    int base = 2;
    int degreeOfNumber = 0;
    int len = binaryNumber.length();
    for (int i = len - 1; i >= 0; i--)
    {
        int digit = ((int)binaryNumber[i] - (int)'0');
        resultDecimalNumber += digit * pow(base, degreeOfNumber);
        degreeOfNumber++;
    }
    return resultDecimalNumber;
}

void FrequencyTable::encoding(string message, string& encodedMessage)
{
    for (int i = 0; i < message.size(); i++)
    {
        pushRecord(message[i]);
    }
    HuffmanTree tree = HuffmanTree(createNodes());
    addCodes(tree.getRoot());
    for (int i = 0; i < message.size(); i++)
    {
        for (int j = 0; j < getSize(); j++)
        {
            if (message[i] == getRecord(j).getSymbol())
            {
                encodedMessage += getRecord(j).getBitsCodesSymbol();
            }
        }
    }
}

void FrequencyTable::decoding(string messageForDecoding, string& decodedMessage)
{
    int indexLetter = 0;
    HuffmanTree tree = HuffmanTree(createNodes());
    funcDecoding(tree.getRoot(), tree.getRoot(), messageForDecoding, decodedMessage, indexLetter);
}

int FrequencyTable::degreeOfCompression(string message, string encodedMessage)
{
    int lenghtMessage = message.size();
    int lenghtEncodedMessage = encodedMessage.size();
    int result = ((lenghtEncodedMessage * encodedCharBits) * 100) / (lenghtMessage * charBits);
    return result;
}

void FrequencyTable::debugMode(string messageForDecoding)
{
    int nextCodeBox = 8, baseBits = 8;
    string codeBoxes;
    vector <string> eightBitsCodeBoxes;
    for (int i = 0; i < messageForDecoding.size(); i++)
    {
        if (i == nextCodeBox || i + 1 == messageForDecoding.size())
        {
            if (i + 1 == messageForDecoding.size())
            {
                codeBoxes += messageForDecoding[i];
            }
            eightBitsCodeBoxes.push_back(codeBoxes);
            nextCodeBox += baseBits;
            codeBoxes.clear();
        }
        codeBoxes += messageForDecoding[i];
    }
    for (int i = 0; i < eightBitsCodeBoxes.size(); i++)
    {
        if (i + 1 == eightBitsCodeBoxes.size())
        {
            cout << binaryToDecimal(eightBitsCodeBoxes[i]) << endl;
        }
        else
        {
            cout << binaryToDecimal(eightBitsCodeBoxes[i]) << ", ";
        }
    }
}

const int FrequencyTable::getSize() const
{
    return this->frequencyTable.size();
}

void FrequencyTable::print()
{
    for (int i = 0; i < this->frequencyTable.size(); i++)
    {
        cout << this->frequencyTable[i].getSymbol() << " " << this->frequencyTable[i].getCount() << " " << this->frequencyTable[i].getBitsCodesSymbol() << endl;
    }
}

bool FrequencyTable::checkFileIsExist(string filePath)
{
    ifstream check(filePath);
    return check.good();
}

bool FrequencyTable::checkMessageIsReadyToDecompress(string messageForDecoding)
{
    for (int i = 0; i < messageForDecoding.size(); i++)
    {
        if (messageForDecoding[i] != '0' || messageForDecoding[i]!= '1')
        {
            return false;
        }
    }
    return true;
}

void FrequencyTable::readFromFileEncodingMessage(string& message)
{
    string filePath;
    cout << locateFileWithMessage;
    getline(cin, filePath);
    if (checkFileIsExist(filePath))
    {
        ifstream readingFile;
        readingFile.open(filePath, ios::in);
        if (readingFile.is_open())
        {
            while (!readingFile.eof())
            {
                getline(readingFile, message);
            }
            readingFile.close();
        }
    }
    else
    {
        cout << fileDoesNotExist << endl;
        readFromFileEncodingMessage(message);
    }
    
}

void FrequencyTable::writeInFileEncodedMessage(string encodedMessage)
{
    string filePath;
    cout << directoryFileToSavedEncodedMessage;
    getline(cin, filePath);
    if (checkFileIsExist(filePath))
    {
        cout << fileAlreadyExist << endl;
        writeInFileEncodedMessage(encodedMessage);
    }
    else
    {
        ofstream writingFile;
        writingFile.open(filePath, ios::out);
        if (writingFile.is_open())
        {
            writingFile << encodedMessage;
            writingFile.close();
        }
    }
}

void FrequencyTable::writeInFileFrequencyTable()
{
    string filePathFrequencyTable;
    cout << directoryToSaveFrequencyTable;
    getline(cin, filePathFrequencyTable);
    if (checkFileIsExist(filePathFrequencyTable))
    {
        cout << fileAlreadyExist << endl;
        writeInFileFrequencyTable();
    }
    else
    {
        ofstream writingFileFrequencyTable;
        writingFileFrequencyTable.open(filePathFrequencyTable, ios::out);
        if (writingFileFrequencyTable.is_open())
        {
            for (int i = 0; i < getSize(); i++)
            {
                writingFileFrequencyTable << getRecord(i).getSymbol() << " " << getRecord(i).getCount() << endl;
            }
            writingFileFrequencyTable.close();
        }
    }
}

void FrequencyTable::readEncodedMessageFromFile(string& messageForDecoding)
{
    string filePathToDecodeMessage;
    cout << directoryWithEncodedMessage;
    getline(cin, filePathToDecodeMessage);
    if (checkFileIsExist(filePathToDecodeMessage))
    {
        ifstream fileDecodeMessage;
        fileDecodeMessage.open(filePathToDecodeMessage, ios::in);
        if (fileDecodeMessage.is_open())
        {
            while (!fileDecodeMessage.eof())
            {
                getline(fileDecodeMessage, messageForDecoding);
            }
            fileDecodeMessage.close();
        }
        if (checkMessageIsReadyToDecompress(messageForDecoding))
        {
            cout << messageIsNotReadyForDecoding;
            readEncodedMessageFromFile(messageForDecoding);
        }
    }
    else
    {
        cout << fileDoesNotExist;
        readEncodedMessageFromFile(messageForDecoding);
    }
}

void FrequencyTable::readFrequencyTableToDecodeMessage(bool& ifContinue)
{
    string filePathToFrequencyTable;
    cout << isNotExistFrequencyTable << directoryWithFrequencyTable;
    getline(cin, filePathToFrequencyTable);
    if (filePathToFrequencyTable == "$")
    {
        cout << doNotContinueWithoutFrequencyTable;
        ifContinue = false;
        return;
    }
    else
    {
        if (checkFileIsExist(filePathToFrequencyTable))
        {
            ifstream fileFrequencyTable;
            fileFrequencyTable.open(filePathToFrequencyTable, ios::in);
            if (fileFrequencyTable.is_open())
            {
                string line;
                while (!fileFrequencyTable.eof())
                {
                    getline(fileFrequencyTable, line);
                    if (line != "")
                    {
                        line.erase(remove(line.begin(), line.end(), ' '), line.end());
                        addRecord(line[0], atoi(line.substr(1, line.size() - 1).c_str()));
                    }
                }
                fileFrequencyTable.close();
            }
        }
        else
        {
            cout << fileDoesNotExist << endl;
            readFrequencyTableToDecodeMessage(ifContinue);
        }
    }
    
}

void FrequencyTable::writeInFileDecodedMessage(string decodedMessage)
{
    string filePath;
    cout << directoryWithDecodedMessage;
    getline(cin, filePath);
    if (checkFileIsExist(filePath))
    {
        cout << fileAlreadyExist << endl;
        writeInFileDecodedMessage(decodedMessage);
    }
    else
    {
        ofstream writingFile;
        writingFile.open(filePath, ios::out);
        if (writingFile.is_open())
        {
            writingFile << decodedMessage;
            writingFile.close();
        }
    }
}

void FrequencyTable::compressing()
{
    string message, encodedMessage, option;
    readFromFileEncodingMessage(message);
    encoding(message, encodedMessage);
    cout << menuCompressMode;
    getline(cin, option);
    transform(option.begin(), option.end(), option.begin(), ::tolower);
    cout << endl;
    while (option != "main menu")
    {
        if (option == "degree of compression")
        {
            int bitsBeforeCompress = message.size() * charBits;
            int bitsAfterCompress = encodedMessage.size() * encodedCharBits;
            int percentCompress = degreeOfCompression(message, encodedMessage);
            cout << "From " << bitsBeforeCompress << " bits we received " << bitsAfterCompress << " bits compressed information around " << percentCompress << "% from the original size." << endl;
        }
        else if (option == "show on screen")
        {
            cout << "Тhe message " << message << " is encoded as follows: " << encodedMessage << endl;
        }
        else if (option == "save")
        {
            writeInFileEncodedMessage(encodedMessage);
            writeInFileFrequencyTable();
        }
        else
        {
            cout << invalidOptionCompressMode << endl;
        }
        cout << menuCompressMode;
        getline(cin, option);
        transform(option.begin(), option.end(), option.begin(), ::tolower);
        cout << endl;
    }
}

void FrequencyTable::decompressing()
{
    bool ifContinue = true;
    string messageForDecoding, decodedMessage, option;
    readEncodedMessageFromFile(messageForDecoding);
    readFrequencyTableToDecodeMessage(ifContinue);
    if (!ifContinue)
    {
        return;
    }
    decoding(messageForDecoding, decodedMessage);
    cout << menuDecompressMode;
    getline(cin, option);
    transform(option.begin(), option.end(), option.begin(), ::tolower);
    cout << endl;
    while (option != "main menu")
    {
        if (option == "debug mode")
        {
            debugMode(messageForDecoding);
        }
        else if (option == "show on screen")
        {
            cout << "The encoded message " << messageForDecoding << "  is decoded as follows: " << decodedMessage << endl;
        }
        else if (option == "save")
        {
            writeInFileDecodedMessage(decodedMessage);
        }
        else
        {
            cout << invalidOptionCompressMode << endl;
        }
        cout << menuDecompressMode;
        getline(cin, option);
        transform(option.begin(), option.end(), option.begin(), ::tolower);
        cout << endl;
    }
}
