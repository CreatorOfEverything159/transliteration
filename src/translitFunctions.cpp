#include "translitFunctions.h"
#include "constants.h"

bool isCyrillic(char a, char b) {
    return a == -48 && b >= -112 && b <= -65 ||
           a == -47 && b >= -128 && b <= -113 ||
           a == -48 && b == -127 ||
           a == -47 && b == -111;
}

int getRusLetterIndex(char a, char b) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (rusAlphabet[i][0] == a && rusAlphabet[i][1] == b) { return i; }
    }
    return -1;
}

void addToOutLine(char* outLine, int& iOutLine, const char* symbol) {
    unsigned short i = 0;
    while (i < sizeof(symbol) && symbol[i] != '\0') {
        outLine[iOutLine++] = symbol[i++];
    }
}

char* transliterationRusToEng(const char* inLine) {
    int iInLine = 0;
    int iOutLine = 0;
    int letterIndex;
    char* outLine = new char[TEXT_SIZE];

    while (iInLine < TEXT_SIZE && inLine[iInLine] != '\0') {
        if (iInLine + 1 < TEXT_SIZE && isCyrillic(inLine[iInLine], inLine[iInLine + 1])) {
            letterIndex = getRusLetterIndex(inLine[iInLine], inLine[iInLine + 1]);
            addToOutLine(outLine, iOutLine, engTransliteration[letterIndex]);
            iInLine += 2;
        }
        else { outLine[iOutLine++] = inLine[iInLine++]; }
    }

    return outLine;
}