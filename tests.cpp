#include "gtest/gtest.h"
#include "translitFunctions.h"

TEST(translit, expectedLowerCase) {
    const char* expected = transliterationRusToEng("а б в г д е ё ж з и й к л м н о п р с т у ф х ц ч ш щ ъ ы ь э ю я");
    const char* actual = "a b v g d e jo zh z i j k l m n o p r s t u f kh ts ch sh sh \" y \' e ju ja";
    EXPECT_STREQ(actual, expected);
    delete[] expected;
}

TEST(translit, expectedHigherCase) {
    const char* expected = transliterationRusToEng("А Б В Г Д Е Ё Ж З И Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ы Э Ю Я");
    const char* actual = "A B V G D E Jo Zh Z I J K L M N O P R S T U F Kh Ts Ch Sh Sh Y E Ju Ja";
    EXPECT_STREQ(actual, expected);
    delete[] expected;
}

TEST(translit, expectedInputValues) {
    const char* expected = transliterationRusToEng("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=");
    const char* actual = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=";
    EXPECT_STREQ(actual, expected);
    delete[] expected;
}

TEST(translit, expectedCorrectTranslit) {
    const char* expected = transliterationRusToEng("Съешь ещё этих мягких французских булок да выпей чаю!");
    const char* actual = "S\"esh' eshjo etikh mjagkikh frantsuzskikh bulok da vypej chaju!";
    EXPECT_STREQ(actual, expected);
    delete[] expected;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}