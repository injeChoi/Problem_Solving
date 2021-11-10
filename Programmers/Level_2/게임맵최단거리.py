from collections import deque

def solution(maps):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    Y, X = len(maps), len(maps[0])
    visited = [[0] * X for _ in range(Y)]

    def bfs(i, j):
        q = deque()
        cnt = 1
        q.append([i, j, cnt])

        while q:
            y, x, cnt = q.popleft()
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if 0 <= ny < Y and 0 <= nx < X and maps[ny][nx] == 1 and not(visited[ny][nx]):
                    visited[ny][nx] = cnt+1
                    q.append([ny, nx, cnt+1])


    bfs(0, 0)
    if visited[Y-1][X-1] == 0:
        return -1
    else:
        return visited[Y-1][X-1]

solution([1,1])