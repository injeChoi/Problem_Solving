"""
https://www.acmicpc.net/problem/23288

주사위 굴리기 + 주사위의 이동 방향 회전 로직을 미리 구현
dfs를 통해 특정 칸에 도달 시 얻을 수 있는 점수 미리 계산해두기
주사위가 구르는데 칸 밖으로 나가면 반대 방향으로 구르기

시계 방향 회전이랑 시계 반대 방향 회전할 때
배열의 인덱스가 오름차순이나 내림차순처럼 이쁘게 증가, 감소한다고 무작정 생각하지 말고
방향에 맞는 인덱스를 가지는지 꼼꼼히 체크해야 한다
"""

def solution():
    N, M, K = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    dice = [1, 4, 2, 3, 5, 6]
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    direction = 1
    y, x = 0, 0
    lst = []
    answer = 0

    def roll(direction):
        if direction == 0:
            dice[0], dice[2], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[2]
        elif direction == 1:
            dice[0], dice[1], dice[3], dice[5] = dice[1], dice[5], dice[0], dice[3]
        elif direction == 2:
            dice[0], dice[2], dice[4], dice[5] = dice[2], dice[5], dice[0], dice[4]
        else:
            dice[0], dice[1], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[1]

    def dfs(y, x, num):
        nonlocal lst
        lst += [(y, x)]
        visited[y][x] = num
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and not visited[ny][nx] and graph[ny][nx] == graph[y][x]:
                dfs(ny, nx, num)

    def calculate():
        for y, x in lst:
            visited[y][x] *= len(lst)

    def change_dir(y, x):
        nonlocal direction
        if dice[5] > graph[y][x]:
            direction = (direction + 1) % 4
        elif dice[5] < graph[y][x]:
            direction = (direction - 1) % 4

    for i in range(N):
        for j in range(M):
            if not visited[i][j]:
                lst = []
                dfs(i, j, graph[i][j])
                calculate()

    for _ in range(K):
        ny, nx = y + dy[direction], x + dx[direction]
        if 0 <= ny < N and 0 <= nx < M:
            roll(direction)
            change_dir(ny, nx)
        else:
            direction = (direction + 2) % 4
            roll(direction)
            ny, nx = y + dy[direction], x + dx[direction]
            change_dir(ny, nx)

        y, x = ny, nx
        answer += visited[y][x]

    print(answer)

solution()