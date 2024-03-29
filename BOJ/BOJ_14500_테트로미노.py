N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
answer = 0
# 모든 도형 만들기 [0, 0]은 항상 포함되니 간결해보이기 위해 제거 
tetromino = [
    [[0, 1], [0, 2], [0, 3]], [[1, 0], [2, 0], [3, 0]], 
    [[0, 1], [1, 0], [1, 1]], [[1, 0], [2, 0], [2, 1]], 
    [[1, 0], [2, 0], [2, -1]], [[0, 1], [0, 2], [1, 0]], 
    [[0, 1], [0, 2], [1, 2]], [[0, 1], [1, 1], [2, 1]], 
    [[0, 1], [1, 0], [2, 0]], [[0, 1], [0, 2], [-1, 2]], 
    [[1, 0], [1, 1], [1, 2]], [[1, 0], [1, 1], [2, 1]], 
    [[1, 0], [1, -1], [2, -1]], [[0, 1], [-1, 1], [-1, 2]], 
    [[0, 1], [1, 1], [1, 2]], [[0, 1], [0, 2], [1, 1]], 
    [[1, 0], [1, 1], [2, 0]], [[1, 0], [1, -1], [2, 0]], 
    [[0, 1], [0, 2], [-1, 1]]
]

for i in range(N):
    for j in range(M):
        for k in tetromino:
            try:
                s = graph[i][j] + graph[i + k[0][0]][j + k[0][1]] + graph[i + k[1][0]][j + k[1][1]] + graph[i + k[2][0]][j + k[2][1]]
            except:
                s = 0
            answer = max(answer, s)

print(answer)