'''
https://www.acmicpc.net/problem/1302

카운팅 소트 문제 
'''

from collections import defaultdict

N = int(input())
d = defaultdict(int)
answer = []

for _ in range(N):
    d[input()] += 1

MAX = max(d.values())

for key in d.keys():
    if d[key] == MAX:
        answer += [key]

print(sorted(answer)[0])
