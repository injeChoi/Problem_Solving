from copy import deepcopy
# 12시 방향부터 반시계 방향으로 45도씩 회전 
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]
answer = 0

tmp = [list(map(int, input().split())) for _ in range(4)]
# 리스트의 원소가 [물고기 숫자, 방향] 형식으로 되게 만들기  
graph = [[0] * 4 for _ in range(4)]
for i in range(4):
    for j in range(4):
        graph[i][j] = [tmp[i][j*2], tmp[i][j*2+1]-1] # 이동 방향 인덱스 값은 1 빼고 계산해야 함 1~8 -> 0~7 (dy, dx)

# 반복문 종료가 되지 않았는데 바뀐 물고기 위치가 뒤에 나타나서 반복문에서 2번 이상 걸릴 수도 있으니  
# 한 번 위치 계산하고 빠져주는 로직으로 구현 
def find_fish(arr, idx):
    for y in range(4):
        for x in range(4):
            if arr[y][x][0] == idx:
                return (y, x)
    return None


def fish_move(arr, shark_y, shark_x):
    pos = []
    for fish_num in range(1, 17):
        pos = find_fish(arr, fish_num)
        if pos != None:
            y, x = pos[0], pos[1]
            dst = arr[y][x][1]
            for _ in range(8):
                ny, nx = y + dy[dst], x + dx[dst]
                # 새로 이동할 위치가 벽이 아니고 상어 위치로 아니라면 위치 이동 진행 
                if 0 <= ny < 4 and 0 <= nx < 4:
                    if ny != shark_y or nx != shark_x: 
                        # 파이썬 식 신발끈 공식
                        arr[y][x][0], arr[ny][nx][0] = arr[ny][nx][0], arr[y][x][0]
                        arr[y][x][1], arr[ny][nx][1] = arr[ny][nx][1], dst
                        break # 물고기 위치 변경했으면 끝 
                # dst 값 변경
                dst = (dst+1) % 8


def shark_move(y, x, dst, arr):
    pos = []
    while 1:
        ny, nx = y + dy[dst], x + dx[dst]
        if 0 <= ny < 4 and 0 <= nx < 4:
            if 1 <= arr[ny][nx][0] <= 16:
                pos.append((ny, nx))
            y, x = ny, nx
        else:
            break
    return pos


def dfs(y, x, total, arr):
    global answer
    # 원본 값은 건드리지 않는 새로운 복사본 생성 
    next_arr = deepcopy(arr)
    # 상어가 먹을 값
    next_eat = next_arr[y][x][0]
    # 먹었으니 그 자리에 상어 배치 
    next_arr[y][x][0] = -1
    # 상어가 물고기 먹었으니 물고기 위치 이동, 현재 상어의 위치 정보를 함께 전송 
    fish_move(next_arr, y, x)

    next_dst = next_arr[y][x][1]
    # 물고기가 움직였으니 상어가 갈 수 있는 위치 알아내기 
    next_pos = shark_move(y, x, next_dst, next_arr)

    answer = max(answer, next_eat + total)

    for p in next_pos:
        dfs(p[0], p[1], next_eat + total, next_arr)


dfs(0, 0, 0, graph)
print(answer)
