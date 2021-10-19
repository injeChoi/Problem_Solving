import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
graph = [input() for _ in range(N)]
visited = [[0] * M for _ in range(N)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
cnt = 0

def dfs(y, x, c):
    visited[y][x] = 1
    if c == '|':
        for i in range(2):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] == c and not(visited[ny][nx]):
                dfs(ny, nx, c)
    elif c == '-':
        for i in range(2, 4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] == c and not(visited[ny][nx]):
                dfs(ny, nx, c)

for i in range(N):
    for j in range(M):
        if not(visited[i][j]):
            cnt += 1
            dfs(i, j, graph[i][j])

print(cnt)