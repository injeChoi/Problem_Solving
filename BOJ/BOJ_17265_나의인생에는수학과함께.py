N = int(input())
graph = [input().split() for _ in range(N)]
result = []
dy = [1, 0]
dx = [0, 1]

def dfs(y, x, res):
    if y == N-1 and x == N-1:
        result.append(int(res))
        return
    for i in range(2):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < N and 0 <= nx < N:
            if graph[ny][nx] in ['+', '-', '*']:
                dfs(ny, nx, res + graph[ny][nx])
            else:
                dfs(ny, nx, str(eval(res + graph[ny][nx])))

dfs(0, 0, graph[0][0])
result.sort()
print(result[-1], result[0])