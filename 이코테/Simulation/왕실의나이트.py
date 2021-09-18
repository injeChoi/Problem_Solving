pos = list(input())
y = ord(pos[0]) - ord('a')
x = pos[1]
dy = [-2, -2, 2, 2, -1, 1, -1, 1]
dx = [-1, 1, -1, 1, -2, -2, 2, 2]
cnt = 0

for i in range(8):
    ny = y + dy[i]
    nx = x = dx[i]

    if 0 <= ny and 0 <= nx and ny < 8 and nx < 8:
        cnt += 1

print(cnt)