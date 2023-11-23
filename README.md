# IEEE-754
32-bit hexadecimal representation of a floating-point number in IEEE 754 format and then prints a detailed description of the number, including its sign, exponent, and significand.

Let's break down the steps:

Input Reading:
The code reads hexadecimal values from the standard input (cin) until there's no more input.

Binary Representation:
It prints the given hexadecimal value in both hexadecimal and binary formats by extracting each bit using bitwise operations.

Interpretation of Components:
Extracts the sign, exponent, and significand from the 32-bit hexadecimal value according to IEEE 754 format.

Determines the sign bit by shifting the value 31 bits to the right.

Extracts the exponent bits from positions 23 to 30, calculates the exponent value by interpreting these bits as an integer, and subtracts 127 (the bias for single-precision).

Calculates the significand by summing the values represented by the last 23 bits (bits 0 to 22).

Printing the Interpretation:
Prints the sign, exponent (in both hexadecimal and decimal formats), and significand (in hexadecimal format).

    Based on the sign, exponent, and significand, it identifies and prints different cases:
        Infinity if the exponent is 128 and the significand is zero.
        Zero if the exponent is -127 and the significand is zero.
        Prints the normalized number for other cases, considering the binary representation of the significand:
            For denormalized numbers or numbers between 0 and 1, it prints the binary representation considering the exponent.
            For numbers larger than 1, it prints the integer part as 1 followed by the fractional part.
Formatting Output:
The code takes care of formatting the output to match the specified requirements.

It's a detailed and methodical breakdown of the IEEE 754 representation, using bitwise operations to extract and interpret the various components of a floating-point number.
