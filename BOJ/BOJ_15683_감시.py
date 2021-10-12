from copy import deepcopy

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
cctv = []
cctv5 = []
area = N * M
dy = [1, 0, -1, 0]
dx = [0, -1, 0, 1]
way = []
answer = 10e8

def dfs(cnt):
    if cnt == len(cctv):
        global answer, arr
        arr = deepcopy(graph)
        num = 0

        for i, c in enumerate(cctv):
            y, x = c[0], c[1]
            if arr[y][x] == 1:
                num += move(y, x, way[i])
            elif arr[y][x] == 2:
                num += move(y, x, way[i])
                num += move(y, x, (way[i]+2) % 4)
            elif arr[y][x] == 3:
                num += move(y, x, way[i])
                num += move(y, x, (way[i]+1) % 4)
            else:
                num += move(y, x, way[i])
                num += move(y, x, (way[i]+1) % 4)
                num += move(y, x, (way[i]+2) % 4)

        answer = min(answer, area - num)
        return
    # 4방향 돌기
    for i in range(4):
        way.append(i)
        dfs(cnt+1)
        way.pop()

def move(y, x, d):
    cnt = 0
    while True:
        ny, nx = y + dy[d], x + dx[d]
        if not(0 <= ny < N) or not(0 <= nx < M) or arr[ny][nx] == 6:
            return cnt
        if 0 < arr[ny][nx] < 6 or arr[ny][nx] == -1:
            y, x = ny, nx
            continue
        y, x = ny, nx
        arr[y][x] = -1
        cnt += 1

for i in range(N):
    for j in range(M):
        if 0 < graph[i][j] < 5:
            cctv.append([i, j])
        elif graph[i][j] == 5:
            cctv5.append([i, j])

for c in cctv5:
    y, x = c[0], c[1]
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        while True:
            if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] != 6:
                if not(0 < graph[ny][nx] < 5) and graph[ny][nx] != -1:
                    graph[ny][nx] = -1
                ny, nx = ny + dy[i], nx + dx[i]
            else:
                break

for i in range(N):
    for j in range(M):
        if graph[i][j] != 0:
            area -= 1

dfs(0)
print(answer)
