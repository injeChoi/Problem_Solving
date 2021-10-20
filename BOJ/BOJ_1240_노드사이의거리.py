import sys
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())
visited = [0] * (N+1)
dist = [[0] * (N+1) for _ in range(N+1)]
tree = [[] for _ in range(N+1)]
for i in range(N-1):
    s, e, d = map(int, input().split())
    tree[s].append([e, d])
    tree[e].append([s, d])

def dfs(s, e, d):
    dist[s][e] = d
    for next_node, cost in tree[e]:
        if not(visited[next_node]):
            visited[next_node] = 1
            dfs(s, next_node, d + cost)
            visited[next_node] = 0

for i in range(1, N+1):
    visited[i] = 1
    dfs(i, i, 0)
    visited[i] = 0

for i in range(M):
    s, e = map(int, input().split())
    print(dist[s][e])