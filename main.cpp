#include <iostream>
#include "src/constants.h"
#include "src/translitFunctions.h"
using namespace std;

int main() {
    char* inLine = new char[TEXT_SIZE];
    char* outLine;

    cout << "Enter the text on russian: ";
    cin.getline(inLine, TEXT_SIZE);
    cout << endl;

    cout << "Get your translit: ";
    outLine = transliterationRusToEng(inLine);
    cout << outLine;

    delete[] inLine;
    delete[] outLine;

    return 0;
}