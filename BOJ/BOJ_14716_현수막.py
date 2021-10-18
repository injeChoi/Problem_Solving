import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]
answer = 0

def dfs(y, x):
    visited[y][x] = 1
    for i in range(8):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] == 1 and not(visited[ny][nx]):
            dfs(ny, nx)

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1 and not(visited[i][j]):
            answer += 1
            dfs(i, j)

print(answer)