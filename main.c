#include "string/string_.h"
#include "string/task/task10.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "a b c";

    task10(s1);

    for (int j = 0; j < strlen(s1); ++j) {
        printf("%c", s1[j]);
    }
//    printf("\n%d %d %d", s1, w.begin, w.end);


    return 0;
}