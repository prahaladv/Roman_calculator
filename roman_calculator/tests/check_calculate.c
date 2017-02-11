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

int main(void)
{
    return 0;
}
