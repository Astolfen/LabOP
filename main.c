#include "string/string_.h"
#include "string/task/task8.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "ba,asd,ss,fggf";
//    for (int j = 0; j < bag_.size; ++j) {
//        printf("\n");
//    }

    printf("\n%d", getCountPalindromeWord(s1));

    return 0;
}