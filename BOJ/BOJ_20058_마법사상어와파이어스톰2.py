"""
https://www.acmicpc.net/problem/20058

명세 이해가 중요한 문제

문제: 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다
=> 상,하,좌,우에 얼음이 남아있는 칸이 3개 미만이면 1 감소

1. 격자를 2^N 사이즈로 나눈다
2. 나눈 격자를 시계 방향으로 90도 회전시킨다
3. 얼음을 감소시킨다
4. 1 ~ 3 반복
5. 최종적으로 남아있는 얼음의 양과 가장 큰 덩어리 크기를 구한다

2차원 배열을 나누는 것이 항상 가장 헷갈리는 부분
List Comprehension을 활용해서 2차원 배열에서 필요한 부분만
한 행 씩 따로 뽑고 난 후, 뽑아온 행에서 또 필요한 부분만 슬라이싱 한다
ex) [row[j:j+r] for row in graph[i:i+r]]
그리고 뽑아온 부분만 회전 로직을 적용해서 임시 배열에 저장 후
임시 배열을 원본에다가 다시 붙여넣는다

그 후엔 비교적 단순한 인접 칸 탐색과 처리 로직을 적용하고
마지막에 가장 큰 덩어리 구할 때 bfs나 dfs로 덩어리 별로 크기를 구한 후
내림차순으로 정렬해서 0번째 인덱스 값을 리턴하면 된다
"""

from collections import deque

def solution():
    N, Q = map(int, input().split())
    n = pow(2, N)
    graph = [list(map(int, input().split())) for _ in range(n)]
    L = map(int, input().split())
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    def rotate(lst, i, j, r):
        tmp = [[0] * r for _ in range(r)]
        for y in range(r):
            for x in range(r):
                tmp[y][x] = lst[r-1-x][y]

        for t in tmp:
            graph[i][j:j+r] = t
            i += 1

    def check_melt(y, x, melt):
        count = 0
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < n and 0 <= nx < n:
                if graph[ny][nx] > 0:
                    count += 1

        if count < 3:
            melt += [[y, x]]

    def execute_melt(melt):
        for y, x in melt:
            graph[y][x] -= 1

    def bfs(i, j, visited):
        dq = deque([[i, j]])
        visited[i][j] = 1
        cnt = 1 if graph[i][j] > 0 else 0

        while dq:
            y, x = dq.popleft()
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx] and graph[ny][nx] > 0:
                    visited[ny][nx] = 1
                    dq.append([ny, nx])
                    cnt += 1

        return cnt

    def find_result():
        total = 0
        count = []
        visited = [[0] * n for _ in range(n)]

        for i in range(n):
            for j in range(n):
                total += graph[i][j]
                if not visited[i][j]:
                    count += [bfs(i, j, visited)]

        return total, sorted(count, reverse=True)[0]

    for l in L:
        r = pow(2, l)
        melt = []

        for i in range(0, n, r):
            for j in range(0, n, r):
                rotate([row[j:j+r] for row in graph[i:i+r]], i, j, r)

        for i in range(n):
            for j in range(n):
                if graph[i][j] > 0:
                    check_melt(i, j, melt)

        execute_melt(melt)

    answer = find_result()
    print(answer[0], answer[1], sep='\n')

solution()