from collections import deque

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
block = [['#'] * N for _ in range(N)]
visited = [[False] * N for _ in range(N)]
block_info = []
block_idx = 1
score = 0
play = True

def find_group(i, j):
    global block_idx, block
    cnt = 1
    flag = False
    q = deque()
    q.append((i, j))
    visited[i][j] = True
    y = x = my = mx = rainbow = 0

    while q:
        y, x = q.popleft()
        for r in range(4):
            ny, nx = y + dy[r], x + dx[r]
            if 0 <= ny < N and 0 <= nx < N and not(visited[ny][nx]):
                if (graph[ny][nx] == graph[i][j]) or graph[ny][nx] == 0:
                    if graph[ny][nx] == 0:
                        rainbow += 1
                    my, mx = max(my, ny), max(mx, nx)
                    flag = True
                    visited[ny][nx] = True
                    q.append((ny, nx))
                    block[ny][nx] = block_idx
                    cnt += 1
    
    if flag == True:
        block_info.append([cnt, rainbow, my, mx, i, j, block_idx])
        block[i][j] = block_idx

    if (y, x) != (i, j):
            block_idx += 1 


def remove_block():
    global block_info, score, graph
    block_info.sort(reverse=True)
    score += block_info[0][0]**2

    for i in range(N):
        for j in range(N):
            if block[i][j] == block_info[0][6]:
                graph[i][j] = -2 # 빈칸으로 만들기 


def gravity():
     for i in range(N-1, -1, -1):  # 밑에서 부터 체크
        for j in range(N):
            if graph[i][j] >= 0:  # -1이 아니면 아래로 다운
                r = i
                while True:
                    if 0 <= r+1 <N and graph[r+1][j] == -2:  # 다음행이 인덱스 범위 안이면서 '#'이면 아래로 다운
                        graph[r+1][j] = graph[r][j]
                        graph[r][j] = -2
                        r += 1
                    else:
                        break

def rotate():
    global graph
    ret = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            ret[N-1-j][i] = graph[i][j]
    graph = ret

while True:
    block = [['#'] * N for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    block_info = []
    block_idx = 1

    for i in range(N):
        for j in range(N):
            if not(visited[i][j]) and graph[i][j] > 0: 
                find_group(i, j)

    if not block_info:
        break

    remove_block()
    gravity()
    rotate()
    gravity()

print(score)