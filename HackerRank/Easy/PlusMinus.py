#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    positive = negative = zero = 0
    total = len(arr)
    
    for item in arr:
        if item > 0:
            positive += 1
        elif item < 0:
            negative += 1
        else:
            zero += 1
    
    print("{:.6f}".format(positive / total))
    print("{:.6f}".format(negative / total))
    print("{:.6f}".format(zero / total))

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
