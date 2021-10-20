import sys
sys.setrecursionlimit(10**6)

T = int(input())
H = W = cnt = 0
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def dfs(y, x, graph, visited):
    visited[y][x] = 1
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < H and 0 <= nx < W and graph[ny][nx] == '#' and not(visited[ny][nx]):
            dfs(ny, nx, graph, visited)

for t in range(T):
    H, W = map(int, input().split())
    graph = [input() for _ in range(H)]
    visited = [[0] * W for _ in range(H)]
    cnt = 0

    for i in range(H):
        for j in range(W):
            if graph[i][j] == '#' and not(visited[i][j]):
                dfs(i, j, graph, visited)
                cnt += 1

    print(cnt)