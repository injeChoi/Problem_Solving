'''
https://www.acmicpc.net/problem/15650

기본적인 조합 찾기 문제 
'''

N, M = map(int, input().split())

def dfs(idx, lst):
    if len(lst) == M:
        for item in lst:
            print(item, end=" ")
        print()
        return

    for i in range(idx, N + 1):
        dfs(i+1, lst + [i])
    
dfs(1, [])