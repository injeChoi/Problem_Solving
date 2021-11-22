#!/bin/python3

import math
import os
import random
import re
import sys
from bisect import bisect_right

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

'''
ranked 리스트를 중복 제거해서 오름차순으로 정렬한다
player[i] 보다 큰 ranked 요소 값의 index를 찾는다 -> bisect_right
len(ranked) - index + 1 을 하면 player[i]의 순위가 나온다.

player는 오름차순 정렬 돼있으므로 player[i]의 순위는 player[i+1]의 순위에 영향을 주지 않는다.
높은 순위는 낮은 순위가 얼만큼 늘어나는지 상관 안 해도 되는게 포인트다.

ex) 1, 2, 3, 4, 5 순위가 있을 때 5 순위는 6~100순위가 얼마나 늘어나든지 상관없다. 자기는 무조건 5위니까.
반면 하위권은 자기보다 높은 순위가 생기면 영향을 받는다.
6, 7, 8순위가 있는데 3순위가 새로 등장하면 6, 7, 8 -> 7, 8, 9 순위가 된다. 
'''

def climbingLeaderboard(ranked, player):
    s = sorted(set(ranked))
    answer = []
    
    for score in player:
        idx = len(s) - bisect_right(s, score) + 1
        answer.append(idx)
        
    return answer

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
