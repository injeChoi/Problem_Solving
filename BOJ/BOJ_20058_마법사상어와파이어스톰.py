from collections import deque

N, Q = map(int, input().split())
N = 2**N 
graph = [list(map(int, input().split())) for _ in range(N)]
L = list(map(int, input().split()))
visited = [[False] * N for _ in range(N)]
melt_check = []
MAX = total = 0
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

# 최종 제일 큰거 찾기 
def bfs(i, j):
    cnt = 1
    q = deque()
    q.append((i, j))
    visited[i][j] = True

    while q:
        y, x = q.pop()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] > 0 and not(visited[ny][nx]):
                visited[ny][nx] = True
                q.append((ny, nx))
                cnt += 1
    return cnt


# 인접한 얼음 개수 3개 이상인지 확인해서 아니면 값 -1 
def melt(y, x):
    global graph
    ice = 0

    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] > 0:
            ice += 1
    
    if ice < 3:
        melt_check[y][x] = True


def rotate(i, j, sz):
    global graph
    arr = []
    # 격자 불러오기 
    for y in range(i-sz, i):
        tmp = []
        for x in range(j-sz, j):
            tmp.append(graph[y][x])
        arr.append(tmp)

    l = len(arr)
    ret = [[0] * l for _ in range(l)]
    # 격자 회전 
    for y in range(l):
        for x in range(l):
            ret[x][sz-1-y] = arr[y][x]
    
    # 원본 배열에 붙여넣기 
    r = 0
    for y in range(i-sz, i):
        c = 0
        for x in range(j-sz, j):
            graph[y][x] = ret[r][c]
            c += 1
        r += 1


def magic(l):
    global melt_check
    melt_check = [[False] * N for _ in range(N)]
    sz = 2**L[l]
    # graph 격자로 나눠서 회전 
    for i in range(sz, N+1, sz):
        for j in range(sz, N+1, sz):
            rotate(i, j, sz)

    # 얼음 녹일 위치 체크, 얼음 녹이기 
    for i in range(N):
        for j in range(N):
            if graph[i][j] > 0:
                melt(i, j)
    
    for i in range(N):
        for j in range(N):
            if melt_check[i][j] == True:
                graph[i][j] -= 1


for q in range(Q):
    magic(q)

for row in graph:
    total += sum(row)

for i in range(N):
    for j in range(N):
        if not(visited[i][j]) and graph[i][j] > 0:
            MAX = max(MAX, bfs(i, j))

print(total)
print(MAX)