'''
https://programmers.co.kr/learn/courses/30/lessons/67258

전형적인 투포인터 문제

시작점을 s, 끝점을 e라고 하고
s와 e 사이 범위 안의 보석들을 종류별로 카운팅
s~e의 보석 종류 개수가 총 보석 종류 개수와 같으면
정답 후보로 추가하고 s를 1 증가, 그리고 gems[s]를 1 감소 (gems[s]가 0이면 아예 삭제)
같지 않으면 e를 1 증가하면서 gems[e]를 dictionary에 추가
이때, e가 length의 범위를 초과해선 안 된다
'''

from collections import defaultdict

def solution(gems):
    answer = [[len(gems), 1, len(gems)]]
    gemCount, s, e = 0, 0, 0
    length = len(gems)
    d = defaultdict(int)    
    gemCount = len(set(gems))

    def checkDict():
        if len(d) == gemCount:
            answer.append([sum(d.values()), s + 1, e])
            return True
        return False
    
    def decreaseDict(gem):
        d[gem] -= 1
        if d[gem] <= 0:
            del d[gem]

    while s < length or e < length:
        if checkDict():
            decreaseDict(gems[s])
            s += 1
        else:
            if e < length:
                d[gems[e]] += 1
                e += 1
            else:
                s += 1
    
    answer.sort()
    return [answer[0][1], answer[0][2]]

print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))