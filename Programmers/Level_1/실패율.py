'''
https://programmers.co.kr/learn/courses/30/lessons/42889

특정 단계를 지나쳐 가거나 진행중인 단계의 개수를 카운팅
현재 진행 중인 stages의 원소별로 개수를 센 후
비율을 계산 
'''

from collections import Counter

def solution(N, stages):
    ratio = [[i, 0] for i in range(1, N+1)]
    arr = [0] * (N+1)
    counter = Counter(stages)
    answer = []
    
    for stage in stages:
        for i in range(stage):
            arr[i] += 1
            
    for key, value in counter.items():
        if key <= N:
            ratio[key-1] = (key, value / arr[key-1])
    
    ratio.sort(key=lambda x: -x[1])
    
    for r in ratio:
        answer.append(r[0])
        
    return answer

print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))