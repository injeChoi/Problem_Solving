N = int(input())
move = input().split(" ")
# 상 하 좌 우 
dx = [0, 0, -1, 1]  # x 축
dy = [-1, 1, 0, 0]  # y 축 
move_type = ["U", "D", "L", "R"]
x = y = 0   # 현재 x, y 좌표 

for direction in move:
    for i in range(len(move_type)):
        if direction == move_type[i]:
            nx = x + dx[i]
            ny = y + dy[i]

    if nx < 0 or ny < 0 or nx >= N or ny >= N:
        continue

    x, y = nx, ny

print(y+1, x+1) # x축, y 축 
