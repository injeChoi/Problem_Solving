'''
https://www.acmicpc.net/problem/1937

DFS만으로 풀면 시간초과, 고로 DP 섞어서 풀어야한다
DP를 통해 한 번 계산했던 자리는 다시 계산하지 않도록 한다
만약 진행하려는 자리가 이미 계산했던 자리면 그 자리의 값 + 1의 값을 현재 자리에 저장한다
이때, 현재 자리에 저장돼있는 값 보다 클 경우에만 최신화를 한다
'''

import sys
sys.setrecursionlimit(10000)

def solution():
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    N = int(input())
    graph = [list(map(int, input().split())) for _ in range(N)]
    DP = [[-1] * N for _ in range(N)]
    answer = 0
    
    def check_route(y, x, ny, nx):
        if 0 <= ny < N and 0 <= nx < N and graph[y][x] < graph[ny][nx]:
            return True
        return False
    
    
    def dfs(y, x):
        if DP[y][x] != -1:
            return DP[y][x]
        
        DP[y][x] = 1
                 
        for d in range(4):
            ny, nx = y + dy[d], x + dx[d]
            if check_route(y, x, ny, nx):
                DP[y][x] = max(DP[y][x], dfs(ny, nx) + 1)
                
        return DP[y][x]
        
        
    for i in range(N):
        for j in range(N):
            answer = max(answer, dfs(i, j))
            
    for d in DP:
        print(d)

    print(answer)
    
solution()