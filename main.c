#include "string/string_.h"
#include "string/task/task19.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "z";
    char s2[MAX_STRING_SIZE + 1] = "a";
    WordDescriptor w;
    getWord(s2, &w);

//    for (int j = 0; j < strlen(s1); ++j) {
//        printf("%c", s1[j]);
//    }
    printf("\n%d", task19(s1, w));

    return 0;
}