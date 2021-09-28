# mod 연산이 중요
# -n % m = -(n % m) + m, ex) -1 % 4 = -(1 % 4) + 4
way = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
N, M, K = map(int, input().split())
# 0: y, 1: x, 2: 질량, 3: 속력, 4: 방향 
fireball = [list(map(int, input().split())) for _ in range(M)]
fb = [[0] * 5 for _ in range(M)]
for i, row in enumerate(fireball):
    fb[i][0], fb[i][1], fb[i][2:] = row[0]-1, row[1]-1, row[2:]
fireball = fb
total = 0

def move():
    graph = [[0] * N for _ in range(N)]
    global fireball
    dup = dict()
    new_fireball = []

    # 파이어볼 하나씩 이동 
    for item in fireball:
        y, x, m, s, d = item[0], item[1], item[2], item[3], item[4]
        if type(d) == list:
            d = d[0]
        ny, nx = (s * way[d][0] + y) % N, (s * way[d][1] + x) % N

        if graph[ny][nx] == 0:
            graph[ny][nx] = [m, s, [d]]
            dup[(ny, nx)] = 1
        else:
            graph[ny][nx][0] = graph[ny][nx][0] + m
            graph[ny][nx][1] = graph[ny][nx][1] + s
            graph[ny][nx][2] = graph[ny][nx][2] + [d]
            dup[(ny, nx)] += 1
    # 합쳐지는 칸에서 작업 처리 
    for y, x in dup:
        if dup[(y, x)] > 1:
            mass = graph[y][x][0] // 5
            if mass == 0:
                graph[y][x] = 0
                continue
            
            speed = graph[y][x][1] // (dup[(y, x)])
            flag = False
            even = odd = 0

            for idx in graph[y][x][2]:
                if idx % 2 == 0: even += 1
                else: odd += 1
            
            if len(graph[y][x][2]) == even or len(graph[y][x][2]) == odd:
                flag = True
            
            graph[y][x] = []

            if flag == True:
                for i in range(0, 7, 2):
                    graph[y][x].append([y, x, mass, speed, i])
            else:
                for i in range(1, 8, 2):
                    graph[y][x].append([y, x, mass, speed, i])
            
            for lst in graph[y][x]:
                new_fireball.append(lst)

    # 새로운 파이어볼 위치 저장 
    fireball = new_fireball
    for val in dup:
        if dup[val] == 1:
            fireball.append([val[0]] + [val[1]] + graph[val[0]][val[1]])
    
while K:
    move()
    K -= 1

for lst in fireball:
    total += lst[2]

print(total)