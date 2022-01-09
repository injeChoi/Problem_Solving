'''
https://programmers.co.kr/learn/courses/30/lessons/12985

토너먼트 원리가 중요한 문제
한 라운드가 끝날 때 마다 참가자는 반 씩 줄어든다.
즉, a와 b의 index 번호가 절반으로 줄어든다.
계속 절반으로 줄어들다가 a와 b의 index 번호 차이가 1 차이가 나면 
둘이 맞붙는 상황이 된 것이다. 
'''


def solution(n, a, b):
    answer =  1
    
    while True:
        if (a % 2 == 0 and a - 1 == b) or (a % 2 != 0 and a + 1 == b):
            return answer

        a, b = (a + 1) // 2, (b + 1) // 2
        answer += 1