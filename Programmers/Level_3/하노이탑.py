'''
https://programmers.co.kr/learn/courses/30/lessons/12946

1번, 2번, 3번 기둥의 역할이 수시로 변할 수 있음을 유의
1번이 시작일 수도, 보조일 수도, 목적지일 수도 있다
이 개념을 머리에 두고 재귀적으로 문제를 해결

'''

def solution(n):
    answer = []
    
    def hanoi(n, start, mid, end):
        if n == 1:
            answer.append([start, end])
            return
        
        hanoi(n-1, start, end, mid)
        answer.append([start, end])
        hanoi(n-1, mid, start, end)

    hanoi(n, 1, 2, 3)

    return answer

print(solution(3))