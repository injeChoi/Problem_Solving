from collections import deque

N = int(input())
K = int(input())
graph = [[0] * N for _ in range(N)]
graph[0][0] = 1
for _ in range(K):
    y, x = map(int, input().split())
    graph[y-1][x-1] = 9
L = int(input())
directions = {}
for _ in range(L):
    X, C = input().split()
    directions[int(X)] = C
q = deque()
q.append((0, 0))
time = 1
move = (0, 1)

def decision(current, nxt):
    decide = 0

    if current == (0, 1):
        if nxt == 'L': decide = (-1, 0)
        else: decide = (1, 0)

    elif current == (0, -1):
        if nxt == 'L': decide = (1, 0)
        else: decide = (-1, 0)

    elif current == (-1, 0):
        if nxt == 'L': decide = (0, -1)
        else: decide = (0, 1)

    elif current == (1, 0):
        if nxt == 'L': decide = (0, 1)
        else: decide = (0, -1)

    return decide

while True:
    ny, nx = q[0][0]+move[0], q[0][1]+move[1]
    if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] != 1:
        if graph[ny][nx] != 9:
            y, x = q.pop()
            graph[y][x] = 0
        graph[ny][nx] = 1
        q.appendleft((ny, nx))
        if time in directions.keys():
            move = decision(move, directions[time])
        time += 1
    else:
        print(time)
        break
