#include "string/string_.h"
#include "string/task/task17.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "ssda sfa s";
    char s2[MAX_STRING_SIZE + 1] = "s a s";

    task17a(s1);

    for (int j = 0; j < strlen(s1); ++j) {
        printf("%c", s1[j]);
    }
//    printf("\n%d", task16(s1, s2));

    return 0;
}