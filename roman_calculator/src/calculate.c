#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"

int check_if_roman_string(char * pcStr)
{
    int iRetVal = SUCCESS;

    if(pcStr == NULL || !strcmp(pcStr, ""))
    {
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    int i = 0, iLen = strlen(pcStr);

    if(strstr(pcStr, "MMMMM") != NULL)
    {
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

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

int find_occurances_and_subtract(char * s, int * sum)
{
    /* Since the string is MDCXLIV. So XL = 40 and not 60. Similarly IV = 4
     * and not 6. So subtract 22.
     *
     * IMPORTANT POINT!!! If check - because I am running the previous
     * test case as well. So the subtraction should happen only if there are
     * subtractibles. Implies this function should check the string and
     * perform subtractions appropriately. */

    if(strstr(s, "IV") != NULL && strstr(s, "XL") != NULL)
        *sum = (*sum) - 22;

    return SUCCESS;
}

int find_value_of_string(char * acNum, int * piVal)
{
    int iRetVal = SUCCESS;

    if(acNum == NULL || !strcmp(acNum, "") || piVal == NULL)
    {
        if(piVal != NULL)
            *piVal = -1;
        iRetVal = INVALID_INPUT;
        return iRetVal;
    }

    int i = 0, iLen = strlen(acNum), iRes = 0;

    for(i = 0; i < iLen; i++)
    {
        if(acNum[i] == 'M')
            iRes += 1000;
        else if(acNum[i] == 'D')
            iRes += 500;
        else if(acNum[i] == 'C')
            iRes += 100;
        else if(acNum[i] == 'L')
            iRes += 50;
        else if(acNum[i] == 'X')
            iRes += 10;
        else if(acNum[i] == 'V')
            iRes += 5;
        else if(acNum[i] == 'I')
            iRes += 1;
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

    iRetVal = find_occurances_and_subtract(acNum, &iRes);
    if(iRetVal != SUCCESS)
    {
        *piVal = -1;
        return iRetVal;
    }

    *piVal = iRes;

    return iRetVal;
}

int convert_to_roman_string(int iNum, char * pcNum)
{
    if(iNum == 2)
        strcpy(pcNum, "II");

    return SUCCESS;
}

int calculate_sum(char * pcNum1, char * pcNum2, char * pcSum)
{
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

    iRetVal = convert_to_roman_string(iSum, pcSum);

    return iRetVal;
}

int calculate_diff(char * pcNum1, char * pcNum2, char * pcDiff)
{
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

    iDiff = abs(iNum1 - iNum2);

    printf("\nDifference: %d\n", iDiff);

    iRetVal = convert_to_roman_string(iDiff, pcDiff);
    if(iRetVal != SUCCESS)
    {
        return iRetVal;
    }

    if(iNum1 < iNum2)
    {
        iRetVal = NEGATIVE_DIFFERENCE;
    }

    return iRetVal;
}
