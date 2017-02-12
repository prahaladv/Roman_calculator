#ifndef CALCULATE_H
#define CALCULATE_H

/* After making test 1, these are the macros that could be useful */
#define SUCCESS 0
#define FAILURE 1
#define INVALID_NUM_1 2
#define INVALID_NUM_2 3
#define OUT_OF_BOUNDS 4
#define NEGATIVE_DIFFERENCE 5
#define INVALID_INPUT 6

#define MAX_LEN 40

int calculate_sum(char * pcNum1, char * pcNum2, char * pcSum);
int check_if_roman_string(char * pcStr);
/* Should be called only after "check_if_roman_string()" is called */
int find_value_of_string(char * acNum, int * piVal);
int convert_to_roman_string(int iNum, char * pcNum);
int calculate_diff(char * pcNum1, char * pcNum2, char * pcDiff);

#endif /* CALCULATE_H */
