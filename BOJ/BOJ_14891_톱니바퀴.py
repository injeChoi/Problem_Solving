gears = [input() for _ in range(4)]
K = int(input())
cycle = [list(map(int, input().split())) for _ in range(K)]
answer = 0

def solution(idx, way):
    move = [-2, -2, -2, -2]
    move[idx] = 1
    #기준점 우측
    for i in range(idx, 4):
        if i == 3: break
        if gears[i][2] != gears[i+1][6]:
            if move[i] == -2:
                move[i] = 1
            if move[i+1] == -2:
                move[i+1] = 1
        else:
            if i+1 == idx: move[i] = 0
            else: move[i+1] = 0
    # 기준점 좌측
    for i in range(idx, -1, -1):
        if i == 0: break
        if gears[i][6] != gears[i-1][2]:
            if move[i] == -2:
                move[i] = 1
            if move[i-1] == -2:
                move[i-1] = 1
        else:
            if i-1 == idx: move[i] = 0
            else: move[i-1] = 0

    for i in range(len(move)):
        if move[i] == 0 and i < idx:
            move[:i] = [0] * i
        if move[i] == 0 and i > idx:
            move[i:] = [0] * (len(gears) - i)
    # 어느방향으로 움직여야하는지 확인
    if idx % 2 == 0:
        for i in range(len(move)):
            if i % 2 == 0 and move[i] == 1:
                move[i] = way
            elif i % 2 == 1 and move[i] == 1:
                move[i] = -way
    else:
        for i in range(len(move)):
            if i % 2 == 0 and move[i] == 1:
                move[i] = -way
            elif i % 2 == 1 and move[i] == 1:
                move[i] = way

    # 실제 회전
    for i in range(len(gears)):
        g, s, e = gears[i], gears[i][0], gears[i][7]
        if move[i] == 1:
            gears[i] = e + g[0:7]
        elif move[i] == -1:
            gears[i] = g[1:] + s

for idx, way in cycle:
    solution(idx-1, way)


for i, gear in enumerate(gears):
    if gear[0] == '1':
        answer += 2**i

print(answer)