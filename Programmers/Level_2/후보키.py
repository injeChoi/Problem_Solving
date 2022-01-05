'''
https://programmers.co.kr/learn/courses/30/lessons/42890

1. 만들어질 수 있는 모든 조합 구성 -> candidates
2. candi를 기반으로 실제 조합 구성
3. 조합의 개수가 object 개수와 동일하면 유일성 통과
4. 유일한 녀석 중 최소성을 만족하는지 체크
'''

from itertools import combinations

def solution(relation):
    row = len(relation)
    col = len(relation[0])

    candidates = []
    for i in range(1, col + 1):
        candidates.extend(combinations(range(col), i))

    unique = []
    for candi in candidates:
        tmp = [tuple(item[i] for i in candi) for item in relation]
        if len(set(tmp)) == row:
            unique.append(candi)

    answer = set(unique)
    for i in range(len(unique)):
        for j in range(i + 1, len(unique)):
            if len(unique[i]) == len(set(unique[i]) & set(unique[j])):
                answer.discard(unique[j])

    return len(answer) 
