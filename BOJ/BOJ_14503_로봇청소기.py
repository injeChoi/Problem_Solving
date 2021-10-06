N, M = map(int, input().split())
y, x, d = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
clean = 0

def solution(y, x, d):
    global clean
    # 청소 가능 구역이면 청소 
    if graph[y][x] == 0:
        graph[y][x] = 2
        clean += 1
    # 순서대로 4방향 체크 
    for _ in range(4):
        nd = (d-1) % 4
        ny, nx = y + dy[nd], x + dx[nd]
        if graph[ny][nx] == 0:
            solution(ny, nx, nd)
            return
        d = nd
    # 4방향 모두 이동할 수 없으면 후진 
    nd = (d+2) % 4
    ny, nx = y + dy[nd], x + dx[nd]
    if graph[ny][nx] == 1:
        return
    solution(ny, nx, d) # 후진하지만 방향은 유지 
    
solution(y, x, d)
print(clean)
