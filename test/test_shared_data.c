//!gcc {0} -IC -I../include/ -o out; ./out --cester-noisolation
//this test shares data between tests

#include <exotic/cester.h>

CESTER_BEFORE_ALL(test_instance,
    test_instance->arg = "Hello World";
)

CESTER_TEST(check_number_equals, test_instance,
    cester_assert_true(cester_string_equals(test_instance->arg, "Hello World"));
    cester_assert_not_null(test_instance->arg);
    cester_assert_equal(test_instance->arg, test_instance->arg);
    cester_assert_not_equal(NULL, test_instance->arg);
)

CESTER_TEST(validate_shared_arg, test_instance,
    cester_assert_true(cester_string_equals(test_instance->arg, "Hello World"));
    cester_assert_false(cester_string_equals(test_instance->arg, "World"));
    cester_assert_false(cester_string_equals(test_instance->arg, "Hello"));
)

CESTER_OPTIONS(
    CESTER_VERBOSE();
    CESTER_MINIMAL();
)