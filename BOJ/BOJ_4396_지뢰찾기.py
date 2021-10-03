N = int(input())
mine = [list(input()) for _ in range(N)]
graph = [list(input()) for _ in range(N)]
way = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
boom = False
mines = []

def count_mine(y, x):
    cnt = 0
    for i in range(8):
        ny, nx = y + way[i][0], x + way[i][1]
        if 0 <= ny < N and 0 <= nx < N and mine[ny][nx] == '*':
            cnt += 1
    return cnt

for i in range(N):
    for j in range(N):
        if mine[i][j] == '*': 
            mines.append((i, j))
        if graph[i][j] == 'x' and mine[i][j] == '*':
            boom = True
        elif graph[i][j] == 'x':
            graph[i][j] = str(count_mine(i, j))

if boom:
    for y, x in mines:
        graph[y][x] = '*'

for row in graph:
    print(''.join(row))