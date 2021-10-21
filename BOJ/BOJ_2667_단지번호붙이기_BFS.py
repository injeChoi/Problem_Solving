from collections import deque

N = int(input())
graph = [list(map(int, input())) for _ in range(N)]
visited = [[0] * N for _ in range(N)]
result = []
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
cnt = 0

def bfs(i, j):
    global cnt
    result[cnt] += 1
    visited[i][j] = 1
    q = deque()
    q.append([i, j])

    while q:
        y, x = q.pop()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] and not(visited[ny][nx]):
                result[cnt] += 1
                visited[ny][nx] = 1
                q.append([ny, nx])

for i in range(N):
    for j in range(N):
        if graph[i][j] and not(visited[i][j]):
            result.append(0)
            bfs(i, j)
            cnt += 1

result.sort()
print(len(result))
for item in result:
    print(item)