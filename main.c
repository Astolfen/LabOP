#include "string/string_.h"
#include "string/task/task1.h"

int main() {
    char s1[10] = "123456";
    char s2[10] = "abc";
    char *s = copy(s1, s1 + strlen(s1), s2);

    for (int i = 0; i < strlen(s2); ++i) {
        printf("%c", s2[i]);
    }
//    printf("\n%u %u %d", s2, s, strlen(s2));

    return 0;
}