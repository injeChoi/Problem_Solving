'''
https://www.acmicpc.net/problem/15651

'''

N, M = map(int, input().split())

def dfs(lst):
    if len(lst) == M:
        for item in lst:
            print(item, end=" ")
        print()
        return
    
    for i in range(1, N+1):
        dfs(lst + [i])
        
dfs([])