import sys
sys.setrecursionlimit(10**6)

R, C = map(int, input().split())
graph = [input() for _ in range(R)]
visited = [[0] * C for _ in range(R)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
rw = rs = 0

def dfs(y, x):
    global wolf, sheep
    if not 0 <= y < R or not 0 <= x < C or visited[y][x] or graph[y][x] == '#':
        return

    visited[y][x] = True
    if graph[y][x] == 'v':
        wolf += 1
    elif graph[y][x] == 'o':
        sheep += 1
        
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        dfs(ny, nx)

for i in range(R):
    for j in range(C):
        if graph[i][j] != '#' and not visited[i][j]:
            wolf = sheep = 0
            dfs(i, j)
            if sheep > wolf: rs += sheep
            else: rw += wolf

print(rs, rw)