"""
https://www.acmicpc.net/problem/21610

시간복잡도에서 빡빡했던 문제
N이 최대 50 밖에 안 돼서 편하게 풀었더니 시간초과가 났다
이유는 구름의 위치를 2차원 배열이 아닌 nested list로 만들어서 관리했기 때문이다
이 경우, 최악의 경우 기존 구름 위치를 파악하고 새로운 구름의 위치를 찾아내는 단계에서 (2500 * 2500 * 2) * M번의 연산과
기타 다른 연산 횟수 @ 를 따지면 1초에 2000만번 연산을 하는 파이썬의 경우 터질 수도 있다

그래서 기존 구름 위치를 2차원 배열에 찍어놨고
기존 구름 위치를 찾는것을 O(1)의 시간 복잡도로 낮췄다
"""

dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [-1, -1, 0, 1, 1, 1, 0, -1]

def solution():
    N, M = map(int, input().split())
    ground = [list(map(int, input().split())) for _ in range(N)]
    cloud_pos = [[N-1, 0], [N-1, 1], [N-2, 0], [N-2, 1]]
    answer = 0

    def check_diag(y, x):
        cnt = 0
        for i in range(1, 8, 2):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < N and ground[ny][nx]:
                cnt += 1

        return cnt


    def rain(d, s):
        nonlocal cloud_pos
        moved_cloud = []
        new_cloud = []
        visited = [[0] * N for _ in range(N)]

        for y, x in cloud_pos:
            ny, nx = (y + dy[d] * s) % N, (x + dx[d] * s) % N
            moved_cloud += [[ny, nx]]
            visited[ny][nx] = 1

        for y, x in moved_cloud:
            ground[y][x] += 1

        for y, x in moved_cloud:
            ground[y][x] += check_diag(y, x)

        for i in range(N):
            for j in range(N):
                if ground[i][j] > 1 and not visited[i][j]:
                    new_cloud += [[i, j]]
                    ground[i][j] -= 2

        cloud_pos = new_cloud


    def calculate():
        nonlocal answer
        for i in range(N):
            for j in range(N):
                answer += ground[i][j]


    for _ in range(M):
        d, s = map(int, input().split())
        rain(d-1, s)

    calculate()
    print(answer)

solution()