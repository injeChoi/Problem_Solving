'''
https://www.acmicpc.net/problem/1520

DFS + DP
그냥 DFS로만 풀면 시간 초과

Bottom Up 방식으로 특정 경로를 통해 graph[N-1][N-1]에 도달할 수 있으면
해당 경로에 1씩 증가시킨다.

모든 도달 가능한 경로를 통해 DFS를 돌고 나면 graph[0][0]에서 출발해서 목적지까지 도달할 수 있는
경로의 개수가 visited[0][0]에 쌓이게 된다. 
'''

import sys
sys.setrecursionlimit(10**6)

def solution():
    N, M = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    visited = [[-1] * M for _ in range(N)]
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    
    def checker(y, x, ny, nx):
        if 0 <= ny < N and 0 <= nx < M and graph[y][x] > graph[ny][nx]:
            return 1
        return 0
    
    def dfs(y, x):        
        if y == N - 1 and x == M - 1:
            return 1
        
        if visited[y][x] != -1:
            return visited[y][x]
        
        visited[y][x] = 0
        
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            
            if checker(y, x, ny, nx):
                visited[y][x] += dfs(ny, nx)
                
        return visited[y][x]
            
    print(dfs(0, 0))
    for v in visited:
        print(v)
    
    
solution()