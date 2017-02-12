#include <stdlib.h>
#include <check.h>
#include "../src/calculate.h"

/* Test 1 */
START_TEST(test_calculate_sum)
{
    int iRetVal = FAILURE;
    char * pcInput1 = "I";
    char * pcInput2 = "I";

    /* Assuming the max length of a Roman string will be MAX_LEN = 40 */
    char acSum[MAX_LEN] = {0};

    /* Should take in two input strings and return output in acSum - a valid buffer */
    iRetVal = calculate_sum(pcInput1, pcInput2, acSum);

    ck_assert_int_eq(iRetVal, SUCCESS);
    ck_assert_str_eq(acSum, "II");
}
END_TEST

/* Test 2 */
START_TEST(test_calculate_diff)
{
    int iRetVal = FAILURE;
    char * pcInput1 = "III";
    char * pcInput2 = "I";

    /* Assuming the max length of a Roman string will be MAX_LEN = 40 */
    char acDiff[MAX_LEN] = {0};

    /* Should take in two input strings and return output in acSum - a valid buffer */
    iRetVal = calculate_diff(pcInput1, pcInput2, acDiff);

    ck_assert_int_eq(iRetVal, SUCCESS);
    ck_assert_str_eq(acDiff, "II");
}
END_TEST

/* Test 3 */
START_TEST(test_calculate_negative_diff)
{
    int iRetVal = FAILURE;
    char * pcInput1 = "I";
    char * pcInput2 = "III";

    /* Assuming the max length of a Roman string will be MAX_LEN = 40 */
    char acDiff[MAX_LEN] = {0};

    /* Should take in two input strings and return output in acSum - a valid buffer */
    iRetVal = calculate_diff(pcInput1, pcInput2, acDiff);

    ck_assert_int_eq(iRetVal, NEGATIVE_DIFFERENCE);
    ck_assert_str_eq(acDiff, "II");
}
END_TEST

/* Test 4 */
START_TEST(test_check_if_roman_string_fails_if_passed_null)
{
    int iRetVal = FAILURE;

    /* Should take in one input string and return appropriate output */
    iRetVal = check_if_roman_string(NULL);

    ck_assert_int_eq(iRetVal, INVALID_INPUT);
}
END_TEST

Suite * calculate_suite(void)
{
    Suite * s;
    TCase * tc_core;
    s = suite_create("Calculate");
    /* Core test case */
    tc_core = tcase_create("Core");

    //tcase_add_test(tc_core, test_calculate_diff);
    //tcase_add_test(tc_core, test_calculate_negative_diff);

    tcase_add_test(tc_core, test_check_if_roman_string_fails_if_passed_null);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = calculate_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
