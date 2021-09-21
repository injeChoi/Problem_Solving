from collections import deque
row, col = map(int, input().split(" "))
graph = [list(map(int, input())) for _ in range(row)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
cnt = 0

# BFS
def bfs(i, j):
    graph[i][j] = 1
    q = deque()
    q.append((i, j))

    while q:
        y, x = q[0][0], q[0][1]
        q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny and 0 <= nx and ny < row and nx < col and graph[ny][nx] == 0:
                graph[ny][nx] = 1
                q.append((ny, nx))

for i in range(row):
    for j in range(col):
        if graph[i][j] == 0:
            bfs(i, j)
            cnt += 1

print(cnt)

# DFS
def dfs(i, j):
    # 탈출 조건
    if i < 0 or j < 0 or row <= i or col <= j:
        return False
    
    if graph[i][j] == 0:
        # 방문 처리 
        graph[i][j] = 1
        # 연결된 요소중 빈칸이 있으면 다 방문처리 
        dfs(i-1, j)
        dfs(i+1, j)
        dfs(i, j-1)
        dfs(i, j+1)
        # 방문 처리 잘 됐으면 True 반환 
        return True
    return False

for i in range(row):
    for j in range(col):
        if dfs(i, j) == True:
            cnt += 1

print(cnt)