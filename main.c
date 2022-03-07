#include "string/string_.h"
#include "string/task/task3.h"

int main() {
    char s1[100] = "z1v2 fs3f";

    task3(s1);

    for (int i = 0; i < strlen(s1); i++) {
        printf("%c", s1[i]);
    }

    printf("\n%d", strlen(s1));

    return 0;
}