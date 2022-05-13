'''
https://www.acmicpc.net/problem/2607

기준이 되는 문자열(A)과 다른 문자열(B)을 하나씩 비교
B의 문자가 A에 포함됐다면 A와 B에서 그 문자를 소거하고 아니라면 유지

소거 완료 후 남은 문자열들의 차가 1이라면 답
'''

from collections import deque

T = int(input())
target = list(input())
words = [deque(input()) for _ in range(T-1)]
answer = 0

for word in words:
    tmp = target[:]
    
    for _ in range(len(word)):
        element = word.popleft()
        if element in tmp:
            tmp.remove(element)
        else:
            word.append(element)
    
    
    if len(tmp) in [0, 1] and len(word) in [0, 1] and abs(len(tmp) - len(word)) < 2:
        answer += 1
        
print(answer)
        