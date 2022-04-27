"""
https://www.acmicpc.net/problem/14499

주사위를 굴리는 로직만 떠올리면 쉬운 문제
어떤 우아한 로직이 있는지는 고민해봐도 모르겠어서 일일이 대입하는 방식으로 풀었다
"""

def solution():
    N, M, y, x, K = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    commands = map(int, input().split())
    dice = [0, 0, 0, 0, 0, 0]
    move = [(0, 0), (0, 1), (0, -1), (-1, 0), (1, 0)]

    def roll(direction):
        if direction == 1:
            dice[0], dice[1], dice[3], dice[5] = dice[1], dice[5], dice[0], dice[3]
        elif direction == 2:
            dice[0], dice[1], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[1]
        elif direction == 3:
            dice[0], dice[2], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[2]
        else:
            dice[0], dice[2], dice[4], dice[5] = dice[2], dice[5], dice[0], dice[4]

    def check(y, x):
        if graph[y][x] == 0:
            graph[y][x] = dice[5]
        else:
            dice[5], graph[y][x] = graph[y][x], 0

    for command in commands:
        ny, nx = y + move[command][0], x + move[command][1]
        if 0 <= ny < N and 0 <= nx < M:
            y, x = ny, nx
            roll(command)
            check(y, x)
            print(dice[0])

solution()