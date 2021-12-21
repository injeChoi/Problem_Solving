'''
https://programmers.co.kr/learn/courses/30/lessons/12980

DP로 풀어야 하나 싶었지만 
문제대로 목적지에서 출발지가 아닌,
목적지에서 출발지로 돌아가는 방식으로 역으로 문제를 푸는게 핵심이다

목적지에서 출발지로 가는데 순간이동(나누기 2)했을 때 값이 홀수가 나오면 한 칸 점프하면 된다(짝수로 만둘기).
짝수로 만들어서 계속 순간이동만 하면 배터리를 안 쓸 수 있다. 
'''

def solution(n):
    ans = 0
    
    while n > 0:
        if n % 2 != 0:
            ans += 1
        n //= 2

    return ans
