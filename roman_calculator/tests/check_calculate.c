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

/* Test 5 */
START_TEST(test_check_if_roman_string_fails_if_passed_random_string)
{
    int iRetVal = SUCCESS;

    /* Should take in one input string and return appropriate output */
    iRetVal = check_if_roman_string("MCXIA");

    ck_assert_int_eq(iRetVal, FAILURE);
}
END_TEST

/* Test 6 */
START_TEST(test_value_of_string_fails_if_passed_null)
{
    int iRetVal = SUCCESS;
    int iValue = 0;

    /* Should take in one input string and pointer to an int variable
     * and return appropriate output */
    iRetVal = find_value_of_string(NULL, &iValue);

    ck_assert_int_eq(iRetVal, INVALID_INPUT);
    ck_assert_int_eq(iValue, -1);
}
END_TEST

/* Test 7 */
START_TEST(test_value_of_string_fails_if_passed_empty_string)
{
    int iRetVal = SUCCESS;
    int iValue = 0;

    /* Should take in one input string and pointer to an int variable
     * and return appropriate output */
    iRetVal = find_value_of_string("", &iValue);

    ck_assert_int_eq(iRetVal, INVALID_INPUT);
    ck_assert_int_eq(iValue, -1);

}
END_TEST

/* Test 8 */
START_TEST(test_value_of_string_fails_if_passed_null_int_pointer)
{
    int iRetVal = SUCCESS;

    /* Should take in one input string and pointer to an int variable
     * and return appropriate output */
    iRetVal = find_value_of_string("IV", NULL);

    ck_assert_int_eq(iRetVal, INVALID_INPUT);
}
END_TEST

/* Test 9 */
START_TEST(test_value_of_string_on_passing_a_valid_string_without_subtractibles)
{
    int iRetVal = SUCCESS;
    int iValue = 0;

    /* Should take in one input string and pointer to an int variable
     * and return appropriate output */
    iRetVal = find_value_of_string("MDCLXVI", &iValue);

    ck_assert_int_eq(iRetVal, SUCCESS);
    ck_assert_int_eq(iValue, 1666);
}
END_TEST

/* Test 10 */
START_TEST(test_value_of_string_on_passing_a_valid_string_with_subtractibles)
{
    int iRetVal = SUCCESS;
    int iValue = 0;

    /* Should take in one input string and pointer to an int variable
     * and return appropriate output */
    iRetVal = find_value_of_string("MDCXLIV", &iValue);

    ck_assert_int_eq(iRetVal, SUCCESS);
    ck_assert_int_eq(iValue, 1644);
}
END_TEST

/* Test 11 */
/*
START_TEST(test_find_occurances_and_subtract_on_passing_a_valid_string_with_IX)
{
    int iRetVal = SUCCESS;

    // Since MDCIV is passed from find_value_of_string. This function would
    // have passed a simple summation of Roman characters.
    int iValue = 1606;

    // Should take in one input string and pointer to an int variable
    // and return appropriate output.
    iRetVal = find_occurances_and_subtract("MDCIV", &iValue);

    ck_assert_int_eq(iRetVal, SUCCESS);
    ck_assert_int_eq(iValue, 1604);
}
END_TEST
*/

/* Test 12 */
START_TEST(test_find_occurances_and_subtract_on_passing_a_valid_string)
{
    int iRetVal = SUCCESS;

    /* Since MDCIV is passed from find_value_of_string. This function would
     * have passed a simple summation of Roman characters. */
    int iValue = 1666;

    /* Should take in one input string and pointer to an int variable
     * and return appropriate output */
    iRetVal = find_occurances_and_subtract("MDCXLIV", "XL", &iValue);

    ck_assert_int_eq(iValue, 1646);

    iRetVal = find_occurances_and_subtract("MDCXLIV", "IV", &iValue);

    ck_assert_int_eq(iRetVal, SUCCESS);
    ck_assert_int_eq(iValue, 1644);
}
END_TEST

/* Test 13 */
START_TEST(test_convert_to_roman_string_for_invalid_and_out_of_bounds_input)
{
    int iRetVal = SUCCESS;
    char acNum[MAX_LEN] = {0};

    iRetVal = convert_to_roman_string(NULL, acNum);
    ck_assert_int_eq(iRetVal, INVALID_INPUT);

    iRetVal = convert_to_roman_string(-10, acNum);
    ck_assert_int_eq(iRetVal, OUT_OF_BOUNDS);

    iRetVal = convert_to_roman_string(10000, acNum);
    ck_assert_int_eq(iRetVal, OUT_OF_BOUNDS);
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

    //tcase_add_test(tc_core, test_check_if_roman_string_fails_if_passed_null);
    //tcase_add_test(tc_core, test_check_if_roman_string_fails_if_passed_random_string);

    //tcase_add_test(tc_core, test_value_of_string_fails_if_passed_null);
    //tcase_add_test(tc_core, test_value_of_string_fails_if_passed_empty_string);
    //tcase_add_test(tc_core, test_value_of_string_fails_if_passed_null_int_pointer);

    //tcase_add_test(tc_core, test_value_of_string_on_passing_a_valid_string_without_subtractibles);
    //tcase_add_test(tc_core, test_value_of_string_on_passing_a_valid_string_with_subtractibles);

    //tcase_add_test(tc_core, test_find_occurances_and_subtract_on_passing_a_valid_string_with_IX);
    //tcase_add_test(tc_core, test_find_occurances_and_subtract_on_passing_a_valid_string);

    tcase_add_test(tc_core, test_convert_to_roman_string_for_invalid_and_out_of_bounds_input);

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
