"""
https://www.acmicpc.net/problem/16926

회전해야 하는 테두리 단위별로 큐에 담고 회전하는 수 만큼 rotate 처리
"""

from collections import deque

def solution():
    N, M, R = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    pos, n, m = 0, N, M

    def rotate(p, n, m):
        dq = deque()

        for i in range(p, p + m):
            dq.append(graph[p][i])

        for i in range(p + 1, p + n):
            dq.append(graph[i][p+m-1])

        for i in range(p + m - 2, p, -1):
            dq.append(graph[p+n-1][i])

        for i in range(p + n - 1, p, -1):
            dq.append(graph[i][p])

        dq.rotate(-R)

        for i in range(p, p + m):
            graph[p][i] = dq.popleft()

        for i in range(p + 1, p + n):
            graph[i][p+m-1] = dq.popleft()

        for i in range(p + m - 2, p, -1):
            graph[p+n-1][i] = dq.popleft()

        for i in range(p + n - 1, p, -1):
            graph[i][p] = dq.popleft()

    while True:
        if n == 0 or m == 0:
            break
        rotate(pos, n, m)
        pos += 1
        n, m = n - 2, m - 2

    for i in range(N):
        for j in range(M):
            print(graph[i][j], end=' ')
        print()

solution()