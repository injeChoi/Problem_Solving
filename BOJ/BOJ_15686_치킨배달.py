"""
https://www.acmicpc.net/problem/15686

모든 치킨 집에서 모든 집으로 부터 치킨 거리의 누적 합을 구한 후
누적 합이 가장 작은 M개의 치킨 집을 골라 도시 치킨 거리를 구하려 했으나
TC는 다 통과하지만 틀린 풀이
이 로직은 각각의 집에서 부터 치킨 집 까지의 최단 거리를 보장하지 못한다

DFS로 M개의 치킨집만 남겨두고 그 상황에서 도시 치킨 거리를 구한 후
최솟값을 구하면 되는 문제

종료조건을 만들어내는 게 까다로웠다
치킨 집을 하나씩 추가하다가 추가된 치킨집의 개수가 M가 같다면
추가된 치킨집들과 가정집들의 최소 치킨 거리를 구한 후 합산하여
구할 수 있는 최솟값을 찾는 문제
"""

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [0] * 13
homes = []
chickens = []
answer = 10e9


def find_location():
    for i in range(N):
        for j in range(N):
            if graph[i][j] == 1:
                homes.append([i, j])
            elif graph[i][j] == 2:
                chickens.append([i, j])


def dfs(idx, cnt):
    global answer

    if cnt == M:
        tmp = 0
        for hy, hx in homes:
            MIN = 10e9
            for i, (cy, cx) in enumerate(chickens):
                if visited[i]:
                    MIN = min(MIN, abs(hy - cy) + abs(hx - cx))
            tmp += MIN

        answer = min(answer, tmp)

    if idx == len(chickens):
        return

    visited[idx] = 1
    dfs(idx + 1, cnt + 1)
    visited[idx] = 0
    dfs(idx + 1, cnt)


find_location()
dfs(0, 0)
print(answer)
