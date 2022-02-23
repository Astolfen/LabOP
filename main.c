#include "libs/data_structures/matrix/matrix_test.h"
#include "libs/data_structures/matrix/test_task.h"

#define TEST
#define TEST_TASK

int main() {
#ifdef TEST
    test_matrix();
#endif

#ifdef TEST_TASK
    test_task();
#endif

    return 0;
}