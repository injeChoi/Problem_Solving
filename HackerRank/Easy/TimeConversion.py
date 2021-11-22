#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    flag = True if s[-2:] == 'AM' else False
    s = s[:-2]
    hour, minute, second = map(int, s.split(':'))
    
    if flag:
        if hour == 12:
            hour = 0
        return f'{hour:02d}:{minute:02d}:{second:02d}'
    else:
        if hour != 12:
            hour += 12
        return f'{hour:02d}:{minute:02d}:{second:02d}'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
