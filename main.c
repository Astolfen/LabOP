#include "string/string_.h"
#include "string/task/task13.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "s";
    char s2[MAX_STRING_SIZE + 1] = "s sd s";


//    for (int j = 0; j < strlen(s1); ++j) {
//        printf("%c", s1[j]);
//    }
    printf("\n%d", haveEqualWord(s1));

    return 0;
}