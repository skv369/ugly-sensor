# Fixes that are made in the ugly-sensor.c code

## MUST comments
    1. <= is changed to < in the for loop to avoid out-of-bounds
    2. snprintf() is used instead of strcpy() to avoid stack buffer overflow
    3. default block included in the switch, and an additional break statement is added
    4. macros defined for all required variables to avoid magic numbers
    5. regs were freed using deinit-sensor()
    6. datatypes of t and lim were matched (unsigned is removed) to perform comparison operation
    7. x * x is changed to (x) * (x) in the SQR(x) macro
    8. return value of multiple functions is checked

## SHOULD comments
    1. CamelCase variables were all changed to snake-case
    2. char name was modified to const char name to avoid string modification
    3. braces were added around all the if blocks to improve readability
    4. the functions were mentioned as static as they are a part of this file only

## NIT comments
    1. variable unused is removed
    2. t++ is removed because it need not be incremented as it is inside an if block    
