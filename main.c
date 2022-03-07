#include "string/string_.h"
#include "string/task/task4.h"

int main() {
    char s1[MAX_STRING_SIZE + 1] = "A3B0C1";

    printf("%d\n", strlen(s1));

    task4(s1);

    for (int i = 0; i < strlen(s1); i++) {
        printf("%c", s1[i]);
    }

    printf("\n%d", strlen(s1));

    return 0;
}