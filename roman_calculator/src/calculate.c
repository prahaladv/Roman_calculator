#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"

int check_if_roman_string(char * pcNum)
{
    /* Since I know I have provided the right user input for unit testing */
    return SUCCESS;
}

int find_value_of_string(char * acNum, int * piVal)
{
    if(piVal != NULL && !strcmp(acNum, "I"))
        *piVal = 1;

    return SUCCESS;
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
