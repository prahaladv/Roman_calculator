#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "calculate.h"

void print_error_and_exit(int err)
{
    if(err == FAILURE)
    {
        printf("The calculation failed. Please retry.\n");
    }
    else if(err == OUT_OF_BOUNDS)
    {
        printf("The calculation failed due to out of bounds output. Please retry.\n");
    }
    else if(err == INVALID_INPUT)
    {
        printf("The calculation failed due to invalid inputs. Please retry.\n");
    }
    else if(err == INVALID_NUM_1)
    {
        printf("The calculation failed due to invalid input 1. Please retry.\n");
    }
    else if(err == INVALID_NUM_2)
    {
        printf("The calculation failed due to invalid input 2. Please retry.\n");
    }
    _exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    int iRetVal = SUCCESS;

    if(argc != 3)
    {
        printf("Incorrect number of arguments.\nFormat: ./main <Roman_string_1> <Romand_string_2>\nPlease retry.\n");
        return 1;
    }

    char acSum[MAX_LEN] = {0};
    char acDiff[MAX_LEN] = {0};

    iRetVal = calculate_sum(argv[1], argv[2], (char *) &acSum);

    if(iRetVal != SUCCESS)
    {
        print_error_and_exit(iRetVal);
    }

    if(iRetVal == SUCCESS)
    {
        strcmp(acSum, "") ? printf("The sum is: %s\n\n", acSum) :
            printf("The sum is: -\n");
    }

    iRetVal = calculate_diff(argv[1], argv[2], (char *) &acDiff);
    if(iRetVal != SUCCESS && iRetVal != NEGATIVE_DIFFERENCE)
    {
        print_error_and_exit(iRetVal);
    }

    if(iRetVal == SUCCESS)
    {
        strcmp(acDiff, "") ? printf("The difference is: %s\n\n", acDiff) :
            printf("The difference is: -\n");
    }
    else if(iRetVal == NEGATIVE_DIFFERENCE)
    {
        printf("The difference is: Negative %s\n\n", acDiff);
    }

    return SUCCESS;
}
