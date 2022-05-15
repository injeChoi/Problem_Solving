'''
https://www.acmicpc.net/problem/15649

기본적인 순열 찾기 문제 
'''

N, M = map(int, input().split())
visited = [0] * (N + 1)

def dfs(lst):
    if len(lst) == M:
        for item in lst:
            print(item, end=" ")
        print()
        return
    
    for i in range(1, N+1):
        if not visited[i]:
            visited[i] = 1
            dfs(lst + [i])
            visited[i] = 0
    
dfs([])