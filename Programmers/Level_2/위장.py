'''
https://programmers.co.kr/learn/courses/30/lessons/42578

Hash보단 경우의 수 문제(?)
특정 종류의 옷을 안 입는 경우 때문에 특정 종류 옷의 개수 + 1
모든 종류의 옷 개수를 곱하면 옷을 입는 모든 경우의 수가 나온다.
옷을 안 입는 경우는 없으니 최종 값에서 -1
고로, (item1 + 1) * (item2 + 1) * ... * (itemN + 1) - 1
'''

from collections import defaultdict

def solution(clothes):
    answer = 1
    d = defaultdict(int)

    for name, item in clothes:
        d[item] += 1

    for item in d.values():
        answer *= item + 1

    return answer - 1
