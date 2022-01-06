'''
https://programmers.co.kr/learn/courses/30/lessons/72412

combination 없이 단순 로직으로 직접 로직 만들어 풀다가 정확도에서 실패함
지원서에서 점수 빼고 모든 조합 구해서 각각을 해쉬의 키로 사용, 점수를 값으로 사용
문제 조건에서 지원서와 쿼리의 개수가 단순 O(mn)이어도 시간 초과가 나기 때문에
해쉬 값을 정렬 후 이분 탐색으로 특정 점수 이상의 개수만 구함 
'''


from collections import defaultdict
from itertools import combinations
from bisect import bisect_left

def solution(info, queries):
    answer = []
    d = defaultdict(list)

    for item in info:
        lst = item.split()
        
        for i in range(5):
            for comb in combinations(lst[:-1], i):
                tmp = ''.join(comb)
                d[tmp] += [int(lst[-1])]

    for key in d:
        d[key].sort()

    for query in queries:
        queryList = query.split()
        q = ''.join([queryList[x] for x in range(len(queryList)-1) if x % 2 == 0 and queryList[x] != '-'])
        score = int(queryList[-1])
        values = d[q]

        if len(values) != 0:
            left = bisect_left(values, score)
            answer.append(len(values) - left)
        else:
            answer.append(0)

    return answer
