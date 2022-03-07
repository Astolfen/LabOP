#include "string/string_.h"
#include "string/task/task5.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "abc abc abs abc nds";
    char w1[MAX_STRING_SIZE + 1] = "abc";
    char w2[MAX_STRING_SIZE + 1] = "abcdf";

    replace(s1,w1,w2);

    for (int i = 0; i < strlen(s1); i++) {
        printf("%c", s1[i]);
    }

    return 0;
}