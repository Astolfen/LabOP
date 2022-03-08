#include "string/string_.h"
#include "string/task/task12.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "sd sdf sf";
    char s2[MAX_STRING_SIZE + 1] = "s sd s";

    task12(s1, s2);

//    for (int j = 0; j < strlen(s1); ++j) {
//        printf("%c", s1[j]);
//    }
//    printf("\n%d %d %d", s1, w2.end, w2.begin);

    return 0;
}