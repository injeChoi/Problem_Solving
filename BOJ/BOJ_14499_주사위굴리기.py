N, M, y, x, K = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
move = list(map(int, input().split()))
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
dice = [0] * 6

for m in move:
    m -= 1
    ny, nx = y + dy[m], x + dx[m]

    if not(0 <= ny < N and 0 <= nx < M):
        continue
    # 주사위 굴리기 -> 원래 주사위 면에 새로 오는 면 대입 
    if m == 0: # 동쪽으로
        dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
    elif m == 1: # 서쪽으로
        dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
    elif m == 2: # 북쪽으로
        dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]
    elif m == 3: # 남쪽으로
        dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]

    print(dice[0])
    
    if graph[ny][nx] == 0:
        graph[ny][nx] = dice[5]
    else:
        dice[5] = graph[ny][nx]
        graph[ny][nx] = 0
    
    y, x = ny, nx
    