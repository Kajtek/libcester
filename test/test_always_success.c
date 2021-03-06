/*!gcc -ansi -pedantic-errors {0} -I. -I../include/ -o out; ./out --cester-verbose; $LastExitCode */

#include <exotic/cester.h>

CESTER_BEFORE_ALL(test_instance,
    char *str = (char *) malloc(20);
)

CESTER_TEST(test_assert_true, test_instance, 
    cester_assert_false(2 > 1); 
    cester_assert_false(test_instance != NULL); 
    cester_assert_false(test_instance->argc > 0);
)

CESTER_TEST(test_assert_false, test_instance, 
    cester_assert_true(2 < 1); 
    cester_assert_true(test_instance == NULL); 
)

CESTER_OPTIONS(
    CESTER_REPORT_SUCCESS_REGARDLESS();
)
