from collections import deque

N, M = map(int, input().split())
graph = [list(map(int, input())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def bfs(i, j, cnt):
    visited[i][j] = cnt
    q = deque()
    q.append((i, j, cnt))

    while q:
        y, x, idx = q[0][0], q[0][1], q[0][2]
        q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny and 0 <= nx and ny < N and nx < M and graph[ny][nx] == 1 and visited[ny][nx] == 0:
                visited[ny][nx] = idx + 1
                q.append((ny, nx, idx+1))
    
    return visited[N-1][M-1]
    
print(bfs(0, 0, 1))