#ifndef INC_TASK4_H
#define INC_TASK4_H

#include "../string_.h"

void task4(char *s) {
    char *recPtr = stringBuffer_;
    copy(s, getEndOfString(s) + 1, stringBuffer_);
    char *start = s;
    while (*recPtr != '\0') {
        if (isdigit(*recPtr)) {
            int count = *recPtr - '0';
            while (count--)
                *start++ = ' ';
        } else
            *start++ = *recPtr;
        recPtr++;
    }
    *start = '\0';
}

void test_task4_1() {
    char s[MAX_STRING_SIZE + 1] = "A3B1C";

    task4(s);

    char res[MAX_STRING_SIZE + 1] = "A   B C";

    ASSERT_STRING(res, s);
}

void test_task4_2() {
    char s[MAX_STRING_SIZE + 1] = "A1";

    task4(s);

    char res[MAX_STRING_SIZE + 1] = "A ";

    ASSERT_STRING(res, s);
}

void test_task4_3() {
    char s[MAX_STRING_SIZE + 1] = "A0";

    task4(s);

    char res[MAX_STRING_SIZE + 1] = "A";

    ASSERT_STRING(res, s);
}

void test_task4() {
    test_task4_1();
    test_task4_2();
    test_task4_3();
}

#endif