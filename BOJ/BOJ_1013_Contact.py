'''
https://www.acmicpc.net/problem/1013

정규 표현식 문제
그냥 match 메소드를 사용하면
입력 값의 일부분 중 match 되는 것이 있으면 매칭됐다는 값을 리턴받는다
하지만 문제 명세에 따르면 입력 값 전체가 특정 패턴에 match 되는지를 판별해야 하기 때문에
match 메소드 대신 fullmatch 메소드를 사용해야 한다 
'''

import re

T = int(input())

def solution():
    fm = re.fullmatch('(100+1+|01)+', input())
    print("YES") if fm else print("NO")

for _ in range(T):
    solution()