"""
https://www.acmicpc.net/problem/21609

중력 작용 함수와 무지개 색깔 블록은 다른 그룹에 포함될 수도 있다는 점에서 헷갈렸다
주어진 명세에 따라 그룹을 만들고,
그룹의 정보들 (그룹의 크기, 무지개 개수, 기준 블록 좌표, 블록들의 좌표들)을 구하여 저장한다

그룹의 크기, 무지개 개수, 기준 블록 좌표 순에 따라 내림차순으로 정렬하면
터트릴 그룹이 어떤건지 알 수 있고, 그 개수의 제곱 만큼 답으로 추가한다

중력 작용은 graph의 바닥부터 시작해서 검사하는데
만약 특정 칸에 블록이 있고 그 블록 아래가 빈 칸이라면 둘의 위치를 바꿔주면 된다
블록과 빈 칸의 위치를 바꾸게 돼서 한 칸 아래로 이동한 블록의 아래를 다시 확인해서
또 빈 칸이면 또 내려간다 (while문으로 반복)
N의 범위를 벗어나서 검사하지 않게 제한사항도 만들어 둔다

무지개 블록은 그룹을 형성할 때, A 그룹, B 그룹 모두에 들어갈 수 있으므로
그룹들을 찾을 때, 무지개 블록의 위치를 따로 저장해뒀다가
새로운 그룹을 찾기 전에 무지개 블록들의 위치는 방문 안 함으로 만들어 준 후에
새로운 그룹을 찾아야한다
"""

def solution():
    N, M = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    answer = 0

    def find_group(y, x, color):
        nonlocal cnt, rainbow, group, py, px, rainbow_pos
        visited[y][x] = 1
        cnt += 1
        if graph[y][x] == color:
            py, px = min(py, y), min(px, x)
        elif graph[y][x] == 0:
            rainbow += 1
            rainbow_pos.append([y, x])
        group.append([y, x])

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                if graph[ny][nx] in [color, 0]:
                    find_group(ny, nx, color)

    def rotate():
        nonlocal graph
        tmp = [[0] * N for _ in range(N)]

        for i in range(N):
            for j in range(N):
                tmp[i][j] = graph[j][N-1-i]

        graph = tmp


    def gravity():
        for col in range(N):
            for row in range(N-1, -1, -1):
                if graph[row][col] is not None and graph[row][col] >= 0:
                    idx = row
                    while True:
                        if idx + 1 < N and graph[idx+1][col] is None:
                            graph[idx][col], graph[idx+1][col] = graph[idx+1][col], graph[idx][col]
                            idx += 1
                        else:
                            break

    while True:
        groups = []
        visited = [[0] * N for _ in range(N)]
        for i in range(N):
            for j in range(N):
                if graph[i][j] not in [-1, 0, None]:
                    cnt, rainbow = 0, 0
                    group = []
                    rainbow_pos = []
                    py, px = i, j
                    find_group(i, j, graph[i][j])
                    for y, x in rainbow_pos:
                        visited[y][x] = 0
                    if len(group) > 1:
                        groups.append([cnt, rainbow, py, px, group])

        if not groups:
            break

        groups.sort(reverse=True)
        answer += pow(groups[0][0], 2)
        for y, x in groups[0][4]:
            graph[y][x] = None
        gravity()
        rotate()
        gravity()

    print(answer)

solution()