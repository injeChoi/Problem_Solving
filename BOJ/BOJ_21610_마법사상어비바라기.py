way = [(0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
info = [list(map(int, input().split())) for _ in range(M)]
cloud = [[N-1, 0], [N-1, 1], [N-2, 0], [N-2, 1]]
visited = []
total = 0

def new_cloud():
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False and graph[i][j] >= 2:
                cloud.append([i, j])
                graph[i][j] -= 2

def move(m):
    # 구름이 있던 곳 초기화 
    global visited, cloud
    visited = [[False] * N for _ in range(N)]
    # m 번째 이동 명령 정보 받기 
    d, s = info[m]
    d -= 1
    # 구름들 새로운 위치로 이동 
    for i in range(len(cloud)):
        for j in range(len(cloud[i])):
            if j == 0: cloud[i][j] = (s * way[d][0] + cloud[i][j]) % N
            else: cloud[i][j] = (s * way[d][1] + cloud[i][j]) % N
    # 구름이 있는 지역에 비 뿌리기
    for y, x in cloud:
        graph[y][x] += 1
    # 구름이 있는 곳 대각선 방향에 물이 있으면 물 증가(경계 밖은 무시)
    for y, x in cloud:
        for i in range(1, 8, 2):
            ny, nx = y + way[i][0], x + way[i][1]
            if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] > 0:
                graph[y][x] += 1
    # 구름이 있는 곳 방문 처리
    for y, x in cloud:
        visited[y][x] = True
    # 비 뿌렸으니 구름 사라지기
    cloud.clear()
    # 새로운 구름 생성 
    new_cloud()

for m in range(M):
    move(m)

for row in graph:
    total += sum(row)

print(total)