//!gcc test_expect_actual.c -I. -I../include/ -o test_expect_actual; ./test_expect_actual

#include <exotic/cester.h>

CESTER_BODY(

typedef struct a_struct {
    int index ;
    char* value;
} AStruct;

)

CESTER_BEFORE_ALL(test_instance,
    AStruct* arg_value = malloc(sizeof(AStruct*));
    arg_value->index = 20;
    arg_value->value = "A string";
    test_instance->arg = arg_value;
)

CESTER_TEST(modify_test_instance, test_instance,
    AStruct* arg_value = ((AStruct*)test_instance->arg);
    cester_assert_equal(arg_value->index++, 20);
    cester_assert_equal(arg_value->value, "A string");
    arg_value->value = "Unknown";
)

CESTER_TEST(test_direct_variables, test_instance,
    cester_assert_equal(((AStruct*)test_instance->arg)->index, 21);
    cester_assert_not_equal(((AStruct*)test_instance->arg)->value, "A string");
    cester_assert_equal(((AStruct*)test_instance->arg)->value, "Unknown");
)

CESTER_OPTIONS(
    CESTER_VERBOSE();
    CESTER_MINIMAL();
)