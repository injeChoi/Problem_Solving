import sys
sys.setrecursionlimit(10**6)

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[0] * N for _ in range(N)]

def dfs(y, x):
    visited[y][x] = 1
    if graph[y][x] == -1:
        return
    ny, nx = y + graph[y][x], x + graph[y][x]
    if 0 <= ny < N and not(visited[ny][x]):
        dfs(ny, x)
    if 0 <= nx < N and not(visited[y][nx]):
        dfs(y, nx)

dfs(0, 0)
if visited[N-1][N-1]:
    print("HaruHaru")
else:
    print("Hing")