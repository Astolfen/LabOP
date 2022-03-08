#include "string/string_.h"
#include "string/task/task18.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "s s";

    task18(s1, s2);

    for (int j = 0; j < strlen(s1); ++j) {
        printf("%c", s1[j]);
    }
    printf("\n");
    for (int j = 0; j < strlen(s2); ++j) {
        printf("%c", s2[j]);
    }
//    printf("\n%d", task16(s1, s2));

    return 0;
}