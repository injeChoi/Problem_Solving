left = [(-2, 0, 2), (-1, -1, 10), (-1, 0, 7), (-1, 1, 1), (0, -2, 5), (1, -1, 10), (1, 0, 7), (1, 1, 1), (2, 0, 2), (0, -1, 'a')]
down = [(-1, -1, 1), (-1, 1, 1), (0, -2, 2), (0, -1, 7), (0, 1, 7), (0, 2, 2), (1, -1, 10), (1, 1, 10), (2, 0, 5), (1, 0, 'a')]
right = [(-2, 0, 2), (-1, -1, 1), (-1, 0, 7), (-1, 1, 10), (0, 2, 5), (1, -1, 1), (1, 0, 7), (1, 1, 10), (2, 0, 2), (0, 1, 'a')]
up = [(-2, 0, 5), (-1, -1, 10), (-1, 1, 10), (0, -2, 2), (0, -1, 7), (0, 1, 7), (0, 2, 2), (1, -1, 1), (1, 1, 1), (-1, 0, 'a')]

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
sy = sx = N // 2 # 시작 좌표
out = 0

# cnt: 특정 방향으로 몇칸 이동, dy, dx : 특정 방향 선택, way: 특정 방향으로 갈 때 모래 영향 받는 곳들 
def spread(cnt, dy, dx, way):
    global sy, sx, out

    for _ in range(cnt):
        # 시작 인덱스(현재 작업 위치)를 달팽이 룰에 따라 다음 칸으로 이동 
        sy, sx = sy + dy, sx + dx
        # (0, 0) 도달 후 다음이면 스탑 
        if sx < 0 or sy < 0:
            break
        
        total = 0
        for y, x, z in way:
            # 토네이도 영향을 받는 위치 
            ny, nx = sy + y, sx + x

            if z == 'a':    # a 위치를 마지막에 배치해 놨으므로 원래 값 - 총 휘날린 값이 됨 
                new_sand = graph[sy][sx] - total
            else:
                # 그 위치에 새로 쌓일 모래 양 
                new_sand = int(graph[sy][sx] * (z * 0.01))
                # 총 휘날린 모래 양 증가 
                total += new_sand

            # 그래프 범위 안이면 원래 쌓여있던 모래 위에 휘날린 모래가 쌓인다 
            if 0 <= ny < N and 0 <= nx < N: 
                graph[ny][nx] += new_sand
            else:
                out += new_sand

# 달팽이 처럼 빙글빙글 돌아가는 방법 
for i in range(1, N + 1):
    # (좌, 하), (우, 상) 쌍으로 이동 거리가 같음 
    # i: 이동 거리 
    if i % 2:
        spread(i, 0, -1, left)
        spread(i, 1, 0, down)
    else:
        spread(i, 0, 1, right)
        spread(i, -1, 0, up)

print(out)