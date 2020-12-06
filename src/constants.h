#ifndef TRANSLIT_CONSTANTS_H
#define TRANSLIT_CONSTANTS_H

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

#endif //TRANSLIT_CONSTANTS_H
