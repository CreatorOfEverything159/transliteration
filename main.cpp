#include <iostream>
using namespace std;

const int LETTER_SIZE = 3;
const int ALPHABET_SIZE = 66;
const int TEXT_SIZE = 512;

typedef char letter[LETTER_SIZE];

const letter rusAlphabet[ALPHABET_SIZE] = {
        "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й",
        "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф",
        "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я",
        "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й",
        "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф",
        "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я"
};

const letter engTransliteration[ALPHABET_SIZE] = {
        "a",  "b",  "v",  "g",  "d",  "e",  "jo", "zh", "z", "i",  "j",
        "k",  "l",  "m",  "n",  "o",  "p",  "r",  "s",  "t", "u",  "f",
        "kh", "ts", "ch", "sh", "sh", "\"", "y",  "\'", "e", "ju", "ja",
        "A",  "B",  "V",  "G",  "D",  "E",  "Jo", "Zh", "Z", "I",  "J",
        "K",  "L",  "M",  "N",  "O",  "P",  "R",  "S",  "T", "U",  "F",
        "Kh", "Ts", "Ch", "Sh", "Sh", "\"", "Y",  "\'", "E", "Ju", "Ja"
};

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