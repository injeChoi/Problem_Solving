INF = int(1e9)

N, M = map(int, input().split())
graph = [[INF] * (N+1) for _ in range(N+1)]

# 자기 자신에게 가는 길은 0으로 초기화 
for i in range(1, N+1):
    graph[i][i] = 0

# 간선 개수만큼 입력 받기 
for _ in range(M):
    start, end = map(int, input().split())
    graph[start][end] = 1
    graph[end][start] = 1

# 목적지와 거쳐갈 곳 입력받기 
X, K = map(int, input().split())

# Floyd Warshall, O(N^3)
for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

distance = graph[1][K] + graph[K][X]

if distance >= INF:
    print(-1)
else:
    print(distance)

