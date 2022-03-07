#include "string/string_.h"
#include "string/task/task1.h"
#include "string/task/task2.h"

int main() {
    char s1[100] = "abbbscx  frsf";
    removeAdjacentEqualLetters(s1);

    for (int i = 0; i < strlen(s1); i++) {
        printf("%c", s1[i]);
    }
    printf("\n%d", strlen(s1));

    return 0;
}