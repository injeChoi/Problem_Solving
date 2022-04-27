"""
https://www.acmicpc.net/problem/21608

입력 파싱 처리, 조건 3개를 순차적으로 따지면서
차지할 수 있는 자리를 파악 후 가장 적합한 자리를 찾아내는 게 핵심

2차원 배열의 크기가 크지 않으므로 모든 좌표를 순차 탐색하면서
주위에 빈 공간, 친구의 개수를 카운팅

기존 친구의 수 보다 더 많은 친구가 있는 자리를 발견하면
자리 후보 초기화 후 더 많은 친구가 있는 자리 추가
동률이면 주위에 빈 공간 개수와 좌표를 후보로 추가

빈 공간 개수 (내림차순), y 좌표 (오름차순), x 좌표 순으로 정렬하면
0번 인덱스의 y, x 좌표가 가장 적합한 자리가 된다
"""

def solution():
    N = int(input())
    n = pow(N, 2)
    graph = [[0] * N for _ in range(N)]
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    info = []
    answer = 0

    for i in range(n):
        data = list(map(int, input().split()))
        info.append([data[0], data[1:]])

    def search(person):
        MAX = 0
        positions = []

        for y in range(N):
            for x in range(N):
                friends, blank = 0, 0

                if graph[y][x]:
                    continue

                for idx in range(4):
                    ny, nx = y + dy[idx], x + dx[idx]
                    if 0 <= ny < N and 0 <= nx < N:
                        if graph[ny][nx] in info[person][1]:
                            friends += 1
                        elif graph[ny][nx] == 0:
                            blank += 1

                if MAX < friends:
                    MAX = friends
                    positions = [[blank, y, x]]
                elif MAX == friends:
                    positions += [[blank, y, x]]

        positions.sort(key=lambda x: (-x[0], x[1]))
        return positions[0][1], positions[0][2]

    def calculate(person, y, x):
        cnt = 0
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] in info[person][1]:
                cnt += 1
        return 0 if cnt == 0 else pow(10, cnt-1)

    for idx, (person, lst) in enumerate(info):
        y, x = search(idx)
        graph[y][x] = person

    for i in range(N):
        for j in range(N):
            for k in range(n):
                if info[k][0] == graph[i][j]:
                    answer += calculate(k, i, j)
                    break

    print(answer)

solution()
