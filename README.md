# Roman_calculator
This "Roman_calculator" takes in two Roman number strings and performs its addition and subtraction The output is also Roman strings.

### How to compile the codebase?
1. Set the present working directory to: path-to/Roman-calculator/roman-calculator/
2. Execute the command "make check". This command compiles the codebase and executes all the testcases that is present in ./tests/check_calculate.c.
3. Once the command finishes execution, you will see a Testsuite summary coloured in green. This means all the test cases have passed. The executable is generated and resides in ./src/.
4. Please navigate to ./src/ by executing the command "cd ./src"
5. You can now test the application by executing "./main roman-string-1 roman-string-2"

### Brief logic of addition and subtraction algorithms:
1. The calculate_sum() and calculate_diff() functions first check if the passed strings are Roman strings consisting of only 'M', 'D', 'C', 'L', 'X', 'V', and 'I' characters.
2. If so, execution proceeds and the values of the two strings are found using the find_value_of_string() function.
3. This function also checks if the passed strings are valid Roman strings. For eg: MLC is an invalid Roman string because L cannot be a subtractible occuring before C.
4. Once the values are found, they are added and subtracted in the two functions.
5. The integer sum and difference values are then converted back to Roman strings by convert_to_roman_string() function and sent to the calling application.
6. The return value of the function calls also contain necessary information. For more details, please refer to the header file : path-to/Roman-calculator/roman-calculator/src/calculate.h

### Note:

The library archive file libcalculate.la can be found in path-to/Roman-calculator/roman-calculator/src/ directory after compiling the codebase.


## Have fun calculating the old way and hey! don't forget to be a Roman in Rome! ;)
