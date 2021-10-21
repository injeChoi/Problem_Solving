import sys
sys.setrecursionlimit(10**6)

N = int(input())
graph = [list(map(int, input())) for _ in range(N)]
visited = [[0] * N for _ in range(N)]
result = []
cnt = 0
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def dfs(y, x):
    result[cnt] += 1
    visited[y][x] = 1
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] and not(visited[ny][nx]):
            dfs(ny, nx)

for i in range(N):
    for j in range(N):
        if graph[i][j] and not(visited[i][j]):
            result.append(0)
            dfs(i, j)
            cnt += 1

result.sort()
print(len(result))
for item in result:
    print(item)