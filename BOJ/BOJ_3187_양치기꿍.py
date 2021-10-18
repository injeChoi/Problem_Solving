import sys
sys.setrecursionlimit(10**6)

R, C = map(int, input().split())
graph = [input() for _ in range(R)]
visited = [[0] * C for _ in range(R)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
sheep = wolf = s = w = 0

def dfs(y, x):
    global s, w
    if graph[y][x] == 'k':
        s += 1
    elif graph[y][x] == 'v':
        w += 1
    visited[y][x] = 1

    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < R and 0 <= nx < C and graph[ny][nx] != '#' and not(visited[ny][nx]):
            visited[ny][nx] = 1
            dfs(ny, nx)

for i in range(R):
    for j in range(C):
        if graph[i][j] != '#' and not(visited[i][j]):
            s = w = 0
            dfs(i, j)
            if s > w:
                sheep += s
            else:
                wolf += w

print(sheep, wolf)