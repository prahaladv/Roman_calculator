#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"

#define M_VAL 1000
#define D_VAL 500
#define C_VAL 100
#define L_VAL 50
#define X_VAL 10
#define V_VAL 5
#define I_VAL 1

char * subtractibles[6] = {"IV", "IX", "XL", "XC", "CD", "CM"};

int check_if_roman_string(char * pcStr)
{
    int iRetVal = SUCCESS;

    /* TEST 4 */
    /* If the passed inputs are invalid */
    if(pcStr == NULL || !strcmp(pcStr, ""))
    {
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    /* TEST 5 */
    int i = 0, iLen = strlen(pcStr);

    /* If the string contains more than 4 Ms, exit */
    if(strstr(pcStr, "MMMMM") != NULL)
    {
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    /* Iterate through the string and check if the character is non-Roman. If
     * yes, exit saying it's invalid */
    for(i = 0; i < iLen; i++)
    {
        if(pcStr[i] != 'I' && pcStr[i] != 'V' && pcStr[i] != 'X' && pcStr[i] != 'L' &&
                pcStr[i] != 'C' && pcStr[i] != 'D' && pcStr[i] != 'M')
        {
            iRetVal = FAILURE;
            return iRetVal;
        }
    }
    return iRetVal;
}

int find_occurances_and_subtract(char * s, char * subtractible, int * sum)
{
    int iRetVal = SUCCESS;

    /* If the input is invalid */
    if(s == NULL || !strcmp(s, "") || subtractible == NULL ||
            !strcmp(subtractible, "") || sum == NULL)
    {
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    int iLen = strlen(s), sub = 0;
    char acStr[iLen + 1], * pcPtr = acStr;

    /* TEST 11 */
    strcpy(acStr, s);

    /* Decide the subtractible value based on what is passed */
    if( (strcmp(subtractible, "IV") == 0) || (strcmp(subtractible, "IX") == 0) )
        sub = 2;
    else if( (strcmp(subtractible, "XL") == 0) || (strcmp(subtractible, "XC") == 0) )
        sub = 20;
    else if( (strcmp(subtractible, "CD") == 0) || (strcmp(subtractible, "CM") == 0) )
        sub = 200;

    /* TEST 12 */
    /* Repeated check for the presence of the subtractible until NULL or ""
     * is encountered */
    while(pcPtr != NULL)
    {
        if(!strcmp(pcPtr, ""))
            return iRetVal;

        pcPtr = strstr(pcPtr, subtractible);

        if(pcPtr != NULL)
        {
            pcPtr += 2; //Skip the two subtractible characters as well
            *sum = (*sum) - sub;
        }
    }
    return iRetVal;
}

int find_value_of_string(char * acNum, int * piVal)
{
    int iRetVal = SUCCESS;
    char acVerifier[MAX_LEN] = {0};

    /* TEST 6, 7 and 8 */
    /* In case of invalid inputs */
    if(acNum == NULL || !strcmp(acNum, "") || piVal == NULL)
    {
        if(piVal != NULL)
            *piVal = -1;
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    /* TEST 9 */
    int i = 0, iLen = strlen(acNum), iRes = 0;

    /* Iterate through the string and just add the respective values */
    for(i = 0; i < iLen; i++)
    {
        if(acNum[i] == 'M')
            iRes += M_VAL;
        else if(acNum[i] == 'D')
            iRes += D_VAL;
        else if(acNum[i] == 'C')
            iRes += C_VAL;
        else if(acNum[i] == 'L')
            iRes += L_VAL;
        else if(acNum[i] == 'X')
            iRes += X_VAL;
        else if(acNum[i] == 'V')
            iRes += V_VAL;
        else if(acNum[i] == 'I')
            iRes += I_VAL;
        else
        {
            * piVal = -1;
            iRetVal = INVALID_INPUT;
            return iRetVal;
        }
    }

    /* The only possible "subtract"ibles are IV, IX, XL, XC, CD and CM. So the
     * approach is to add all the values regardless of whether it is a
     * subtractibles or not. Then find occurance of those subtractibles and
     * subtract twice of what should have been subtracted. Example: IX is 9
     * but when simply added gives 11. So subtract 2. For CD, subtract 200.
     * Similarly if it is XC, simple summing would have yeilded 110 but it is
     * 90. */

    /* TEST 10 */
    for(i = 0; i < 6; i++)
    {
        iRetVal = find_occurances_and_subtract(acNum, subtractibles[i], &iRes);
        if(iRetVal != SUCCESS)
        {
            *piVal = -1;
            return iRetVal;
        }
    }

    /* To check if the passed string is actually a valid one or not.
     * We find the value and convert it back to Roman string for verification.
     * If the passed string is valid, it would be the same as
      that we obtained by converting the value to Roman string. */

    /* TEST 15 */
    iRetVal = convert_to_roman_string(iRes, acVerifier);
    if(iRetVal != SUCCESS)
    {
        *piVal = -1;
        return iRetVal;
    }

    if(strcmp(acVerifier, acNum) == 0)
    {
        * piVal = iRes;
    }
    else
    {
        * piVal = -1;
        iRetVal = INVALID_INPUT;
    }

    return iRetVal;
}

int convert_to_roman_string(int iNum, char * pcNum)
{
    int iRetVal = SUCCESS;

    /* TEST 13 */
    /* If no destination pointer is sent */
    if(pcNum == NULL)
    {
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    /* If the passed number is out of bounds */
    if(iNum < 0 || iNum > MAX_VAL)
    {
        iRetVal = OUT_OF_BOUNDS;
        return iRetVal;
    }

    /* TEST 14 */
    int num = iNum, thou = 0, hund = 0, ten = 0, one = 0;
    /* Used to compute the Roman equivalent of each digit as per their place
     * value */
    char * thousandth[5] = {"", "M", "MM", "MMM", "MMMM"};
    char * hundredth[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char * tenth[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char * ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    /* thou, hund, ten, and one contain the digit values in the number */
    thou = num / 1000;
    if(thou > 4)
    {
        iRetVal = OUT_OF_BOUNDS;
        return iRetVal;
    }

    num -= (thou * 1000);
    hund = num / 100;
    num -= (hund * 100);
    ten = num / 10;
    num -= (ten * 10);
    one = num % 10;

    /* Indexing various arrays and fetching the Roman equivalent string based
     * on the digit values we obtained from the number */
    strcat(pcNum, thousandth[thou]);
    strcat(pcNum, hundredth[hund]);
    strcat(pcNum, tenth[ten]);
    strcat(pcNum, ones[one]);

    return iRetVal;
}

int calculate_sum(char * pcNum1, char * pcNum2, char * pcSum)
{
    /* TEST 1 */
    int iLen1 = strlen(pcNum1), iLen2 = strlen(pcNum2);
    char acNum1[iLen1 + 1];
    char acNum2[iLen2 + 1];
    strcpy(acNum1, pcNum1);
    strcpy(acNum2, pcNum2);
    int iNum1 = 0, iNum2 = 0, iSum = 0, iRetVal = SUCCESS;

    /* To check if the input string 1 contains only roman characters */
    iRetVal = check_if_roman_string(acNum1);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_1;
        return iRetVal;
    }
    /* To check if the input string 2 contains only roman characters */
    iRetVal = check_if_roman_string(acNum2);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_2;
        return iRetVal;
    }

    /* To fetch Roman string 1's value */
    iRetVal = find_value_of_string(acNum1, &iNum1);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_1;
        return iRetVal;
    }
    /* To fetch Roman string 2's value */
    iRetVal = find_value_of_string(acNum2, &iNum2);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_2;
        return iRetVal;
    }

    printf("\nNumber 1 : %d, Number 2: %d\n", iNum1, iNum2);

    iSum = iNum1 + iNum2;

    printf("\nSum : %d\n", iSum);

    /* The number is converted back to a Roman string */
    iRetVal = convert_to_roman_string(iSum, pcSum);

    return iRetVal;
}

int calculate_diff(char * pcNum1, char * pcNum2, char * pcDiff)
{
    /* TEST 2 */
    int iLen1 = strlen(pcNum1), iLen2 = strlen(pcNum2);
    char acNum1[iLen1 + 1];
    char acNum2[iLen2 + 1];
    strcpy(acNum1, pcNum1);
    strcpy(acNum2, pcNum2);
    int iNum1 = 0, iNum2 = 0, iDiff = 0, iRetVal = SUCCESS;

    /* To check if the input string 1 contains only roman characters */
    iRetVal = check_if_roman_string(acNum1);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_1;
        return iRetVal;
    }
    /* To check if the input string 2 contains only roman characters */
    iRetVal = check_if_roman_string(acNum2);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_2;
        return iRetVal;
    }

    /* To fetch Roman string 1's value */
    iRetVal = find_value_of_string(acNum1, &iNum1);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_1;
        return iRetVal;
    }
    /* To fetch Roman string 2's value */
    iRetVal = find_value_of_string(acNum2, &iNum2);
    if(iRetVal != SUCCESS)
    {
        iRetVal = INVALID_NUM_2;
        return iRetVal;
    }

    printf("\nNumber 1 : %d, Number 2: %d\n", iNum1, iNum2);

    /* TEST 2 and 3 */
    iDiff = abs(iNum1 - iNum2);

    printf("\nDifference: %d\n", iDiff);

    /* The number is converted back to a Roman string */
    iRetVal = convert_to_roman_string(iDiff, pcDiff);
    if(iRetVal != SUCCESS)
    {
        return iRetVal;
    }

    /* If the first value is smaller than the second, the return value is
     * NEGATIVE_DIFFERENCE */

    /* TEST 3 */
    if(iNum1 < iNum2)
    {
        iRetVal = NEGATIVE_DIFFERENCE;
    }

    return iRetVal;
}
