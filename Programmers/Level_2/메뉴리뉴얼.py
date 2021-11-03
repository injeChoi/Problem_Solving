from itertools import combinations
from collections import defaultdict

def solution(orders, course):
    answer = []
    d = defaultdict(int)
    length = []
    m = []
    for c in course:
        length.append(c)

    for string in orders:
        lst = list(string)
        lst.sort()
        for c in course:
            comb = list(combinations(lst, c))
            for item in comb:
                s = ''.join(item)
                d[s] += 1

    for l in length:
        MAX = 0
        for item in d:
            if len(item) == l:
                MAX = max(MAX, d[item])
        if MAX > 1:
            m.append(MAX)

    start = 0
    for idx in m:
        for item in d:
            if len(item) == length[start] and d[item] == idx:
                answer.append(item)
        start += 1

    answer.sort()
    return answer
