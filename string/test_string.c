#include "test_string.h"

void test_strlen_NoEmpty() {
    char s[] = "asfsbeb";

    assert(strlen(s) == 7);
}

void test_strlen_space() {
    char s[] = " ";

    assert(strlen(s) == 1);
}

void test_strlen_Empty() {
    char s[] = "";

    assert(strlen(s) == 0);
}

void test_strlen() {
    test_strlen_NoEmpty();
    test_strlen_Empty();
    test_strlen_space();
}

void test_find_MoreCharacter() {
    char s[] = "bc dakfsa";
    int ch = 'a';

    char *res = s + 4;
    assert(find(s, s + strlen(s), ch) == res);
}

void test_find_OneCharacter() {
    char s[] = "bc dkfsa";
    int ch = 'a';

    char *res = s + 7;
    assert(find(s, s + strlen(s), ch) == res);
}

void test_find_NotCharacter() {
    char s[] = "bc dkfs";
    int ch = 'a';

    char *res = s + 7;
    assert(find(s, s + strlen(s), ch) == res);
}

void test_find_Empty() {
    char s[] = "";
    int ch = 'a';

    char *res = s;
    assert(find(s, s + strlen(s), ch) == res);
}

void test_find() {
    test_find_MoreCharacter();
    test_find_OneCharacter();
    test_find_NotCharacter();
    test_find_Empty();
}

void test_findNonSpace_OnlySpace() {
    char s[] = "      ";;

    char *res = s + strlen(s);
    assert(findNonSpace(s) == res);
}

void test_findNonSpace_StandardInput() {
    char s[] = " a s s";

    char *res = s + 1;
    assert(findNonSpace(s) == res);
}

void test_findNonSpace_Empty() {
    char s[] = "";

    char *res = s;
    assert(findNonSpace(s) == res);
}

void test_findNonSpace() {
    test_findNonSpace_OnlySpace();
    test_findNonSpace_StandardInput();
    test_findNonSpace_Empty();
}

void test_findSpace_OnlyNonSpace() {
    char s[] = "czcxvcxvxv";

    char *res = s + strlen(s);
    assert(findSpace(s) == res);
}

void test_findSpace_StandardInput() {
    char s[] = "sdf dfs";

    char *res = s + 3;
    assert(findSpace(s) == res);
}

void test_findSpace_Empty() {
    char s[] = "";

    char *res = s;
    assert(findSpace(s) == res);
}

void test_findSpace() {
    test_findSpace_StandardInput();
    test_findSpace_OnlyNonSpace();
    test_findSpace_Empty();
}

void test_findNonSpaceReverse_OnlySpace() {
    char s[] = "      ";

    char *res = s - 1;
    assert(findNonSpaceReverse(s + strlen(s) - 1, s - 1) == res);
}

void test_findNonSpaceReverse_StandardInput() {
    char s[] = "sfsd sdfd sdf ";

    char *res = s + 12;
    assert(findNonSpaceReverse(s + strlen(s) - 1, s - 1) == res);;
}

void test_findNonSpaceReverse_Empty() {
    char s[] = "";

    char *res = s - 1;
    assert(findNonSpaceReverse(s + strlen(s) - 1, s - 1) == res);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_OnlySpace();
    test_findNonSpaceReverse_StandardInput();
    test_findNonSpaceReverse_Empty();
}

void test_findSpaceReverse_OnlyLetters() {
    char s[] = "sdsadasd";

    char *res = s - 1;
    assert(findSpaceReverse(s + strlen(s) - 1, s - 1) == res);
}

void test_findSpaceReverse_StandardWord() {
    char s[] = "dsa asdd sd";

    char *res = s + 8;
    assert(findSpaceReverse(s + strlen(s) - 1, s - 1) == res);
}

void test_findSpaceReverse_Empty() {
    char s[] = "";

    char *res = s - 1;
    assert(findSpaceReverse(s + strlen(s) - 1, s - 1) == res);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_OnlyLetters();
    test_findSpaceReverse_StandardWord();
    test_findSpaceReverse_Empty();
}

void test_strcmp_Equal() {
    char s[] = "12";

    assert(strcmp(s, s) == 0);
}

void test_strcmp_StandardInput1() {
    char s1[] = "12";
    char s2[] = "21";

    assert(strcmp(s1, s2) < 0);
}

void test_strcmp_StandardInput2() {
    char s1[] = "12";
    char s2[] = "21";

    assert(strcmp(s2, s1) > 0);
}

void test_strcmp_Empty() {
    char s[] = "";

    assert(strcmp(s, s) == 0);
}

void test_strcmp() {
    test_strcmp_Equal();
    test_strcmp_StandardInput1();
    test_strcmp_StandardInput2();
    test_strcmp_Empty();
}

void test_copy_StandardInput() {
    char s1[] = "12";
    char s2[] = "21";

    assert(copy(s2, getEndOfString(s2), s1) == s1 + 2);
    assert(s1[0] == '2');
    assert(s1[1] == '1');
}

void test_copy() {
    test_copy_StandardInput();
}

void test_getEndOfString_Empty() {
    char s[] = "";

    assert(getEndOfString(s) == s);
}

void test_getEndOfString_Standard() {
    char s[] = "122";

    assert(getEndOfString(s) == s + strlen(s));
}

void test_getEndOfString() {
    test_getEndOfString_Empty();
    test_getEndOfString_Standard();
}

void test_areWordsEqual_Standard1() {
    char s1[] = "abc";
    char s2[] = "abc";
    WordDescriptor w1, w2;
    getWord(s1, &w1);
    getWord(s2, &w2);

    assert(areWordsEqual(w1, w2) == 1);
}

void test_areWordsEqual_Standard2() {
    char s1[] = "abc";
    char s2[] = "abs";
    WordDescriptor w1, w2;
    getWord(s1, &w1);
    getWord(s2, &w2);

    assert(areWordsEqual(w1, w2) == 0);
}

void test_areWordsEqual() {
    test_areWordsEqual_Standard1();
    test_areWordsEqual_Standard2();
}

void test_string() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_getEndOfString();
    test_areWordsEqual();
}