#pragma once
#include <iostream>
using namespace std;

const string locateFileWithMessage = "Please enter the directory where your file is located: ";
const string fileDoesNotExist = "\nSuch a file does not exist... Try Again...\n";
const string directoryFileToSavedEncodedMessage = "Please enter the directory where you want your file to be saved: ";
const string directoryToSaveFrequencyTable = "Please enter the directory to save the frequency table of the encoded message: ";
const string fileAlreadyExist = "\nSuch a file already exist... Try Again...\n";
const string directoryWithDecodedMessage = "Please enter the directory where is file with the decoded message: ";
const string directoryWithEncodedMessage = "Please enter the directory where is file with the encoded message: ";
const string directoryWithFrequencyTable = "Please enter the directory where is file with the frequency table of encoded message: ";
const string anyFilesDoNotExist = "\nАny of the files do not exist... Try Again...\n";
const string messageIsNotReadyForDecoding = "\nThe message in this file can not be decoded. Please, try again...\n\n";
const string isNotExistFrequencyTable = "\nIf frequency table does not exist please enter the symbol \" $ \"\n\n";
const string doNotContinueWithoutFrequencyTable = "\nThe program is unable to continue unless a frequency table exist...\n";


const string invalidOptionCompressMode = "Invalid function. Please use only /Degree of Compression, Show on screen, Save and Main Menu/...";
const string invalidOptionDecompressMode = "Invalid function. Please use only /Debug mode, Show on screen, Save and Main Menu/...";
const string invalidOptionMainMenu = "Invalid function. Please use only /Compress, Decompress and Exit/...";
const string menuCompressMode = "\n ----- Option ▼ -----\n • Degree of Compression\n • Show on screen\n • Save <File Path>\n • Main Menu\n\nYour choice: ";
const string menuDecompressMode = "\n ----- Option ▼ -----\n • Debug Mode\n • Show on screen\n • Save <File Path>\n • Main Menu\n\nYour choice: ";
const string mainMenu = "\n ----- Main Menu ▼ -----\n • Compress\n • Decompress\n • Exit\n\nYour choice: ";