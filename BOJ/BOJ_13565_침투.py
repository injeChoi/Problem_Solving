import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
board = [input() for _ in range(N)]
visited = [[0] * M for _ in range(N)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def dfs(y, x):
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < N and 0 <= nx < M and board[ny][nx] == '0' and not(visited[ny][nx]):
            visited[ny][nx] = 1
            dfs(ny, nx)

for i in range(M):
    if board[0][i] == '0' and not(visited[0][i]):
        dfs(0, i)

print("YES") if 1 in visited[N-1] else print("NO")