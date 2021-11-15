import math
import os
import random
import re
import sys
from itertools import combinations

#
# Complete the 'alternate' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternate(s):
    # Write your code here
    answer = []
    if len(s) == 1:
        return 0

    u = set(s)
    comb = set()
    for item in list(combinations(u, 2)):
        comb.add(item)

    for item in comb:
        ts = ''.join(x for x in s if x in item)

        for i in range(len(ts)-1):
            if ts[i] == ts[i+1]:
                break
        else:
            answer.append(len(ts))
        
    answer.sort(reverse=True)
    if answer:
        return answer[0]
    else:
        return 0

if __name__ == '__main__':
    s = input()
    result = alternate(s)
    print(result)
