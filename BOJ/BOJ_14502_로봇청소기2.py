"""
https://www.acmicpc.net/problem/14503

BFS + 구현
기존에는 DFS로 풀었지만 BFS로도 풀 수 있는 문제처럼 보여 다시 풀었다
문제 명세대로 현재 진행 방향에서 왼쪽을 찾는 로직을 찾는 방법이 중요했고
4방향 모두 방문했거나 벽일 시 현재 진행 방향을 유지한 채로 후진을 한다는 개념이 주요했다
후진을 할 때 현재 진행 방향의 반대 방향을 찾는 로직을 찾는 방법 또한 주요했다

왼쪽 찾는 방법: (현재 진행 방향 - 1) % 4
후진 방향 찾는 방법: (현재 진행 방향 + 2) % 4
"""

from collections import deque

N, M = map(int, input().split())
r, c, d = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs():
    dq = deque()
    dq.append([r, c, d])
    visited[r][c] = 1
    answer = 1

    while dq:
        cnt = 0
        y, x, dr = dq.popleft()
        for i in range(4):
            nd = (dr - 1) % 4
            ny, nx = y + dy[nd], x + dx[nd]
            if graph[ny][nx] == 0 and visited[ny][nx] == 0:
                answer += 1
                visited[ny][nx] = 1
                dq.append([ny, nx, nd])
                break
            else:
                cnt += 1
                dr = (dr - 1) % 4

        if cnt == 4:
            nd = (dr + 2) % 4
            ny, nx = y + dy[nd], x + dx[nd]
            if graph[ny][nx] == 1:
                return answer
            else:
                dq.append([ny, nx, dr])


print(bfs())
