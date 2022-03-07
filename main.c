#include "string/string_.h"
#include "string/task/task9.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "a a a a a";
    char s2[MAX_STRING_SIZE + 1] = "b b b";
    char res[MAX_STRING_SIZE + 1];

    getString(s1, s2, res);

    for (int j = 0; j < strlen(res); ++j) {
        printf("%c", res[j]);
    }


    return 0;
}