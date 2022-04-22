"""
https://www.acmicpc.net/problem/20057

1. 달팽이처럼 빙글빙글 돌아가는 것 구현
2. 토네이도가 움직인 위치에서 모래가 퍼져나간는 것 구현

1)
1번 구현할 때 토네이도는 항상 왼쪽으로만 커브를 돌고,
커브를 2번 진행했을 시 토네이도의 거리가 1 늘어난다는 것을 알 수 있다
즉, 커브를 1번만 돌았을 때는 거리가 늘어나지 않고 방향만 바뀐다
이를 고려하고 토네이도가 (0, 0) 위치에 도달했을 때 종료해주면 된다

2)
토네이도의 진행 방향에 따라 모래가 퍼져나가는 위치가 다르다
이에 따라 방향에 맞게 모래가 퍼지는 위치를 따로 미리 만들어둔다
모래가 퍼질 때, 격자 밖으로 떨어진 모래의 양을 세야하므로
모래가 퍼져나간 위치가 0 <= sand < N 일 때만 개수를 증가시켰다

a 위치에는 비율에 따라 퍼져나가고 남은 모래들이 모여있는 곳이므로
원래 모래의 양 - 퍼져나간 모래의 양을 a 위치에 더해주었다
이때도 a가 만약 격자 범위 밖이라면 떨어진 모래의 양으로 생각해야 한다
"""

def solution():
    N = int(input())
    graph = [list(map(int, input().split())) for _ in range(N)]
    left = [[-2, 0, 2], [-1, -1, 10], [-1, 0, 7], [-1, 1, 1], [0, -2, 5],
            [1, -1, 10], [1, 0, 7], [1, 1, 1], [2, 0, 2], [0, -1, 0]]
    right = [[y, -x, ratio] for y, x, ratio in left]
    down = [[-x, y, ratio] for y, x, ratio in left]
    up = [[-y, x, ratio] for y, x, ratio in down]
    y, x = N // 2, N // 2
    dy = [0, 1, 0, -1]
    dx = [-1, 0, 1, 0]
    d, answer = 0, 0

    def spread(direction):
        if direction == 0:
            tmp = left
        elif direction == 1:
            tmp = down
        elif direction == 2:
            tmp = right
        else:
            tmp = up

        out, total = 0, 0
        for ny, nx, ratio in tmp:
            sand = int(graph[y][x] * (ratio * 0.01))
            total += sand
            if 0 <= y + ny < N and 0 <= x + nx < N:
                if ratio == 0:
                    graph[y + ny][x + nx] += graph[y][x] - total
                else:
                    graph[y + ny][x + nx] += sand
            else:
                if ratio == 0:
                    out += graph[y][x] - total
                else:
                    out += sand

        return out

    def spin():
        nonlocal d, y, x, answer
        curve_cnt, length = 0, 1
        while True:
            for _ in range(length):
                y, x = y + dy[d], x + dx[d]
                answer += spread(d)
                if y == 0 and x == 0:
                    return

            curve_cnt += 1

            if curve_cnt == 2:
                length += 1
                d = (d + 1) % 4
                curve_cnt = 0
            else:
                d = (d + 1) % 4

    spin()
    print(answer)

solution()
