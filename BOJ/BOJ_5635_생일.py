'''
https://www.acmicpc.net/problem/5635

문자열 파싱 
'''

n = int(input())
info = [list(input().split()) for _ in range(n)]
mani_info = []

for name, day, month, year in info:
    mani_info += [[int(year), int(month), int(day), name]]

mani_info.sort()

print(mani_info[-1][3])
print(mani_info[0][3])