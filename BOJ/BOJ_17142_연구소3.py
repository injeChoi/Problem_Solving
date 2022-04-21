"""
https://www.acmicpc.net/problem/17142

1. 바이러스들의 위치를 저장해서 활성화 시킬 수 있는 개수 만큼의 조합을 구하기 (DFS)
2. 조합별로 BFS를 통해 바이러스를 퍼뜨려 나가기, 퍼뜨려 나갈 때 걸린 시간을 visited 배열에 저장시켜두기
3. 바이러스를 퍼뜨려 나간 후 가장 오래걸린 값 찾기
4. 가장 오래걸린 값의 위치가 비활성화된 바이러스 값이면 값 -1
5. 어떤 경우에도 바이러스가 다 퍼질 수 없는 케이스를 찾기 위해 조합별로 바이러스 다 퍼뜨린 후
   빈 공간이 있는지 체크, 체크한 값이 조합의 개수와 같으면 모든 케이스에서 전염을 실패한 것이니 -1 리턴
6. 처음부터 모든칸에 바이러스가 있거나 벽으로만 이뤄져있는 케이스라면 전염시킬 부분이 없으니 0 리턴
"""

from collections import deque

def solution():
    N, M = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(N)]
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    virus = []
    comb = []
    answer, cnt = int(10e9), 0
    flag = 1

    for g in graph:
        if 0 in g:
            flag = 0

    if flag:
        print(0)
        return

    def find_virus():
        nonlocal virus
        for i in range(N):
            for j in range(N):
                if graph[i][j] == 2:
                    virus += [[i, j]]

    def make_combination(idx, lst):
        if len(lst) == M:
            comb.append(lst[:])
            return

        for i in range(idx, len(virus)):
            make_combination(i + 1, lst + [virus[i]])

    def check_graph(visited):
        tmp = 0
        for i in range(N):
            for j in range(N):
                if visited[i][j] == 0 and graph[i][j] == 0:
                    return False
                if visited[i][j] != 0 and graph[i][j] == 2:
                    continue
                tmp = max(tmp, visited[i][j])
        return tmp

    def bfs(elements):
        nonlocal answer, cnt
        MAX = 0
        visited = [[0] * N for _ in range(N)]
        dq = deque()

        for element in elements:
            y, x = element
            dq.append([y, x, 1])
            visited[y][x] = 1

        while dq:
            y, x, s = dq.popleft()
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if 0 <= ny < N and 0 <= nx < N and graph[ny][nx] != 1 and visited[ny][nx] == 0:
                    visited[ny][nx] = s + 1
                    dq.append([ny, nx, s + 1])

        tmp = check_graph(visited)
        if tmp != 0:
            answer = min(answer, tmp)

        for i in range(N):
            for j in range(N):
                if visited[i][j] == 0 and graph[i][j] == 0:
                    cnt += 1
                    return

    find_virus()
    make_combination(0, [])

    for c in comb:
        bfs(c)

    if cnt == len(comb):
        print(-1)
    else:
        print(answer - 1)

solution()
