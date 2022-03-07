#include "string/string_.h"
#include "string/task/task6.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "abs abc";

//    for (int i = 0; i < strlen(s1); i++) {
//        printf("%c", s1[i]);
//    }

    printf("%d", isSortedWords(s1));

    return 0;
}