graph = [list(map(int, input().split())) for _ in range(5)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
result = set()

def dfs(y, x, cnt, s):
    if cnt == 6:
        result.add(s)
        return
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < 5 and 0 <= nx < 5:
            dfs(ny, nx, cnt+1, s+str(graph[ny][nx]))

for i in range(5):
    for j in range(5):
        dfs(i, j, 1, str(graph[i][j]))

print(len(result))