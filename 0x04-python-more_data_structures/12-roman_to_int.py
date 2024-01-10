#!/usr/bin/python3
def roman_to_int(roman_string):
    roman_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    if not isinstance(roman_string, str):
        return 0
    result = 0
    for i in range(1, len(roman_string)):
        if roman_dict[roman_string[i]] <= roman_dict[roman_string[i-1]]:
            result += roman_dict[roman_string[i-1]]
        else:
            result -= 2 * roman_dict[roman_string[i-1]]
            result += roman_dict[roman_string[i]]
    result += roman_dict[roman_string[-1]]
    return result
