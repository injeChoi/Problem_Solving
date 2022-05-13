'''
https://www.acmicpc.net/problem/2671

정규 표현식을 문제에서 명시해줌
입력으로 주어진 문자열 전체가 정규 표현식 패턴에 부합하면 출력 
'''

import re

S = input()

if re.fullmatch('(100+1+|01)+', S):
    print("SUBMARINE")
else:
    print("NOISE")