'''
https://www.acmicpc.net/problem/15652

중복이 가능한 경우를 만드는 문제 
'''

N, M = map(int, input().split())

def dfs(idx, lst):
    if len(lst) == M:
        for item in lst:
            print(item, end=" ")
        print()
        return
    
    for i in range(1, N+1):
        if i >= idx:
            dfs(i, lst + [i])

dfs(1, [])